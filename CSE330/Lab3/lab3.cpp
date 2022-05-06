#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

template <typename T>
class PQ
{
  public:
    PQ();
    PQ(vector<T> v);
    int getsize();
    T getfront();
    void print();
    void add(T x);
    void fremove();

  private:
    vector<T> pq; 
    void sort();

};

template <typename T>
PQ<T>::PQ()
{  
}

template <typename T>
PQ<T>::PQ(vector<T> v)
{
   pq=v;
   sort();   
}

template <typename T>
void PQ<T>::sort()
{
  for (int i = 0; i < pq.size()-1; i++)
    for (int j = i+1; j < pq.size(); j++)
      {
           if (pq[i] > pq[j])
            swap(pq[i], pq[j]);
      }
}

template <typename T>
int PQ<T>::getsize()
{
  return pq.size();
}

template <typename T>
T PQ<T>::getfront()
{
  return pq[0];
}

template <typename T>
void PQ<T>::print()
{
   for(int i=0;i<pq.size();i++)
    {
       cout<<pq[i]<<endl;
    }
}

template <typename T>
void PQ<T>::add(T x)
{
  typename vector<T>::iterator it=pq.begin();
   while(it!=pq.end() and x>*it)
   {
     it++;
   }
  pq.insert(it,x);
}

template <typename T>
void PQ<T>::fremove()
{
    
    pq.erase(pq.begin());
}

int main()
{
    
    srand(time(NULL));
    vector<int> v;
    int n=0;
    cout<<"Enter size for vector:";
    cin>>n;
    for(int i=0;i<n;i++)
     { 
        v.push_back(rand());
     }
 
    PQ<int> p=PQ<int>(v);

    p.print();
    p.fremove();
    p.add(5);
    p.print();
    
    
    cout<<p.getfront()<<endl;
    cout<<p.getsize()<<endl;
   


}

