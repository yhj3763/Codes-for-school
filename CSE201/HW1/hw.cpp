#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   double w=0, v=0, g=0; /*w=The car's stational, v= Velcity, 
                           g= Width of  the door*/
   double equation;
   int c=186000;         // The speed of light

   cout<<"Enter the stationary Width of the Car: ";
   cin>>w;

   cout<<"Enter Width of the Door: ";
   cin>>g;

   cout<<"Enter Velocity: ";
   cin>>v;
   v=v/3600;            //From mile per hour to mile per second
   cout<<endl;   

   equation=w*sqrt(1-((v*v)/(c*c)));

   if(w<g)              //If the car's stationary width < width of door.
     cout<<"Your car already fits!"<<endl;
    else                //If the car's stationary width > width of door. 
    {
       cout<<"Your car doesn't fit."<<endl<<endl;
       cout<<"Width of the Door: "<<g<<" feet"<<endl;   
       cout<<"With of the Moving Car: "<<equation<<" feet"<<endl;
  
    }
  
   return 0;
   
}
