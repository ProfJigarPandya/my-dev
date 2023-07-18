#include <stdio.h>
#define MAX 100
struct location
{
 char city[MAX], state[MAX], country[MAX];
};
struct appointment
{
 char title[MAX];
 struct location l;
 struct date_time
 {
   int day, month, year;
 }start, end;
};
int main()
{
 struct appointment a;
 scanf("%s",a.title);
 scanf("%s",a.l.city);
 scanf("%d",&a.start.day);
 
}
