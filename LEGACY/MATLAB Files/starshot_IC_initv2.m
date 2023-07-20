clear all
starshot.IC.x=7e6;
starshot.IC.y=0;
starshot.IC.z=0;
starshot.IC.xdot=7000;
starshot.IC.ydot=0;
starshot.IC.zdot=0;

starshot.IC.phi=pi/10;
starshot.IC.theta=0;
starshot.IC.psi=0;

qmatlab=eul2quat([starshot.IC.phi,starshot.IC.theta,starshot.IC.psi]);
q0=[qmatlab(2:4),qmatlab(1)]';

Kp_phi=.1;
Kp_theta=.1;
Kp_psi=.1;

starshot.cmd.Kd=[0.7502,0.8703,0.9229]'*1e-5;
starshot.cmd.Kp=[.5717,.6633,.7034]'*1e-7;
starshot.IC.p=0;
starshot.IC.q=0;
starshot.IC.r=-pi/4;
starshot.IC.massproperties.m=.839;
% starshot.IC.massproperties.Ixx=5521062.3983e-9;
% starshot.IC.massproperties.Ixy=1925020.9549e-9;
% starshot.IC.massproperties.Ixz=1536535.4698e-9;
% starshot.IC.massproperties.Iyx=1925020.9549e-9;
% starshot.IC.massproperties.Iyy=5345390.7635e-9;
% starshot.IC.massproperties.Iyz=1853230.8333e-9;
% starshot.IC.massproperties.Izx=1536535.4698e-9;
% starshot.IC.massproperties.Izy=1853230.8333e-9;
% starshot.IC.massproperties.Izz=5790514.3718e-9;

starshot.IC.massproperties.Ixx=1940437.05021e-9;
starshot.IC.massproperties.Ixy= -65318.82269e-9;
starshot.IC.massproperties.Ixz=6047.20293e-9;
starshot.IC.massproperties.Iyx=-65318.82269e-9;
starshot.IC.massproperties.Iyy=1949979.02076e-9;
starshot.IC.massproperties.Iyz=-3703.69791e-9;
starshot.IC.massproperties.Izx= 6047.20293e-9;
starshot.IC.massproperties.Izy=-3703.69791e-9;
starshot.IC.massproperties.Izz= 2056529.54813e-9;



starshot.IC.massproperties.I=[starshot.IC.massproperties.Ixx,starshot.IC.massproperties.Ixy,starshot.IC.massproperties.Ixz;
starshot.IC.massproperties.Iyx,starshot.IC.massproperties.Iyy,starshot.IC.massproperties.Iyz;
starshot.IC.massproperties.Izx,starshot.IC.massproperties.Izy,starshot.IC.massproperties.Izz];
starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;

starshot.IC.massproperties.Iinv=starshot.IC.massproperties.I^-1;
G=6.67e-11;
M_Earth=5.972e24;
R_Earth=6.378e6;
B0=3.12e-5;
mu_0=4*pi*(10^-7);
n=500;
A=0.07979645340118074;
starshot.magnetorq.A=0.07979645340118074;                  % Surface Area
starshot.magnetorq.n=500;                                  % Wire Turns (supposed)


starshot.cmd.p=0;
starshot.cmd.q=0;
starshot.cmd.r=pi/10;

omegacmd=[starshot.cmd.p,starshot.cmd.q,starshot.cmd.r]';
%quatcmdmatlab=eul2quat([starshot.cmd.psi,starshot.cmd.theta,starshot.cmd.phi]);
%quatcmd=[quatcmdmatlab(2:4),quatcmdmatlab(1)]';


