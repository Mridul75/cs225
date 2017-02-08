#include <iostream>
#include "UnSorted.h"

using namespace std;

int main()
{
  UnSortedType<int> list;
  int x;
  bool found;

  list.InsertItem( 15 );
  list.InsertItem( 10 );
  list.InsertItem( 25 );
  list.InsertItem( 20 );

  cout << "list = ";
  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
	  cout << x << " ";
  }
  cout << endl;

  x = 10;
  list.RetrieveItem( x, found );
  if (found)
  {
	  cout << x << " was found and deleted\n";
      list.DeleteItem( x );
  }
  else 
	  cout << x << " was not found\n";

  x = 12;
  list.RetrieveItem( x, found );
  if (found)
  {
	  cout << x << " was found and deleted\n";
      list.DeleteItem( x );
  }
  else 
	  cout << x << " was not found\n";

  cout << "list = ";
  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
	  cout << x << " ";
  }
  cout << endl;

  return 0;
}


