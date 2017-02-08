#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "hw2 SortedList.h"

const int NUM = 100;

int main()
{
	SortedType<int> list;
	ofstream outData("list.text");

	srand((unsigned int) time(0));  // seed the random number generator
	// insert psuedo random values between 1 and 50
	for (int i = 1; i <= NUM; i++)
	{
		list.InsertItem( rand()%50 + 1);
	}

    outData << "original list = " << endl;
	list.Print( outData );

	list.RemoveEven();
    outData << endl << "after removing even values, list = " << endl;
	list.Print( outData );

	list.RemoveDuplicates();
    outData << endl << "after removing duplicates, list = " << endl;
	list.Print( outData );

	return 0;
}


