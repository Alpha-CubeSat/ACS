%                           PD design
clc
clear all
close all
a=800;                      % Satellite altitude
T=2*sqrt((6371+a)^3/398600);% Orbital period
tp=.3*T;                     %   Peak Time
ts=T;                     %   Settling Time
c=4.4*tp/(pi*ts)
zeta=sqrt(c^2/(1-c^2))      %   Damping ratio
omegan=4.4/(ts*zeta)        %   Natural frequency
Ims=pi/tp;
Res=4.4/ts;
s1=-Res+j*Ims;
ang_p=angle(1/s1^2);
ang_c=-pi-ang_p;
if ang_c<0
    ang_c=2*pi+ang_c
end
T=inv(imag(s1)/tan(ang_c)-real(s1));
Kpd=abs(s1^2/(s1+inv(T)));
Kd=Kpd;
Kp=Kpd/T;
PD=tf([Kd Kp],[1 Kd Kp])

step(PD)