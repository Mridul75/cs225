//****************************************************
// Driver for CS2 Homework 3: double-ended queues
// By Marissa Carson
//****************************************************

#include <iostream>
#include "hw3 DeQue.h"
#include <string>

using namespace std;

int main()
{
	cout << "This is Marissa's driver for testing double-ended queues." << endl;

	string item;
	DeQueType<string> q;

	if(q.IsEmpty())
		cout << "q is empty" << endl;
	else 
		cout << "q is not empty" << endl;

	q.EnqRear("pop");
	q.Print(cout);
	cout << q.Length() << endl;

	q.MakeEmpty();
	if(q.IsEmpty())
		cout << "q is empty" << endl;
	else 
		cout << "q is not empty" << endl;
	cout << q.Length() << endl;

	q.EnqFront("pop");
	q.DeqFront(item);
	cout << item << endl;

	q.EnqFront("pop");
	q.Print(cout);
	q.EnqRear("soda");
	q.Print(cout);
	q.EnqFront("coke");
	q.Print(cout);
	cout << q.Length() << endl;

	q.DeqRear(item);
	cout << item << endl;
	q.Print(cout);

	q.DeqFront(item);
	q.EnqRear(item);
	q.Print(cout);
	cout << q.Length() << endl;

	q.EnqFront("soda");
	q.EnqRear("soft drink");
	q.Print(cout);
	cout << q.Length() << endl;

	return 0;
}