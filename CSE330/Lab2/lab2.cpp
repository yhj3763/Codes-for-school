#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void bubble(vector<int>& v)
{
	for (int i = v.size(); i > 0; i--)
          for (int j = 0; j < i; j++)
            if (v[j] > v[j+1])
              swap(v[j], v[j+1]);
}

int main()
{
	clock_t start, finish;
	srand (time(NULL));
	vector<int> v;
	int n=0;
	cout << "Enter size of input :" ;
	cin >> n;
	for (int i=0; i<n; i++)
		v.push_back(rand());
	start=clock();
	bubble(v);
	finish=clock();
	cout << "time= " << finish-start;
}
