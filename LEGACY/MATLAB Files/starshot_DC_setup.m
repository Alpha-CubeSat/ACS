clc
close
clear all
%% Controller Design

starshot.controller.a=800;                                                          % Satellite altitude
starshot.controller.T=2*sqrt((6371+starshot.controller.a)^3/398600);                % Orbital period
starshot.controller.tp=.3*starshot.controller.T;                                    %   Peak Time
starshot.controller.ts=starshot.controller.T;                                       %   Settling Time
starshot.controller.c=4.4*starshot.controller.tp/(pi*starshot.controller.ts)
starshot.controller.zeta=sqrt(starshot.controller.c^2/(1-starshot.controller.c^2))  %   Damping ratio
starshot.controller.omegan=4.4/(starshot.controller.ts*starshot.controller.zeta)    %   Natural frequency
starshot.controller.Ims=pi/starshot.controller.tp;
starshot.controller.Res=4.4/starshot.controller.ts;
starshot.controller.s1=-starshot.controller.Res+j*starshot.controller.Ims;
starshot.controller.ang_p=angle(1/starshot.controller.s1^2);
starshot.controller.ang_c=-pi-starshot.controller.ang_p;
if starshot.controller.ang_c<0
    starshot.controller.ang_c=2*pi+starshot.controller.ang_c
end
starshot.controller.Td=inv(imag(starshot.controller.s1)/tan(starshot.controller.ang_c)-real(starshot.controller.s1));
starshot.controller.Kpd=abs(starshot.controller.s1^2/(starshot.controller.s1+inv(starshot.controller.Td)));
starshot.controller.Kd=starshot.controller.Kpd;
starshot.controller.Kp=starshot.controller.Kpd/starshot.controller.Td;

%% Simulink model IC & cmd

starshot.IC.x=7e6;
starshot.IC.y=0;
starshot.IC.z=0;
starshot.IC.phi=pi/4;
starshot.IC.theta=-pi/4;
starshot.IC.psi=-pi/6;
starshot.IC.w=[-pi/6 -pi/10 -pi/4];
starshot.IC.massproperties.m=.839;
starshot.IC.massproperties.Ixx=5521062.3983e-9;
starshot.IC.massproperties.Ixy=1925020.9549e-9;
starshot.IC.massproperties.Ixz=1536535.4698e-9;
starshot.IC.massproperties.Iyx=1925020.9549e-9;
starshot.IC.massproperties.Iyy=5345390.7635e-9;
starshot.IC.massproperties.Iyz=1853230.8333e-9;
starshot.IC.massproperties.Izx=1536535.4698e-9;
starshot.IC.massproperties.Izy=1853230.8333e-9;
starshot.IC.massproperties.Izz=5790514.3718e-9;
starshot.IC.massproperties.I=[starshot.IC.massproperties.Ixx,starshot.IC.massproperties.Ixy,starshot.IC.massproperties.Ixz;
starshot.IC.massproperties.Iyx,starshot.IC.massproperties.Iyy,starshot.IC.massproperties.Iyz;
starshot.IC.massproperties.Izx,starshot.IC.massproperties.Izy,starshot.IC.massproperties.Izz];
%starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;
starshot.IC.massproperties.Ixp=1639836.0399e-9;
starshot.IC.massproperties.Iyp=1902436.5156e-9;
starshot.IC.massproperties.Izp=2017393.6728e-9;

starshot.IC.massproperties.I=[starshot.IC.massproperties.Ixp 0 0;...
                              0 starshot.IC.massproperties.Iyp 0;...
                              0 0 starshot.IC.massproperties.Izp];
starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;

qmatlab=eul2quat([starshot.IC.phi,starshot.IC.theta,starshot.IC.psi]);
q0=[qmatlab(2:4),qmatlab(1)]';

starshot.cmd.Kp=[starshot.IC.massproperties.Ixp starshot.IC.massproperties.Iyp starshot.IC.massproperties.Izp]*starshot.controller.Kp;
starshot.cmd.Kd=[starshot.IC.massproperties.Ixp starshot.IC.massproperties.Iyp starshot.IC.massproperties.Izp]*starshot.controller.Kd;
starshot.cmd.w=[0 0 pi/10]';

G=6.67e-11;
M_Earth=5.972e24;
R_Earth=6.378e6;
B0=3.12e-5;
mu_0=4*pi*(10^-7);
n=1000;

%% Hardware

%starshot.magnetorq.V=3;                                    % Volt
starshot.magnetorq.e=0.33;                                 % Ampere
starshot.magnetorq.k=1;                                    % Gain
starshot.magnetorq.A=0.07979645340118074;                  % Surface Area
starshot.magnetorq.n=50;                                  % Wire Turns (supposed)
starshot.magnetorq.m_max_x=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_y=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_z=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;

%% Post Proc
PD=tf([starshot.controller.Kd starshot.controller.Kp],[1 starshot.controller.Kd starshot.controller.Kp])
%figure (1) 
%step(PD)
s=tf('s');
PD3=[(s*starshot.cmd.Kd(1)+starshot.cmd.Kp(1))/(s^2*starshot.IC.massproperties.Ixp+s*starshot.cmd.Kd(1)+starshot.cmd.Kp(1)) 0 0;...
     0 (s*starshot.cmd.Kd(2)+starshot.cmd.Kp(2))/(s^2*starshot.IC.massproperties.Iyp+s*starshot.cmd.Kd(2)+starshot.cmd.Kp(2)) 0;...
     0 0 (s*starshot.cmd.Kd(3)+starshot.cmd.Kp(3))/(s^2*starshot.IC.massproperties.Izp+s*starshot.cmd.Kd(3)+starshot.cmd.Kp(3))]
%figure (2) 
step(PD3);
grid on; grid minor
[starshot.controller.classicalmargins,starshot.controller.diskmargns,starshot.controller.multiloopmargins] = loopmargin(PD3);
% damp(PD3)
% figure (3)
% nyquist(PD3)

% figure (4)
% subplot(3,1,1)
% plot(w.time,w.data(:,1));
% title('Angular speed $\omega$','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('Angular velocity [rad/s]','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,2)
% plot(w.time,w.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('Angular velocity [rad/s]','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,3)
% plot(w.time,w.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('Angular velocity [rad/s]','Interpreter','Latex')
% grid on; grid minor
% 
% figure (5)
% subplot(3,1,1)
% plot(Eul.time,Eul.data(:,1));
% title('Euler Angles','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\theta$ [deg]','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,2)
% plot(Eul.time,Eul.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\phi$ [deg]','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,3)
% plot(Eul.time,Eul.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\psi$ [deg]','Interpreter','Latex')
% grid on; grid minor
% 
% figure (6)
% subplot(3,2,1)
% plot(theta_error_out.time,theta_error_out.data(:,1));
% title('Angle error','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\theta_x$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,2,3)
% plot(theta_error_out.time,theta_error_out.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\theta_y$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,2,5)
% plot(theta_error_out.time,theta_error_out.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\theta_z$','Interpreter','Latex')
% grid on; grid minor
% 
% subplot(3,2,2)
% plot(w_error_out.time,w_error_out.data(:,1));
% title('Angular velocity error','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\omega_x$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,2,4)
% plot(w_error_out.time,w_error_out.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\omega_y$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,2,6)
% plot(w_error_out.time,w_error_out.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$\Delta\omega_z$','Interpreter','Latex')
% grid on; grid minor
% 
% figure (7)
% subplot(3,1,1)
% plot(m_out.time,m_out.data(:,1));
% title('Magnetic dipole','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$m_x$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,2)
% plot(m_out.time,m_out.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$m_y$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,3)
% plot(m_out.time,m_out.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$m_z$','Interpreter','Latex')
% grid on; grid minor

% figure (8)
% subplot(3,1,1)
% plot(current.time,current.data(:,1));
% title('Current','Interpreter','Latex')
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$I_x$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,2)
% plot(current.time,current.data(:,2));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$I_y$','Interpreter','Latex')
% grid on; grid minor
% subplot(3,1,3)
% plot(current.time,current.data(:,3));
% xlabel('Time [s]','Interpreter','Latex')
% ylabel('$I_z$','Interpreter','Latex')
% grid on; grid minor