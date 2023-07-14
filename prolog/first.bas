screen 12
const pi= 3.14159/180
for i%=1 to 360
line (320-200*cos(pi*i%),240-200*sin(pi*i%))-(320,240);
next i%
