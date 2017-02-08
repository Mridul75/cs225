#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "hw2 SortedList.h"

const int NUM = 100;

int main()
{
	SortedType<int> list;

	srand((unsigned int) time(0));  // seed the random number generator
	// insert psuedo random values between 1 and 50
	for (int i = 1; i <= NUM; i++)
	{
		list.InsertItem( rand()%50 + 1);
	}

    cout << "original list = " << endl;
	list.Print( cout );

	list.RemoveEven();
    cout << endl << "after removing even values, list = " << endl;
	list.Print( cout );

	list.RemoveDuplicates();
    cout << endl << "after removing duplicates, list = " << endl;
	list.Print( cout );

	return 0;
}


