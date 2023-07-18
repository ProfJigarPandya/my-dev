#include <stdio.h>
#include <graphics.h>
int main()
{
int gd=DETECT, gm=VGAMAX;
initgraph(&gd,&gm, 0);
moveto(0, 0);
setcolor(4);
rectangle(50,50,500,200);
while(!kbhit());
closegraph();
return 0;
}
