
figure()
tiledlayout(4,2)
k=10;
tempsize=size(yt);
tsize=tempsize(1);
nexttile
hold off
plot(yt(k:tsize,1),'r');
title('PM temp')
hold on
plot(yp(k:tsize,1),'b');
legend('test','predict');
hold off
%plot error
nexttile 
plot(yt(k:tsize,1)-yp(k:tsize,1));
title('PM temp error')
%plot next parameter
nexttile
plot(yt(k:tsize,2),'r');
title('Stator yoke')
hold on
plot(yp(k:tsize,2),'b');
%legend('test','predict');
hold off
nexttile
plot(yt(k:tsize,2)-yp(k:tsize,2));
title('Stator yoke error')
hold off
nexttile
plot(yt(k:tsize,3),'r');
title('Stator tooth')
hold on
plot(yp(k:tsize,3),'b');
%legend('test','predict');
hold off
nexttile
plot(yt(k:tsize,3)-yp(k:tsize,3));
title('Stator tooth error')
hold off
nexttile
plot(yt(k:tsize,4),'r');
title('Stator winding')
hold on
plot(yp(k:tsize,4),'b');
%legend('test','predict');
hold off
nexttile
plot(yt(k:tsize,4)-yp(k:tsize,4));
title('Stator winding error')
hold off

