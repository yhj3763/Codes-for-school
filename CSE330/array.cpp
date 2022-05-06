#include<iostream>
#include<cassert>
#include<vector>

using namespace std;

template <typename T1, typename T2>
class Snode
{
  public :
  T1 index;
  T2 data;
  Snode *lptr;
  Snode *rptr;
};

template <typename T1, typename T2>
class Mset
{ public :
  Mset();
  void add(T1 i, T2 d); 
  T2 find(T1 i);
  T2 operator[] (T1 i) {return find(i);}

  private :
  void add(Snode<T1,T2> *ptr, T1 i, T2 d);
  T2 find(Snode<T1,T2> *ptr, T1 i);
  Snode<T1,T2> *root;
  int ssize;
};

template <typename T1, typename T2>
T2 Mset<T1,T2>::find(T1 i)
{return find(root,i);
}

template <typename T1, typename T2>
T2 Mset<T1,T2>::find(Snode<T1,T2> *ptr, T1 i)
{
  if (ptr->index == i)
     {
       return ptr->data;
     }
  else
     {
       if ( i <= ptr->index )
	  { 
            return find(ptr->lptr,i);
          }
       else
	  {
            return find(ptr->rptr,i);
	  }
     }
}

template <typename T1, typename T2>
Mset<T1,T2>::Mset()
{ root=0;
  ssize=0;
}

template <typename T1, typename T2>
void Mset<T1,T2>::add(T1 i, T2 d)
{
  if (ssize==0)
     {
       Snode<T1,T2> *ptr = new Snode<T1,T2>;
       ptr->index=i;
       ptr->data=d;
       ptr->lptr=0;
       ptr->rptr=0;
       root=ptr;
      }
  else
      {
        add(root,i,d);
      }
  ssize++;
}
  
template <typename T1,typename T2>
void Mset<T1,T2>::add(Snode<T1,T2> *ptr, T1 i, T2 d)
{ 
  if (i<= ptr->index and ptr->lptr==0)
     {
       Snode<T1,T2> *nptr = new Snode<T1,T2>;
       nptr->index=i;
       nptr->data=d;
       nptr->lptr=0;
       nptr->rptr=0;
       ptr->lptr=nptr;
       return;
      }
  if (i> ptr->index and ptr->rptr==0)
     {
       Snode<T1,T2> *nptr = new Snode<T1,T2>;
       nptr->index=i;
       nptr->data=d;
       nptr->lptr=0;
       nptr->rptr=0;
       ptr->rptr=nptr;
       return;
      }
if (i<= ptr -> index)
  add(ptr->lptr,i,d);
else
  add(ptr->rptr,i,d);
}


int main()
{
 Mset<string,string> fruit;
 fruit.add("apple","pie");
 fruit.add("orange","juice");
 fruit.add("blueberry","muffin");
 cout << fruit["orange"] << endl;
}
