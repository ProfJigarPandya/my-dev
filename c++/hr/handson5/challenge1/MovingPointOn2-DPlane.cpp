#include <iostream>
using namespace std;
/* Define your class and its methods here*/
class MovingPoint
{
    int pointx;
    int pointy;
    bool doinit=true;//true means yes
 public:
    void initialize(int x, int y) //Initializes the object of MovingPoint class to given co-ordinates (x, y) on the plane. Should be called only once in object's lifetime. If this method is called more than once for any object then it should not change the state of the object (should not change the position of the point on the X-Y plane for all calls except first)
    {
        if(doinit)
        {
            pointx=x;
            pointy=y;
            doinit=false;
        }
    }

    void move_left(int x) // Point moves left by x units, as specified in the call
    {
        pointx-=x;
    }

    void move_right(int x) // Point moves right by x units, as specified in the call
    {
        pointx+=x;
    }

    void move_up(int y) // Point moves up by y units, as specified in the call
    {
        pointy+=y;
    }

    void move_down(int y) // Point moves down by y units, as specified in the call
    {
        pointy-=y;
    }

    void print_current_position() // Prints current position of the point on the X-Y plane
    {
        cout<<pointx<<" "<<pointy;
    }
};
int main() 
{
  
  MovingPoint mp;
  int x, y, n, i, units;
  char direction;
  
  std::cin >> x >> y;
  mp.initialize(x, y);
  
  std::cin >> n;
  for(i = 0; i < n; i++)
  {
    std::cin >> direction >> units;
    switch(direction)
    {
      case 'L':
        mp.move_left(units);
        break;
      case 'R':
        mp.move_right(units);
        break;
      case 'U':
        mp.move_up(units);
        break;
      case 'D':
        mp.move_down(units);
        break;
    }
  }
  
  // This call to initialize method should be ingored
  // If this method is called twice, it should be ignored as per specification
  // This call should not change the state of the object
  mp.initialize(0, 0);
  
  // Printing final position of the point as output
  mp.print_current_position();
  
  return 0;
}
