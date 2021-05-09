% syms Ixx Ixy Ixz Iyx Iyy Iyz Izx Izy Izz
syms  p q r q1 q2 q3 q4 real
syms i1 i2 i3
syms B1 B2 B3 real
% syms J11 J12 J13 J21 J22 J23 J31 J32 J33 

Ixx=1940437.05021e-9;
Ixy= -65318.82269e-9;
Ixz=6047.20293e-9;
Iyx=-65318.82269e-9;
Iyy=1949979.02076e-9;
Iyz=-3703.69791e-9;
Izx= 6047.20293e-9;
Izy=-3703.69791e-9;
Izz= 2056529.54813e-9;

I=[Ixx,Ixy,Ixz;Iyx,Iyy,Iyz;Izx,Izy,Izz];
Iinv=I^-1;
i=[i1;i2;i3];
B=[B1;B2;B3];
omegadot=Iinv*(cross(i,B)-cross([p;q;r],I*[p;q;r]));
diff(omegadot(1),p);
f=-Iinv*cross([p;q;r],I*[p;q;r]);

qdot=(1/2)*[q4, -q3, q2;
      q3,q4,-q1;
      -q2,q1,q4;
      -q1,-q2,-q3]*[p,q,r]';

Bcross=[0,B3,-B2;
    -B3,0,B1;
    B2,-B1,0];

n=1000;
A=pi*(.005)^2'; 
M=n*A*eye(3);

A=[diff(f(1),p),diff(f(1),q),diff(f(1),r);
   diff(f(2),p),diff(f(2),q),diff(f(2),r);
   diff(f(3),p),diff(f(3),q),diff(f(3),r)];

% Aq=[diff(qdot(1),q1),diff(qdot(1),q2),diff(qdot(1),q3),diff(qdot(1),q4),diff(qdot(1),p),diff(qdot(1),q),diff(qdot(1),r);
%     diff(qdot(2),q1),diff(qdot(2),q2),diff(qdot(2),q3),diff(qdot(2),q4),diff(qdot(2),p),diff(qdot(2),q),diff(qdot(2),r);
%     diff(qdot(3),q1),diff(qdot(3),q2),diff(qdot(3),q3),diff(qdot(3),q4),diff(qdot(3),p),diff(qdot(3),q),diff(qdot(3),r);
%     diff(qdot(4),q1),diff(qdot(4),q2),diff(qdot(4),q3),diff(qdot(4),q4),diff(qdot(4),p),diff(qdot(4),q),diff(qdot(4),r)];

% e=cross([p,q,r]',B);
% Ae=[diff(e(1),p),diff(e(1),q),diff(e(1),r);
%    diff(e(2),p),diff(e(2),q),diff(e(2),r);
%    diff(e(3),p),diff(e(3),q),diff(e(3),r)];

edot=[B3*A(2,1)-B2*A(3,1),B3*A(2,2)-B2*A(3,2),B3*A(2,3)-B2*A(3,3);
     B1*A(3,1)-B3*A(1,1),B1*A(3,2)-B3*A(1,2),B1*A(3,3)-B3*A(1,3);
     B2*A(1,1)-B1*A(2,1),B2*A(1,2)-B1*A(2,2),B2*A(1,3)-B1*A(2,3)];


%%
B0=3.12e-5;
Re=6.37e6;
r=Re+400e3;
theta=85*pi/180;
Br=-2*B0*((Re/r)^3)*cos(theta);
Btheta=-B0*((Re/r)^3)*sin(theta);
B1=0;
B2=Br;
B3=Btheta;
p=0;
q=0;
r=pi/10;
q1=0;
q2=0;
q3=1;
q4=1;
A=vpa(A);
A=subs(A);
A=double(A);

Ae=subs(edot);
Ae=double(Ae);

%C=ctrb(Alqr,Bmatrix);

%%
Alqr=[zeros(3),Ae;
       zeros(3),A];
   
Bmatrix=[zeros(3);0,B3,-B2;-B3,0,B1;B2,B1,0];
Q=eye(6);
Q(1,1)=1;
Q(2,2)=1;
Q(3,3)=1;
Q(4,4)=100;
Q(5,5)=100;
Q(6,6)=100;
Klqr=lqr(Alqr,Bmatrix,Q,eye(3));



