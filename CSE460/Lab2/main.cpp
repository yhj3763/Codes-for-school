#include <iostream>
#include "functions.h"

using namespace std;

int main ()
{
    int array[100];
    int max;
    int size = 0;

    cout << "How big is the array? ";
    cin >> size;
    if (initialize (array, size) != 0 )
    {
        cout << "initialization error\n";
        return 1;
    }

    if (find_max (array, size,&max) != 0 )
    {
        cout << "some function error\n";
        return 1;
    }
    cout << "max value in array is: " <<max;
	cout << endl;

    return 0;
}

haha
something
something
something
