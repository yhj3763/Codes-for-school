#include "ccc_win.h"
#include <iostream>

using namespace std;


class Parachutist
{
   public:
    Parachutist();
    Parachutist(Point p);
    void display();
    void move();

   private:
    Point a;


};

Parachutist::Parachutist()
{
   Point a=Point(0,0);
}



int ccc_win_main()
{
    const double af=32;
    const double tv=174;
    const double df=100;
    const double drf
    int vv=0;
    int hv=0;


    double sp=cwin.get_double("Write the speed of the plane:");
    double hp=cwin.get_double("Write the height of the plane:");
    double fat=cwin.get_double("Write the freefall time:");

    while(vv!=tv)
     {
       vv+=af;
       hp-=vv;
       if(vv>tv)
        {
           vv=tv;           
        }
       fat--;
     }

    while(vv!=17)
     {
       vv-=df;
       hp-=vv;
       if(vv<17)
        {
          vv=17;
        }
       fat--;
      }



 
}
