#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

template <typename T>
class Mvector

{
    private:
    T *v;
    int vsize;
    int vcap;
    void reserve(unsigned int n);

    public:
    Mvector();
    Mvector(unsigned int n);
    void pushback(T x);
    void popback();
    void clear();
    void insert(int i, T x);
    void erase(int i);
    T operator[](unsigned int i);
    int size();
    typedef T* iterator;
    iterator begin() {return v;}
    iterator end() {return v+vsize;}
    void insert(iterator ix,T x);
    void erase(iterator ix);
 
};

template <typename T>
Mvector<T>::Mvector()
{
    T* newv=new T[10];
    assert(newv !=NULL);
    vsize=0;
    vcap=10;
    v=newv;

}

template <typename T>
Mvector<T>::Mvector(unsigned int n)
{
    T* newv=new T[n];
    assert(newv!=NULL);
    vsize=0;
    vcap=n;
    v=newv;

}

template <typename T>
void Mvector<T>::reserve(unsigned int n)
{
    assert(n>vcap);
    T* newv=new T[n];
    for(int i=0;i<vsize;i++)
    {
        newv[i]=v[i];
    }
    delete[]v;
    v=newv;
    vcap=n;
}

template <typename T>
void Mvector<T>::popback()
{
    assert(vsize>0);
    vsize--;
}

template <typename T>
void Mvector<T>::clear()
{
    vsize=0;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{
    assert(i>=0 and i<vsize);
    return v[i];
}

template <typename T>
int Mvector<T>::size()
{
    return vsize;
}

template <typename T>
void Mvector<T>::pushback(T x)
{
    if(vsize<vcap)
    {
        v[vsize]=x;
        vsize++;
    }
    else
    {
        reserve(2*vcap);
        v[vsize]=x;
        vsize++;
    }
 
}

template <typename T>
void Mvector<T>::erase(int i)
{
    assert(i>=0 and i<vsize);
    for(int j=i;j<vsize-1;j++)
    {
        v[j]=v[j+1];
    }
    vsize--;
}

template <typename T>
void Mvector<T>::insert(int i, T x)
{
    assert(i>=0 and i<=vsize);
    if(vsize==vcap)
    {
        reserve(2*vcap);
    }
    for(int j=vsize; j>i;j--)
    {
        v[j]=v[j-1];
    }
    v[i]=x;
    vsize++;
}


template <typename T>
void Mvector<T>::insert(iterator ix,T x)
{
   assert((ix-v>=0) and (ix-v<=(++vsize)));
   int index=ix-v;
   insert(index,x);
}

template <typename T>
void Mvector<T>::erase(iterator ix)
{
  iterator ix1;
  for(ix1=ix;ix!=--(v+vsize);ix1++)
   {
      *ix1=*(++ix1);
   }
  --vsize;
}

int main()
{ Mvector<int> v;
  Mvector<int>::iterator it; 
  v.pushback(10);
  v.pushback(20);
  v.pushback(30);
  v.pushback(40);
  v.pushback(50);
  v.pushback(60);
  v.pushback(70);
  v.pushback(80);

  for (int i=0; i<v.size(); i++)
	  cout << v[i] << endl;
  cout << endl;
  cout << *(v.begin()) << endl;
  cout << *(v.end()) << endl;
  cout << *(v.begin())-*(v.end()) << endl;
  it=v.end();
  it--;
  cout << *it << endl;
  
  for (it=v.begin(); it!=v.end(); it++)
	  cout << *it  << endl;
  v.insert(it, 25);
  for (int i=0; i<v.size(); i++)
	  cout << v[i] << endl;
  cout << *(v.begin());
}

