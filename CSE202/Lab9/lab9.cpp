//homework 4
//Hyeongjun Yang
//Student ID 005897537

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Mlist
{
  public:
    Mlist();//creates the list
    T front();//returns the front of the list
    T end();//returns the end of the list
    int msize();
    bool in(T x);//returns true if x is in the list and false otherwise
    bool empty(); 
    void addfront(T entry);//add entry to the back of the list
    void addend(T entry);//add entry to the back of the list
    void addorder(T entry);//add entry to an ordered list
    void removefront();//removes the front of the list
    void removeend();//removes the back of the list
    void remove(T n);//searches the list and removes the entry with value n
    private:
    vector<T> mlist;
    void remove(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to remove value n
    void addorder(typename vector<T>::iterator ix, T n);//uses an iterator and recursion to add value n in an ordered list
};

template<class T>
Mlist<T>::Mlist()
{
}

template<class T>
int Mlist<T>::msize()
{
   return mlist.size();
}

template<class T>
T Mlist<T>::front()
{
   return *(mlist.begin());
}

template<class T>
T Mlist<T>::end()
{
   return *(--mlist.end());
}

template<class T>
bool Mlist<T>::in(T x)
{
   for(int i=0;i<mlist.size();i++)
    {
          if(mlist[i]==x)
            return true;

    }

   return false;
}
template<class T>
bool Mlist<T>::empty()
{
  if(mlist.size()==0)
   {
      return true;
   }
  return false;
}

template<class T>
void Mlist<T>::addfront(T entry)
{
   mlist.insert(mlist.begin(),entry);
}

template<class T>
void Mlist<T>::addend(T entry)
{

   mlist.push_back(entry);
}

template<class T>
void Mlist<T>::addorder(T entry)
{
    
    addorder(mlist.begin(),entry);
   
}

template<class T>
void Mlist<T>::removefront()
{
   mlist.erase(mlist.begin());
}

template<class T>
void Mlist<T>::removeend()
{
   mlist.pop_back();
}

template<class T>
void Mlist<T>::remove(T n)
{
 
 remove(mlist.begin(),n);

}

template<class T>
void Mlist<T>::addorder(typename vector<T>::iterator ix, T n)
{
   
       if(ix==mlist.end() or *ix>=n)
        {
             mlist.insert(ix,n);
	     return;
        }
       else
         addorder(++ix,n);

        
      
}


template<class T>
void Mlist<T>::remove(typename vector<T>::iterator ix, T n)
{
 
  if(ix==mlist.end())
   {
      return;
   }
   else
   {

       if(*ix==n)
         {
           mlist.erase(ix);
           remove(ix,n);
         }
       else
          remove(++ix,n);
    }
}



int main()
{
 Mlist<int> test1=Mlist<int>() ;
 test1.addfront(6);
 test1.addfront(3);
 test1.addfront(1);
 test1.addend(7);
 test1.addorder(0);
 test1.remove(7);
 cout << test1.front()<< endl;
 cout << test1.end()<< endl;
 Mlist<string> test2= Mlist<string>() ;
 test2.addfront("John");
 test2.addend("Paul");
 test2.addend("Mary");
 test2.addfront("Kate");
 test2.remove("Paul");
 cout << test2.front()<< endl;
 cout << test2.end()<< endl;
 
}
