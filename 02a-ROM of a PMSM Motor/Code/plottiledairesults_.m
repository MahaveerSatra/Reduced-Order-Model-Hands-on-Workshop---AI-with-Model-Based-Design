
figure()
tiledlayout(4,2)
k=10;
tempsize=size(yt);
tsize=tempsize(1);
nexttile
plot(yt(k:tsize,1),yp(k:tsize,1),'.');
v=corr(yt(k:tsize,1),yp(k:tsize,1));
title('PM temp')
legend(string(v));
xlabel('measured');
ylabel('predicted')
%plot error
nexttile 
%boxplot(yt(k:tsize,1)-yp(k:tsize,1));
histogram((yt(k:tsize,1)-yp(k:tsize,1)));
axis([-0.4 0.4 0 inf]);
title('PM temp error')
%plot next parameter
nexttile
plot(yt(k:tsize,2),yp(k:tsize,2),'.');
v=corr(yt(k:tsize,2),yp(k:tsize,2));
legend(string(v));
xlabel('measured');
ylabel('predicted')
%legend('test','predict');
nexttile
%boxplot(yt(k:tsize,2)-yp(k:tsize,2));
histogram(yt(k:tsize,2)-yp(k:tsize,2));
axis([-0.4 0.4 0 inf]);
title('Stator yoke error')
nexttile
plot(yt(k:tsize,3),yp(k:tsize,3),'.');
v=corr(yt(k:tsize,3),yp(k:tsize,3));
legend(string(v));
xlabel('measured');
ylabel('predicted')
nexttile
%boxplot(yt(k:tsize,3)-yp(k:tsize,3));
histogram(yt(k:tsize,3)-yp(k:tsize,3));
axis([-0.4 0.4 0 inf]);
title('Stator tooth error')
nexttile
plot(yt(k:tsize,4),yp(k:tsize,4),'.');
v=corr(yt(k:tsize,4),yp(k:tsize,4));
legend(string(v));
xlabel('measured');
ylabel('predicted')
nexttile
%boxplot(yt(k:tsize,4)-yp(k:tsize,4));
histogram(yt(k:tsize,4)-yp(k:tsize,4));
axis([-0.4 0.4 0 inf]);
title('Stator winding error')
hold off

