#include <stdio.h>
#include <conio.h>


void main()
{
  clrscr();
  printf("\n Integer values  ");
  printf("%d   %d  %d",32767,32767+1,32767+10);          // 32767 garbage garbage


  printf("\n Long Integer values");
  printf("    %d  %ld  %ld",32767,30000+30000,32767+10);   // 32767 garbage garbage

  // use of L ........
  printf("\n Long modified  Integer values");          //    32767   32768  32777
  printf("    %d   %ld  %ld",32767,32767L+1L,32767L+10L);


 //
 printf("\nlast...............");     //  garbage
 printf("   %ld",30000+30000);



 printf("\nlast11111111    ...............");   // 60000
 printf("   %ld",30000L+30000L);


 printf("\nlast11111111    ...............");   // garbage
 printf("   %d",40000);


 printf("\nlast11111111    ...............");  // 40000
 printf("   %u",40000U);






  getch();
}
