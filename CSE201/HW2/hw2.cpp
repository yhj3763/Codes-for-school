#include "ccc_win.h"
#include <cmath>

int ccc_win_main()
{  
   cwin.coord(0,100,100,0);

   cwin << Circle(Point(30,50),10);
   cwin << Circle(Point(60,50),10);
   cwin << Message(Point(26,50),"Shell");
   cwin << Message(Point(56,50),"Nim");

   bool Exit=false;
   while(Exit==false)
   {
     Point click=cwin.get_mouse("Click in circle for playing game.");
     int x2=click.get_x();
     int y2=click.get_y();
     
  
    if(sqrt((30-x2)*(30-x2)+(50-y2)*(50-y2))<=10)
    {
        cwin.clear();
        cwin<<Message(Point(30,50),"The Game is not availiable.");
        cwin.get_mouse("Click to continue");
        cwin.clear();
        
     }
     else if(sqrt((60-x2)*(60-x2)+(50-y2)*(50-y2))<=10) 
     {
        cwin.clear();
        cwin<<Message(Point(30,50),"The Game is not availiable.");
        cwin.get_mouse("Click to continue");
        cwin.clear();
      }   
     else
      {
        Exit=true;
	exit(0);
       } 

    cwin << Circle(Point(30,50),10);
    cwin << Circle(Point(60,50),10);
    cwin << Message(Point(26,50),"Shell");
    cwin << Message(Point(56,50),"Nim");
      
    }
     
        return 0;
}





































  
   
