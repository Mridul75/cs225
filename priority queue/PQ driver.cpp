#include "PQType.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct VIP
{
	string name;
	int status;
	bool operator==( VIP person2 );
	bool operator!=( VIP person2 );
	bool operator<( VIP person2 );
	bool operator<=( VIP person2 );
	bool operator>( VIP person2 );
	bool operator>=( VIP person2 );
};

int Lowest( PQType<VIP> pq );
void Print( PQType<VIP> pq );

int main()
{
  PQType<VIP> pq(10);

  VIP person1;
  int button;

  cout << "Menu: " << endl
	   << "-------------------------------" << endl
	   << "1)  add new customer to queue (prompt user for name and hotness)" << endl
	   << "2)  remove hottest customer from queue (print name and hotness)" << endl
	   << "3)  current highest hottest factor of anyone in queue (print hotness)" << endl
	   << "4)  current lowest hottest factor of anyone in queue (print hotness)" << endl
	   << "5)  print current customers in queue (table of names and hotnesses)" << endl
	   << "6)  exit" << endl;

  cin >> button;

  while (button != 6)
  {
	  switch (button)
	  {
	  case 1: cout << "Name: ";
		  cin >> person1.name;
		  cout << "Status: ";
		  cin >>  person1.status;
		  pq.Enqueue(person1);
		  cout << "Added to queue!" << endl;
		  break;
	  case 2: // remove
		  pq.Dequeue(person1);
		  cout << person1.name << ", VIP level " << person1.status << " has left the queue. " << endl;
		  break;
	  case 3: // highest
		  pq.Dequeue(person1);
		  cout << "Highest VIP level: " << person1.status << endl;
		  pq.Enqueue(person1);
		  break;
	  case 4: // lowest
		  cout << "Lowest VIP level: " << Lowest(pq) << endl;
		  break;
	  case 5: // print all
		  Print(pq);
		  break;
	  case 6: // exit
		  break;
	  default: cout << "Invalid menu item. Select again." << endl;
		  break;
	  }
	  cin >> button;
	  if (button > 6 || button < 1)
		  button = 0;
  }

  return 0;
}

bool VIP::operator==( VIP person2 )
{
	return (status == person2.status);
}

bool VIP::operator!=( VIP person2 )
{
	return (status != person2.status);
}

bool VIP::operator<( VIP person2 )
{
	return (status < person2.status);
}

bool VIP::operator>( VIP person2 )
{
	return (status > person2.status);
}

bool VIP::operator>=( VIP person2 )
{
	return (status >= person2.status);
}

bool VIP::operator<=( VIP person2 )
{
	return (status <= person2.status);
}


int Lowest( PQType<VIP> pq )
{
	VIP item;

	while (!pq.IsEmpty())
		pq.Dequeue(item);

	return item.status;
}

void Print( PQType<VIP> pq )
{
	VIP item;

	cout << setw(10) << "Name: " << setw(12) << "VIP Level: " << endl
		 << "----------  ----------" << endl;

	while (!pq.IsEmpty())
	{
		pq.Dequeue(item);
		cout << setw(10) << item.name << setw(10) << item.status << endl;
	}

	cout << endl;
}