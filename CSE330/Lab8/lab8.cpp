#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

int hash2(int n)
{
 srand (n);
 return rand();
}

int string2int(string s)
{   
 int h=0;
 int d=1;
 for (int i=0; i<s.length(); i++)
 { 
   char x=s[i];
   h+=(x)*d;
   d=d*10;
 }
return h;
}

int main()
{
 int r;
 int n;
 int m; 

 string s;
 cout << "enter string:";
 cin >> s;
 
 

 cout<<"enter number for the size of the name space:";
 cin>> r;

 vector<int> v;

  srand(time(NULL));  
 for(int i=0;i<r;i++)
 {
    v.push_back(rand()%100);
 }

 cout<<"enter number for the size of the address space:";
 cin>> n;

 int y;
 cout<<"enter y numbr between 1~99:";
 cin>>y;
 int x;
 x=hash2(y)%n;
 vector<int> a;
 for(int i=0;i<n;i++)
 {
    a.push_back(-1);
 }

 for(int i=0;i<r;i++)
 {
    m=hash2(v[i])%n;
    if(a[m]==-1)
    {
      a[m]=i;
    }
    else
    {
      cout<<"There is a collision."<<endl;
    }

 }  

 for(int i=0; i<r;i++)
  {
     cout<<a[i]<<endl;
 
  }

  cout<<v[a[x]]<<endl;
  
 }


