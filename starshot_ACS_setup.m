clc
close all
clear all
%% Simulink model IC & cmd
altitude=400;% km
R=6371+altitude;% km
vc=sqrt(398600/(R))*1000;
ISS_inclination = deg2rad(51.6);
G=6.67e-11;
M_Earth=5.972e24;
R_Earth=6.378e6;
B0=3.12e-5;
mu_0=4*pi*(10^-7);


starshot.IC.x=R*1000;
starshot.IC.y=0;
starshot.IC.z=0;
starshot.IC.xdot=0;
starshot.IC.ydot= vc/sqrt(1+(tan(ISS_inclination))^2);
starshot.IC.zdot= tan(ISS_inclination)*vc/sqrt(1+(tan(ISS_inclination))^2);

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
[starshot.IC.massproperties.PI starshot.IC.massproperties.Ip]=eig(starshot.IC.massproperties.I);
starshot.IC.massproperties.Ixp=starshot.IC.massproperties.Ip(1,1);
starshot.IC.massproperties.Iyp=starshot.IC.massproperties.Ip(2,2);
starshot.IC.massproperties.Izp=starshot.IC.massproperties.Ip(3,3);
starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;

qmatlab=eul2quat(starshot.IC.eul);
q0=[qmatlab(2:4),qmatlab(1)]';

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


% Kane Damper
starshot.cmd.Kp=[starshot.IC.massproperties.Ip]*starshot.controller.Kp;
starshot.cmd.Kd=[starshot.IC.massproperties.Ip]*starshot.controller.Kd;
starshot.cmd.Id=0.0021;
starshot.cmd.invId=inv(starshot.cmd.Id);
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
starshot.magnetorq.e=0.250;                                % Max current (Ampere)
starshot.magnetorq.k=13.5;                                 % Gain
starshot.magnetorq.A=4e-5;                                 % Surface Area
starshot.magnetorq.n=500;                                  % Wire Turns (supposed)

starshot.magnetorq.m_max_x=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_y=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;
starshot.magnetorq.m_max_z=starshot.magnetorq.k*starshot.magnetorq.e*starshot.magnetorq.A*starshot.magnetorq.n;

starshot.magnetorq.i_max_x=starshot.magnetorq.m_max_x/(starshot.magnetorq.A*starshot.magnetorq.n);
starshot.magnetorq.i_max_y=starshot.magnetorq.m_max_y/(starshot.magnetorq.A*starshot.magnetorq.n);
starshot.magnetorq.i_max_z=starshot.magnetorq.m_max_z/(starshot.magnetorq.A*starshot.magnetorq.n);
