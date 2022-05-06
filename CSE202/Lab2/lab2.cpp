//Hyeongjun Yang
//Lab2 Monday.
#include "ccc_win.h"
#include <ctime>
#include <cstdlib>

  
class Parachutist
{
    public:
      Parachutist();
      Parachutist(Point b);
      void display(int t,int ss, int height,double r);
      void move(int dx, int dy);
      Point get_a();
    private:
      Point a;

};

Parachutist::Parachutist()
{
   Point a = Point(0,0);    
}
Parachutist::Parachutist(Point b)
{
    a = b;
}

void Parachutist::move(int dx,int dy)
{
     a.move(dx,-dy);
}
void Parachutist::display(int t,int ss,int height,double r)
{   
       
  
   if(t<ss and t==0 or t%3==0)
    {
      cwin<<Circle(a,r);
    }
   else if(t>ss and t%3==0) 
    {
      
      cwin<<Circle(a,r);
   
      
    }
   
   
}

Point Parachutist::get_a()
{
  return a;
}

int ccc_win_main()
{
  int dv=0;
  int hv=0;
  int df=0;   
  int t=0; 
 

  int height=cwin.get_int("Type the height:");
  int speed=cwin.get_int("Type the speed of plane:");
  int ss=cwin.get_int("Write your second to open a parachute:");  
  cwin.coord(0,height,height,0);
  Point dfo=cwin.get_mouse("Plot the descent of the falling object.");
  int x=dfo.get_x();
  int x2=0;

  double e=height*0.15;
  double y=height*0.028;
  double g=height*0.26;
  double r1=height*0.0060;


  Parachutist P=Parachutist(dfo); 
  hv=speed;
  srand(time(0));
 
 while(1)
   {
     P.display(t,ss,height,r1);
     if(height<=0)
      {
        cwin<<Circle(Point(x+(speed*(t-1)),r1),r1);      
        break;
      }
     if(dv<174)
       dv+=32;
     else
       dv=174;

     height-=dv;
     P.move(hv,dv);
     if(t>=ss)
      break;
     
     t++;
   }
  
 if(t==ss)
    cwin<<Message(Point(x-e,height),"---------Parachute opened at this line---------");
    
    
 while(1)
   {
     P.display(t,ss,height,r1);
     dv-=100;
     if(dv<=17)
      {
        dv=17;
      }
     
     height-=dv;
     hv-=rand()%41+20;
     if(hv<0)
      {
        hv=0;    
    
      } 
     P.move(hv,dv);  
      
     if(height<=0)
      {
        height=0;
        Point a=P.get_a();
        x2=a.get_x();
        //cwin<<Circle(Point(x2,height+r2),r2);
        cwin<<Message(Point(x2-g,y),"landed here->");
        break;
      }
      

     t++;
    }      

    
  
}
