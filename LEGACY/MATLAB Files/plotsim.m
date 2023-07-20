figure(1);
subplot(3,1,1);
plot(p.Time,p.Data);
subplot(3,1,2);
plot(q.Time,q.Data);
subplot(3,1,3);
plot(r.Time,r.Data);

figure(2);
subplot(4,1,1);
plot(q1.Time,q1.Data);
subplot(4,1,2);
plot(q2.Time,q2.Data);
subplot(4,1,3);
plot(q3.Time,q3.Data);
subplot(4,1,4);
plot(q4.Time,q4.Data);

%%

for i=1:size(p.Data,1)
Hmag(i)=norm(starshot.IC.massproperties.I*[p.Data(i),q.Data(i),r.Data(i)]');
E(i)=[p.Data(i),q.Data(i),r.Data(i)]*starshot.IC.massproperties.I*[p.Data(i),q.Data(i),r.Data(i)]';
end