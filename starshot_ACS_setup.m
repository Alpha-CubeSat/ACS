clc
close all
clear all
%% Simulink model IC & cmd
%diary('Diary_partial_19th_part.txt')
PLOT=1;
altitude=400;% km
R=6371+altitude;% km
Omega=0;
vc=sqrt(398600/(R))*1000;
ISS_inclination = deg2rad(51.6);


starshot.IC.x=R*1000;
starshot.IC.y=0;
starshot.IC.z=0;
starshot.IC.xdot=0;
starshot.IC.ydot= vc/sqrt(1+(tan(ISS_inclination))^2);
starshot.IC.zdot= tan(ISS_inclination)*vc/sqrt(1+(tan(ISS_inclination))^2);

t=1;
u=1;
tic
discretization_c=linspace(0.0001,0.1,50);
discretization_Id=linspace(0.0001,0.1,50);
starshot.IC.eul=pi/6*[1 2 3];%pi/18*[3 6 4.5];%-1+2*rand(1,3);%pi/6*[1 1 1];[-27.7875      39.0433     -28.1572]*pi/180;%

starshot.IC.w=[0 0 1];%[0.6 -0.5 0.7];%[0.2 0.3 0.5];%-2+4*rand(1,3);%N/10*[1 1 1];[-2.1428     +2.5648      -3.2926];%
starshot.IC.massproperties.m=1.3;
starshot.IC.massproperties.Ixx=1957614.50869e-9;
starshot.IC.massproperties.Ixy=-58366.32382e-9;
starshot.IC.massproperties.Ixz=2276.38093e-9;
starshot.IC.massproperties.Iyx=-58366.32382e-9;
starshot.IC.massproperties.Iyy=1963466.58902e-9;
starshot.IC.massproperties.Iyz=889.20475e-9;
starshot.IC.massproperties.Izx=2276.38093e-9;
starshot.IC.massproperties.Izy=889.20475e-9;
starshot.IC.massproperties.Izz=2046972.65884e-9;
starshot.IC.massproperties.I=[starshot.IC.massproperties.Ixx,starshot.IC.massproperties.Ixy,starshot.IC.massproperties.Ixz;
starshot.IC.massproperties.Iyx,starshot.IC.massproperties.Iyy,starshot.IC.massproperties.Iyz;
starshot.IC.massproperties.Izx,starshot.IC.massproperties.Izy,starshot.IC.massproperties.Izz];
%starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;
[starshot.IC.massproperties.PI starshot.IC.massproperties.Ip]=eig(starshot.IC.massproperties.I);
starshot.IC.massproperties.Ixp=starshot.IC.massproperties.Ip(1,1);
starshot.IC.massproperties.Iyp=starshot.IC.massproperties.Ip(2,2);
starshot.IC.massproperties.Izp=starshot.IC.massproperties.Ip(3,3);

% starshot.IC.massproperties.Ip=[starshot.IC.massproperties.Ixp 0 0;...
%                                0 starshot.IC.massproperties.Iyp 0;...
%                                0 0 starshot.IC.massproperties.Izp];
starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;

qmatlab=eul2quat(starshot.IC.eul);
q0=[qmatlab(2:4),qmatlab(1)]';

G=6.67e-11;
M_Earth=5.972e24;
R_Earth=6.378e6;
B0=3.12e-5;
mu_0=4*pi*(10^-7);
n=1000;

%% Controller Design
starshot.controller.i=ISS_inclination;                                                    % Orbit inclination
starshot.controller.a=altitude;                                                          % Satellite altitude
starshot.controller.T=2*pi*sqrt((6371+starshot.controller.a)^3/398600);                % Orbital period
starshot.controller.tp=1.8*starshot.controller.T;                                     %   Peak Time
starshot.controller.ts=2*starshot.controller.T;                                     %   Settling Time
starshot.controller.c=4.4*starshot.controller.tp/(pi*starshot.controller.ts);
starshot.controller.zeta=sqrt(starshot.controller.c^2/(1+starshot.controller.c^2)); %   Damping ratio
starshot.controller.omegan=4.4/(starshot.controller.ts*starshot.controller.zeta);   %   Natural frequency
starshot.controller.Ims=pi/starshot.controller.tp;
starshot.controller.Res=4.4/starshot.controller.ts;
starshot.controller.s1=-starshot.controller.Res+j*starshot.controller.Ims;
starshot.controller.ang_p=angle(1/starshot.controller.s1^2);
starshot.controller.ang_c=-pi-starshot.controller.ang_p;
if starshot.controller.ang_c<0
    starshot.controller.ang_c=2*pi+starshot.controller.ang_c;
end
starshot.controller.Td=inv(imag(starshot.controller.s1)/tan(starshot.controller.ang_c)-real(starshot.controller.s1));
starshot.controller.Kpd=abs(starshot.controller.s1^2/(starshot.controller.s1+inv(starshot.controller.Td)));


starshot.controller.Kd=starshot.controller.Kpd;
starshot.controller.Kp=starshot.controller.Kpd/starshot.controller.Td;


starshot.cmd.Kp=[starshot.IC.massproperties.Ip]*starshot.controller.Kp;
starshot.cmd.Kd=[starshot.IC.massproperties.Ip]*starshot.controller.Kd;

% Kane Damper
starshot.cmd.Id=0.0021;%0.0082551;%discretization_Id(N);%=eye(3)*0.001;
starshot.cmd.invId=inv(starshot.cmd.Id);
starshot.cmd.c=0.004;%0.41837;%discretization_c(k);%0.41837;%

starshot.cmd.w=[0 0 1]';
starshot.cmd.wdb0=[0 0 1]';%[0 1 2];%-starshot.IC.w;%norm(starshot.IC.massproperties.I*starshot.cmd.w)*starshot.cmd.invId(1,1)*[0 0 1]';
%% Drag
starshot.aerodrag.h=starshot.controller.a*1000;                                 % Altitude (Meters)
starshot.aerodrag.T=-131.21+.00299*starshot.aerodrag.h;                         % Temperature (^C)
starshot.aerodrag.P=2.488*((starshot.aerodrag.T+273.15)/216.6)^(-11.388);       % Pressure (K-Pa)
starshot.aerodrag.p=starshot.aerodrag.P/(.2869*(starshot.aerodrag.T+273.15));   % Density (kg/m^3)
starshot.aerodrag.cd=2;                                                         % Drag coeff
starshot.aerodrag.A=0.01;                                                       % Surface area
starshot.aerodrag.V=sqrt(398600/(starshot.controller.a+6371))*1000;             % Velocity for circular orbit
starshot.aerodrag.xag=0.01;                                                     % Aerodinamic pressure offset
starshot.aerodrag.Ta=0.5*starshot.aerodrag.cd*starshot.aerodrag.p*starshot.aerodrag.A*starshot.aerodrag.V^2*starshot.aerodrag.xag;
%% Hardware

starshot.magnetorq.V=4;                                     % Volt
starshot.magnetorq.e=0.250;%0.33;                            % Max current
%(Ampere)
starshot.magnetorq.k=13.5;                                    % Gain
starshot.magnetorq.A=4e-5;                  % Surface Area
starshot.magnetorq.n=500;                                  % Wire Turns (supposed)

starshot.magnetorq.m_max_x=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_y=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_z=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;

starshot.magnetorq.i_max_x=starshot.magnetorq.m_max_x/(starshot.magnetorq.A*starshot.magnetorq.n);
starshot.magnetorq.i_max_y=starshot.magnetorq.m_max_y/(starshot.magnetorq.A*starshot.magnetorq.n);
starshot.magnetorq.i_max_z=starshot.magnetorq.m_max_z/(starshot.magnetorq.A*starshot.magnetorq.n);

% %% Post Proc
% 
% starshot.model='starshot_sim';%'StarshotAC_DC_kd12';
% load_system(starshot.model)
% sim_time=3500;
% starshot.output=sim(starshot.model,'SimulationMode','accelerator','StopTime','sim_time');
% % SS error angle between omega direction and principal Iz
% %starshot.postproc.Wf=[sum(starshot.output.w.data(length(starshot.output.w.data)-9:length(starshot.output.w.data),1))/10 sum(starshot.output.w.data(length(starshot.output.w.data)-9:length(starshot.output.w.data),2))/10 sum(starshot.output.w.data(length(starshot.output.w.data)-9:length(starshot.output.w.data),3))/10];
% starshot.postproc.Wf=[starshot.output.w.data(length(starshot.output.w.data),1) starshot.output.w.data(length(starshot.output.w.data),2) starshot.output.w.data(length(starshot.output.w.data),3)];
% starshot.postproc.Wf=starshot.postproc.Wf/norm(starshot.postproc.Wf);
% % plot3([0 starshot.postproc.Wf(1)],[0 starshot.postproc.Wf(2)],[0 starshot.postproc.Wf(3)])
% % hold on
% % grid on
% % plot3([0 starshot.IC.massproperties.PI(1,3)],[0 starshot.IC.massproperties.PI(2,3)],[0 starshot.IC.massproperties.PI(3,3)])
% % legend({'$\omega$','$I_z$'},'Interpreter','Latex')
% starshot.postproc.omegaIzangle=acosd(starshot.postproc.Wf(:)'*starshot.IC.massproperties.PI(:,3));
% disp('------------------------------------------------------------------------------------------')
% disp([num2str(k),' ',num2str(N),'| Initial conditions: '])
% disp(['   | Euler angles (phi theta psi): ',num2str(starshot.IC.eul*180/pi),' deg.'])
% disp(['   | Error angle between omega and B: ',num2str(starshot.output.real_angle.data(1)),' deg'])
% disp(['   | Initial omega: ',num2str(starshot.IC.w),' (',num2str(norm(starshot.IC.w)),') rps.'])
% %disp(['   | Desired omega: ',num2str(starshot.cmd.w'),' rps.'])
% disp('------------------------------------------------------------------------------------------')
% disp(['   | Final omega: ',num2str(starshot.output.w.data(length(starshot.output.w.data(:,1)),:)),' (',num2str(norm(starshot.output.w.data(length(starshot.output.w.data(:,1)),:))),') rps.'])
% disp(['   | Final angle between principal Iz and omega : ',num2str(starshot.postproc.omegaIzangle),' deg.'])
% %disp(['Angle between omega and B directions: ',num2str(asind(sqrt(starshot.output.theta_error_out.data(length(starshot.output.theta_error_out.data),:)*starshot.output.theta_error_out.data(length(starshot.output.theta_error_out.data),:)'))),' degrees.'])
% disp(['   | Final angle between omega and B vectors : ',num2str(starshot.output.real_angle.data(length(starshot.output.real_angle.data))),' deg.'])
% disp('------------------------------------------------------------------------------------------')
% starshot.postproc.error(t).k=k;
% starshot.postproc.error(t).N=N;
% starshot.postproc.error(t).IC_angle=starshot.IC.eul*180/pi;                                             % Initial angles (attitude)
% starshot.postproc.error(t).Deltatheta0=starshot.output.real_angle.data(1);                                                                  % Initial angular error
% starshot.postproc.error(t).initial_w=starshot.IC.w;                                                                                         % Initial angular velocity
% %starshot.postproc.error(t).initial_w_error=starshot.output.w_error_out.data(1,:);                                                           % Initial angular velocity error
% starshot.postproc.error(t).final_w=starshot.output.w.data(length(starshot.output.w.data),:);                                                % Final angular velocity
% %starshot.postproc.error(t).final_w_error=starshot.output.w_error_out.data(length(starshot.output.w_error_out.data),:);                      % Final angular velocity error
% starshot.postproc.error(t).Iz_w_angle_error=starshot.postproc.omegaIzangle;                                                                 % Final angular error between (Iz and omega)
% starshot.postproc.error(t).w_B_angle_error=starshot.output.real_angle.data(length(starshot.output.real_angle.data));                        % Final angular error between (omega and B)
% t=t+1;
% if PLOT==1
%     figure (2)
%     subplot(3,1,1)
%     p(1)=plot(starshot.output.w.time,starshot.output.w.data(:,1));
%     ylabel('$\omega_x\quad [rad/s]$','Interpreter','Latex','FontSize',13)
%     p(1).LineWidth=1;
%     set(gca,'FontSize',13)
%     grid on
%     grid minor
% 
%     subplot(3,1,2)
%     p(2)=plot(starshot.output.w.time,starshot.output.w.data(:,2));
%     ylabel('$\omega_y\quad [rad/s]$','Interpreter','Latex','FontSize',13)
%     p(2).LineWidth=1;
%     set(gca,'FontSize',13)
%     grid on
%     grid minor
% 
%     subplot(3,1,3)
%     p(3)=plot(starshot.output.w.time,starshot.output.w.data(:,3));
%     ylabel('$\omega_z\quad [rad/s]$','Interpreter','Latex','FontSize',13)
%     xlabel('Time [s]','Interpreter','Latex','FontSize',13)
%     p(3).LineWidth=1;
%     set(gca,'FontSize',13)
%     grid on
%     grid minor
%     set(gcf,'Position',[0 0 560 630])
%     figure (3)
%     p(4)=plot(starshot.output.real_angle.time,starshot.output.real_angle.data);
%     ylabel('$\theta_{\omega B}\quad[deg]$','Interpreter','Latex','FontSize',13)
%     xlabel('Time [s]','Interpreter','Latex','FontSize',13)
%     p(4).LineWidth=1;
%     set(gca,'FontSize',13)
%     grid on
%     grid minor
% end
% 
% % % Saturation control
% % for i=1:length(starshot.output.m_out.data(:,1))
% %     if starshot.output.m_out.data(i,1)==starshot.magnetorq.m_max_x | starshot.output.m_out.data(i,1)==-starshot.magnetorq.m_max_x
% %         sat_x(i)=1;
% %     else
% %         sat_x(i)=0;
% %     end
% %     if starshot.output.m_out.data(i,2)==starshot.magnetorq.m_max_y | starshot.output.m_out.data(i,2)==-starshot.magnetorq.m_max_y
% %         sat_y(i)=1;
% %     else
% %         sat_y(i)=0;
% %     end
% %     if starshot.output.m_out.data(i,3)==starshot.magnetorq.m_max_z | starshot.output.m_out.data(i,3)==-starshot.magnetorq.m_max_z
% %         sat_z(i)=1;
% %     else
% %         sat_z(i)=0;
% %     end
% % end
% % starshot.postproc.saturationperc(u,1)=length(find(sat_x))/length(starshot.output.m_out.data(:,1))*100;
% % starshot.postproc.saturationperc(u,2)=length(find(sat_y))/length(starshot.output.m_out.data(:,1))*100;
% % starshot.postproc.saturationperc(u,3)=length(find(sat_z))/length(starshot.output.m_out.data(:,1))*100;
% 
% 
% % Time performance control
% % precision=0.2;
% % for i=1:length(starshot.output.w.data(:,1))
% %     if acosd((starshot.output.w.data(i,:)/norm(starshot.output.w.data(i,:)))*starshot.IC.massproperties.PI(:,3))<precision | acosd((starshot.output.w.data(i,:)/norm(starshot.output.w.data(i,:)))*starshot.IC.massproperties.PI(:,3))>180-precision
% %         set_time=i;
% %         break;
% %     else
% %         set_time=length(starshot.output.w.data(:,1));
% %     end
% % end
% starshot.postproc.set_time(u)=starshot.output.w.time(length(starshot.output.w.time));%set_time*sim_time/length(starshot.output.w.data(:,1));
% u=u+1;
% clear sat_x sat_y sat_z set_time
% starshot.postproc.performance.Id(N,1)=starshot.cmd.Id;
% starshot.postproc.performance.c(1,k)=starshot.cmd.c;
% starshot.postproc.performance.set_time(N+1,k+1)=starshot.postproc.set_time(u-1);
% %starshot.postproc.performance.saturationperc(k,:)=[starshot.postproc.saturationperc(k,1) starshot.postproc.saturationperc(k,2) starshot.postproc.saturationperc(k,3)];
% end
% toc
% %dlmwrite('output_newmass_cmd05_W_pm5rand_A_pm180rand_time_30000_ts4tp2a800.csv',[starshot.postproc.error],'delimiter',',')
% end
% starshot.postproc.performance.results=starshot.postproc.performance.set_time;
% starshot.postproc.performance.results(1,2:end)=starshot.postproc.performance.c;
% starshot.postproc.performance.results(2:end,1)=starshot.postproc.performance.Id;
% clear N
% k=0;
% t=0;
% for i=1:length(starshot.postproc.error)
%     if starshot.postproc.error(i).Iz_w_angle_error>3 & starshot.postproc.error(i).Iz_w_angle_error<177
%         starshot.postproc.error(i).Iz_w_flag={'X'};
%         k=k+1;
%     end
%     if starshot.postproc.error(i).w_B_angle_error>3 & starshot.postproc.error(i).w_B_angle_error<177
%         starshot.postproc.error(i).w_B_flag='X';
%         t=t+1;
%     end
% end
% starshot.postproc.error(i+1).Iz_w_flag=k;
% starshot.postproc.error(i+1).w_B_flag=t;
% 
% % Iz vs omega
% 
% starshot.postproc.W=[starshot.output.w.data(:,1) starshot.output.w.data(:,2) starshot.output.w.data(:,3)];
% for i=1:length(starshot.postproc.W)
%     starshot.postproc.W(i,:)=starshot.postproc.W(i,:)/norm(starshot.postproc.W(i,:));
%     starshot.postproc.omegaIz(i,:)=acosd([starshot.postproc.W(i,1) starshot.postproc.W(i,2) starshot.postproc.W(i,3)]*starshot.IC.massproperties.PI(:,3));
% end
% figure (4)
% p(5)=plot(starshot.postproc.W(:,1),starshot.postproc.W(:,2),'-');
% ylabel('$\omega_y\quad [rad/s]$','Interpreter','Latex','FontSize',13)
% xlabel('$\omega_y\quad [rad/s]$','Interpreter','Latex','FontSize',13)
% p(5).LineWidth=1;
% p(5).MarkerSize=5;
% set(gca,'FontSize',13)
% grid on
% grid minor
% hold on
% if starshot.postproc.omegaIzangle<90
%     p(6)=plot(starshot.IC.massproperties.PI(1,3),starshot.IC.massproperties.PI(2,3),'.','Markersize',20);
% elseif starshot.postproc.omegaIzangle>90 
%     p(6)=plot(-starshot.IC.massproperties.PI(1,3),-starshot.IC.massproperties.PI(2,3),'.','Markersize',20);
% end
% legend({'Angular velocity','$I_z$ direction'},'Interpreter','Latex','FontSize',13)
% hold off
% 
% %Performance=struct2table(starshot.postproc.performance.results);
% %T=[starshot.postproc.set_time' starshot.postproc.saturationperc];
% % writetable(Performance,'Performance_output_4.csv')
% %dlmwrite('c_0p1to0p5__1to40__Id0p0001to0p1__41to50.csv',starshot.postproc.performance.results)
% 
% % figure (1)
% % yyaxis left
% % plot(linspace(0.0001,0.005,50),T(:,1))
% % yyaxis right
% % plot(linspace(0.0001,0.005,50),T(:,2))
% % hold on
% % plot(linspace(0.0001,0.005,50),T(:,3))
% % plot(linspace(0.0001,0.005,50),T(:,4))
% % 
% % figure (2)
% % yyaxis left
% % p1=polyfit([1:50],T(:,1)',4);
% % py1=polyval(p1,[1:50]);
% % plot(linspace(0.0001,0.005,50),py1)
% % yyaxis right
% % p2=polyfit([1:50],T(:,2)',4);
% % py2=polyval(p2,[1:50]);
% % p3=polyfit([1:50],T(:,3)',4);
% % py3=polyval(p3,[1:50]);
% % p4=polyfit([1:50],T(:,4)',4);
% % py4=polyval(p4,[1:50]);
% % plot(linspace(0.0001,0.005,50),py2)
% % hold on
% % plot(linspace(0.0001,0.005,50),py3)
% % plot(linspace(0.0001,0.005,50),py4)
% %diary off
% Output=struct2table(starshot.postproc.error);
% %writetable(Output,'output_newmass_ACDC6p6b_cmd1_W_pm1_5rand_A_pm180_100rand_time_15000_ts4tp05a500_try_P_only.csv')