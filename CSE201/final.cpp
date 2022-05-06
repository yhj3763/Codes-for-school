#include "ccc_win.h"
#include <cmath>
#include <ctime>


void Shell(void);
void Mainscreen(void);
double Distance(Point p1,Point p2);
void Nim(void);
int usermove(int u, int nom);
int compmove(int c, int nom);
int winning(int nom);

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
            Nim();
            
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
       int balnce=0;
      

       bool shellagain = false;
      
       while(shellagain == false)
       {    
         int wager=cwin.get_int("Please enter amount of wager: "); 
         balnce=wager+balnce;
     
         cwin.clear();
       
         cwin << Circle(Point(30,70), 15);
	 cwin << Circle(Point(70,70), 15);
         cwin << Circle(Point(47,30), 15);         
         cwin << Message(Point(5,10), "Your balnce:");
         cwin << Message(Point(28,10), balnce);
  
       
       

           int pick= time(0)%3+1;
          Point click=cwin.get_mouse("Click in circle for playing game.");
     if(pick==1)
        {        
           if(Distance(Point(70,70),click)<=15 or Distance(Point(47,30),click)<=15)
            {        
              cwin << Message(Point(28,70),"Lose");
              wager=0;
              cwin.get_mouse("Click to continue"); 
              cwin.clear();
          
            }
           else if(Distance(Point(30,70),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
              balnce = balnce*2;
              cwin.get_mouse("Click to continue"); 
              cwin.clear();
        
            }
           else 
            {
               shellagain = true;
               cwin.clear();
               cwin.get_mouse("Click to continue");
               Mainscreen();
            }             
         }
        else if(pick==2)
        {
           if(Distance(Point(30,70),click)<=15 or Distance(Point(47,30),click)<=15)
            {           
               cwin << Message(Point(68,70),"Lose");
               wager=0;
               cwin.get_mouse("Click to continue");
               cwin.clear();
     
            }
           else if(Distance(Point(70,70),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
              balnce = balnce*2;
              cwin.get_mouse("Click to continue");
              cwin.clear();
            
            }
           else 
            {
               shellagain = true;
               cwin.clear();
               cwin.get_mouse("Click to continue");
               Mainscreen();
               
            }
         }
        else if(pick==3)
        {
           if(Distance(Point(30,70),click)<=15 or Distance(Point(70,70),click)<=15)
            {
               cwin << Message(Point(45,30),"Lose");
               cwin.get_mouse("Click to continue");
               wager=0;
               cwin.clear();
               
            }
           else if(Distance(Point(47,30),click)<=15)
            {
              cwin.clear();
              cwin << Message(Point(40,50), "You win!!!");
              balnce = balnce*2;
              cwin.get_mouse("Click to continue");
              cwin.clear();
              
            }
           else 
            {
               shellagain = true;
               cwin.clear();
               cwin.get_mouse("Click to continue"); 
               Mainscreen();
            }
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

void Nim() //Nim game
{
   int nom=cwin.get_int("Enter the number of matches: ");
   int win=nom;
   int t=time(0)%2+1;
   int c=time(0)%3+1;
 
   bool firstturn=true;
       if(t==1)     
       {
          firstturn=true;        
       }
       else if(t==2)
       {
          firstturn=false;
       }

  while(nom>1)
   {
     //usermove
    
    if(firstturn==true) 
     {
           if(nom<=4)
           {
             
             cwin.clear();
             cwin<<Message(Point(10,50),"You can win by putting this number: ");
             cwin<<Message(Point(80,50),winning(nom)); 
             cwin.get_mouse("click to countinue");     
           }


          int u=cwin.get_int("Please enter number one of 1 to 3 for your move: ");
     
        while(u<1 or u>3)
        {     
         u=cwin.get_int("Please enter number one of 1 to 3 for your move: ");
        }      
      
            nom=usermove(u,nom);
        
           if(nom==1)
           {
             cwin.clear();
             cwin<<Message(Point(50,50),"You win");
             cwin.get_mouse("Click to continue");
             cwin.clear();
	     return Mainscreen();
           }
       
         cwin.clear();
         cwin<<Message(Point(20,50),"Now, the number of mathces is: ");
         cwin<<Message(Point(80,50),nom);
         cwin.get_mouse("It is computer's turn");       
        
       } 
    firstturn=false;
  
  if(firstturn==false)
     {
         // computermove
     
        if(win==nom)
         {
            nom=nom-(nom-1)%4;  //winning strategy
            
             if(nom<=4)
              { 
                nom=nom-winning(nom); 
              }
         }
        else  
         {
           if(nom<=4)
            {
              nom=nom-winning(nom); 
            }
           else
            {
              nom=compmove(c,nom);
            }
         }

       if(nom==1)
        {
          cwin.clear();
          cwin<<Message(Point(50,50),"You lose");
          cwin.get_mouse("Click to continue");
          cwin.clear();
	  return Mainscreen();
        }
   
       cwin.clear();
       cwin<<Message(Point(20,50),"Now, the number of mathces is: ");
       cwin<<Message(Point(80,50),nom);
       cwin.get_mouse("It is your's turn");
     }
    firstturn=true; 
   }

}

int usermove(int u, int nom)
{

   if(u==3)
    {
      return nom-3;
    }
   else if(u==2)
    {
      return nom-2;
    }
   else
    {
      return nom-1;
    }

}

int compmove(int c, int nom)
{ 
   if(c==3)
    {
      return nom-3;
    }
   else if(c==2)
    {
      return nom-2;
    }
   else
    {
      return nom-1;
    }

}

int winning(int nom)
{
    if(nom==4)
     {
       return 3;
     }
    if(nom==3)
     {
       return 2;
     }
    if(nom==2)
     {
       return 1;
     }

}

