#include "ccc_win.h"
#include <cmath>
#include <ctime>


void Shell(void);
void Mainscreen(void);
double Distance(Point p1,Point p2);


int ccc_win_main()
{	
        cwin.coord(0,100,100,0);
	Mainscreen();

        bool Exit=false;
        while(Exit==false)
        {
	 Point click=cwin.get_mouse("Click in circle for playing game.");

	 if(Distance(Point(30,50),click)<=10)
	 {
            cwin.clear();
	    Shell();
	    cwin.get_mouse("Click to continue");
            cwin.clear();
            Mainscreen();
         }

	 else if(Distance(Point(60,50),click)<=10)
	 {
            cwin.clear();
            cwin << Message(Point(20,50),"The Game is not available");
            cwin.get_mouse("Click to continue");
            cwin.clear();
	    Mainscreen();
         }

	 else
         {
          Exit==true;
	  exit(0);  
	 }   
	}
}


void Shell(void)
{
        
        int wager=cwin.get_int("Please enter amount of wager: "); 

        cwin.clear();
       
        cwin << Circle(Point(30,70), 15);
	cwin << Circle(Point(70,70), 15);
        cwin << Circle(Point(47,30), 15);
       
        int pick= time(0)%3+1;
       
        Point click=cwin.get_mouse("Click in circle for playing game.");

        if(pick==1)
        {
           if(Distance(Point(30,70),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
            }
           else if(Distance(Point(70,70),click)<=15)
            {        
              cwin << Message(Point(28,70),"Lose");
            }
           else if(Distance(Point(47,30),click)<=15)
            {
              cwin << Message(Point(28,70),"Lose");
            }
         }
        else if(pick==2)
        {
           if(Distance(Point(30,70),click)<=15)
            {           
               cwin << Message(Point(68,70),"Lose");
            }
           else if(Distance(Point(70,70),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
            }
           else if(Distance(Point(47,30),click)<=15)
            {
              cwin << Message(Point(68,70),"Lose");
            }
         }
        else if(pick==3)
        {
           if(Distance(Point(30,70),click)<=15)
            {
               cwin << Message(Point(45,30),"Lose");
            }
           else if(Distance(Point(70,70),click)<=15)
            {
               cwin << Message(Point(45,30),"Lose");
            }
           else if(Distance(Point(47,30),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
            }
         }
           
}


void Mainscreen(void)
{
	cwin << Circle(Point(30,50), 10);
	cwin << Circle(Point(60,50), 10);
	cwin << Message(Point(26,50), "Shell");
	cwin << Message(Point(56,50), "Nim");
}

double Distance(Point p1,Point p2)
{ 
    double x1=p1.get_x();
    double y1=p1.get_y();
    double x2=p2.get_x();
    double y2=p2.get_y();

   return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}



