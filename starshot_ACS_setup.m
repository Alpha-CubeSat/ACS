clc
close all
clear all
%% Simulink model IC & cmd
altitude=400;% km

ISS_inclination = deg2rad(51.6);
G=6.67e-11;
M_Earth=5.972e24;
R_Earth=6.371e6; %m
B0=3.12e-5;
mu_0=4*pi*(10^-7);
%vc=sqrt(398600/(altitude+R_Earth/1000))*1000; %replaced
dutyclc = 0.5; % [0,1] the dutycycle of the pointing controller
dutyT = 9*60; %sec the period of the pointing controller dutyclc


%starshot.IC.x=altitude*1000+R_Earth; %replaced
starshot.IC.y=0;
starshot.IC.z=0;

starshot.IC.xdot=0;
%starshot.IC.ydot= vc/sqrt(1+(tan(ISS_inclination))^2); %replaced
%starshot.IC.zdot= tan(ISS_inclination)*vc/sqrt(1+(tan(ISS_inclination))^2);%replaced

discretization_c=linspace(0.0001,0.1,50);
discretization_Id=linspace(0.0001,0.1,50);
starshot.IC.eul=pi/6*[1 2 3];
starshot.IC.w=[0 0 1];

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


[starshot.IC.massproperties.PI, starshot.IC.massproperties.Ip]=eig(starshot.IC.massproperties.I);

starshot.IC.massproperties.Ixp=starshot.IC.massproperties.Ip(1,1);
starshot.IC.massproperties.Iyp=starshot.IC.massproperties.Ip(2,2);
starshot.IC.massproperties.Izp=starshot.IC.massproperties.Ip(3,3);

starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;

qmatlab=eul2quat(starshot.IC.eul);
q_init=[qmatlab(2:4),qmatlab(1)]';

%% Controller Design
%%%%%%%%%%%%%%DUTY CYCLE%%%%%%%%%%%%
starshot.controller.dutyclc = dutyclc;
starshot.controller.dutyT = dutyT;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
starshot.controller.s1=-starshot.controller.Res+1i*starshot.controller.Ims;
starshot.controller.ang_p=angle(1/starshot.controller.s1^2);
starshot.controller.ang_c=-pi-starshot.controller.ang_p;

if starshot.controller.ang_c<0
    starshot.controller.ang_c=2*pi+starshot.controller.ang_c;
end
%Pointing Gains
starshot.controller.Td=inv(imag(starshot.controller.s1)/tan(starshot.controller.ang_c)-real(starshot.controller.s1));
starshot.controller.Kpd=abs(starshot.controller.s1^2/(starshot.controller.s1+inv(starshot.controller.Td)));

starshot.controller.Kd=starshot.controller.Kpd;
starshot.controller.Kp=starshot.IC.massproperties.Izp*starshot.controller.Kpd/starshot.controller.Td;
starshot.cmd.Kp=[starshot.IC.massproperties.Ip]*starshot.controller.Kp;
starshot.cmd.Kd=[starshot.IC.massproperties.Ip]*starshot.controller.Kd;

% Kane Damper Vars
starshot.cmd.Id=0.0021;
%starshot.cmd.invId=inv(starshot.cmd.Id);replaced
starshot.cmd.c=0.004;
starshot.cmd.w=[0 0 1]';
starshot.cmd.wdb0=[0 0 1]';
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

starshot.magnetorq.V=4;                                    % Volt
starshot.magnetorq.i_max=0.250;                            % Max current (Ampere)
starshot.magnetorq.k=13.5;                                 % Gain
starshot.magnetorq.A=4e-5;                                 % Surface Area
starshot.magnetorq.n=500;                                  % Wire Turns (supposed)

%% Simulink Auto-Code Parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The ones being defined as Simulink.Parameter
% need to replace the original variable 
% (aka, replacing starshot.controller.Kd by kd in Simulink) 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%Hardware Paramters%%%%%%%%%%%%%%%%%%%%%%%
%i_max
i_max  = Simulink.Parameter;
i_max.Value = starshot.magnetorq.i_max;
i_max.CoderInfo.StorageClass = 'ExportedGlobal';
i_max.CoderInfo.Alias = 'i_max';
i_max.Description = "Max Current for each magnetorquer";
i_max.DataType = 'double';
assignin('base', "i_max", i_max);
%k
k  = Simulink.Parameter;
k.Value = starshot.magnetorq.k;
k.CoderInfo.StorageClass = 'ExportedGlobal';
k.CoderInfo.Alias = 'k';
k.Description = "Gain for magnetorquer";
k.DataType = 'double';
assignin('base', "k", k);
%A
A  = Simulink.Parameter;
A.Value = starshot.magnetorq.A;
A.CoderInfo.StorageClass = 'ExportedGlobal';
A.CoderInfo.Alias = 'A';
A.Description = "Cross Section Area For magnetorquer";
A.DataType = 'double';
assignin('base', "A", A);

%n
n  = Simulink.Parameter;
n.Value = starshot.magnetorq.n;
n.CoderInfo.StorageClass = 'ExportedGlobal';
n.CoderInfo.Alias = 'n';
n.Description = "Wire Turn For magnetorquer";
n.DataType = 'double';
assignin('base', "n", n);
%%%%%%%%%%%%%%%%%Controller Parameters%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%Pointing%%%%%%%%%%%%%%%%%%%%%%
%Kd
Kd  = Simulink.Parameter;
Kd.Value = starshot.controller.Kd ;
Kd.CoderInfo.StorageClass = 'ExportedGlobal';
Kd.CoderInfo.Alias = 'Kd';
Kd.Description = "Kd for the pointing";
Kd.DataType = 'double';
assignin('base', "Kd", Kd);
%Kp
Kp  = Simulink.Parameter;
Kp.Value = starshot.controller.Kp ;
Kp.CoderInfo.StorageClass = 'ExportedGlobal';
Kp.CoderInfo.Alias = 'Kp';
Kp.Description = "Kp for the pointing";
Kp.DataType = 'double';
assignin('base', "Kp", Kp);
%%%%%%%%%%%%%%%%%%%%%%%Detumble%%%%%%%%%%%%%%%%%%%%%%
%c
c  = Simulink.Parameter;
c.Value = starshot.cmd.c ;
c.CoderInfo.StorageClass = 'ExportedGlobal';
c.CoderInfo.Alias = 'c';
c.Description = "c for the Detumble";
c.DataType = 'double';
assignin('base', "c", c);

%Id
Id  = Simulink.Parameter;
Id.Value = starshot.cmd.Id ;
Id.CoderInfo.StorageClass = 'ExportedGlobal';
Id.CoderInfo.Alias = 'Id';
Id.Description = "Id for the Detumble";
Id.DataType = 'double';
assignin('base', "Id", Id);


%%%%%%%%%%%%%%%%%Mass Parameters%%%%%%%%%%%%%%%
%mass
m  = Simulink.Parameter;
m.Value = starshot.IC.massproperties.m ;
m.CoderInfo.StorageClass = 'ExportedGlobal';
m.CoderInfo.Alias = 'm';
m.Description = "Cubesat Mass";
m.DataType = 'double';
assignin('base', "m", m);

%mass Inertia
I= Simulink.Parameter;
Ixx= starshot.IC.massproperties.Ixx;
Ixy = starshot.IC.massproperties.Ixy;
Ixz = starshot.IC.massproperties.Ixz;
Iyx = starshot.IC.massproperties.Iyx;
Iyy = starshot.IC.massproperties.Iyy;
Iyz = starshot.IC.massproperties.Iyz;
Izx = starshot.IC.massproperties.Izx;
Izy = starshot.IC.massproperties.Izy;
Izz= starshot.IC.massproperties.Izz;

I.Value = [Ixx,Ixy,Ixz;
           Iyx,Iyy,Iyz;
           Izx,Izy,Izz];

I.CoderInfo.StorageClass = 'ExportedGlobal';
I.CoderInfo.Alias = 'I';
I.DataType = 'double';
assignin('base', "I", I);

%%%%%%%%%%%%%%%%%Plant Parameters%%%%%%%%%%%%%%%
%wx
wx = Simulink.Parameter;
wx.Value = starshot.IC.w(1) ;
wx.CoderInfo.StorageClass = 'ExportedGlobal';
wx.CoderInfo.Alias = 'wx';
wx.Description = "init angular vel -x";
wx.DataType = 'double';
assignin('base', "wx", wx);
%wy
wy = Simulink.Parameter;
wy.Value = starshot.IC.w(2) ;
wy.CoderInfo.StorageClass = 'ExportedGlobal';
wy.CoderInfo.Alias = 'wy';
wy.Description = "init angular vel -y";
wy.DataType = 'double';
assignin('base', "wy", wy);
%wz
wz = Simulink.Parameter;
wz.Value = starshot.IC.w(3) ;
wz.CoderInfo.StorageClass = 'ExportedGlobal';
wz.CoderInfo.Alias = 'wz';
wz.Description = "init angular vel -z";
wz.DataType = 'double';
assignin('base', "wz", wz);
%inclination
inclination = Simulink.Parameter;
inclination.Value = ISS_inclination ;
inclination.CoderInfo.StorageClass = 'ExportedGlobal';
inclination.CoderInfo.Alias = 'inclination';
inclination.Description = "ISS inclination";
inclination.DataType = 'double';
assignin('base', "inclination", inclination);
%Alt
Alt = Simulink.Parameter;
Alt.Value = altitude ;
Alt.CoderInfo.StorageClass = 'ExportedGlobal';
Alt.CoderInfo.Alias = 'Altitude';
Alt.Description = "Cubesat Altitude (km)";
Alt.DataType = 'double';
assignin('base', "Alt", Alt);
%q0
q0 = Simulink.Parameter;
q0.Value = q_init;
q0.CoderInfo.StorageClass = 'ExportedGlobal';
q0.CoderInfo.Alias = 'q0';
q0.Description = "Init Quat (Default Euler Angle = pi/6*[1 2 3])";
q0.DataType = 'double';
assignin('base', "q0", q0);


%%%SYSTEM PARAMETER
% %Plant Step
% plt_step = Simulink.Parameter;
% plt_step.Value = 0.001 ;
% plt_step.CoderInfo.StorageClass = 'ExportedGlobal';
% plt_step.CoderInfo.Alias = 'plt_step';
% plt_step.Description = "Step size of the plant (s)";
% plt_step.DataType = 'double';
% assignin('base', "plt_step", plt_step);
% 
% %Starshot Step
% starshot_step = Simulink.Parameter;
% starshot_step.Value = 0.2 ;
% starshot_step.CoderInfo.StorageClass = 'ExportedGlobal';
% starshot_step.CoderInfo.Alias = 'plt_step';
% starshot_step.Description = "Step size of the controller (s)";
% starshot_step.DataType = 'double';
% assignin('base', "starshot_step", starshot_step);




