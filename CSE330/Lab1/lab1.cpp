#include <iostream>

#include <unistd.h>



using namespace std;





class Time

{

public:

    Time(int h, int m);

    int gethours() const;

    int getminutes() const;

    void addminute();

    void subtractminute();

    bool operator==(Time t);

    void operator++(); //prefix

    void operator++(int); //postfix

    void operator--();

    void operator--(int);

    private :

    int hours;

    int minutes;

};



Time::Time(int h, int m)

{ hours=h;

    minutes=m;

}



int Time::gethours() const

{ return hours;

}





int Time::getminutes() const

{ return minutes;

}



bool Time::operator==(Time t)

{

    if (this->gethours() != t.gethours()) return false;

    if (this->getminutes() != t.getminutes()) return false;

    return true;

}



void Time::operator++()

{

    this -> addminute();

}



void Time::operator++(int)

{

    this -> addminute();

}

void Time::operator--()

{

    this -> subtractminute();

}



void Time::operator--(int)

{

    this -> subtractminute();

}



void Time::addminute()

{ minutes++;

    if (minutes == 60 )

    {

        minutes=0;

        hours++;

    }

    if (hours == 13)

        hours=1;

}



void Time::subtractminute()

{

    minutes--;

    if(minutes==-1)

    {

        minutes=59;

        hours--;

        

    }

    if(hours==0)

     hours=12;



        }



int main()

{

    Time start=Time(12,0);

    Time end=Time(1,15);

    while(1)

    {
        ++start; //add a minute to start

            if (start == end)

             {

                 cout << "class dismissed"<<endl;

                 break;

             }

        

    }

    Time start2=Time(1,15);

    Time end2=Time(12,0);

    while(1)

    {

        --end2;

        if (start2 == end2)

        {

            cout << "class dismissed"<<endl;

            break;

        }

        

    }

}



