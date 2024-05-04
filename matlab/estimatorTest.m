u=zeros(23,1);
u(2:4)=[1;1; 1];
u(20:22)=[1;1; 1];
u(23)=0;
out=fullEstimator(u,P);

