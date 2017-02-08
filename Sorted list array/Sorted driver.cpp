#include "sortedType.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  int x;

  SortedType<int> list;

  cout << "list = ";
 
  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
      cout << x << " ";
  }
  cout << endl;

  list.InsertItem( 24 );
  list.InsertItem( 58 );
  list.InsertItem( 42 );
  list.InsertItem( 12 );
  list.InsertItem( 36 );

  cout << "list = ";

  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
      cout << x << " ";
  }
  cout << endl;

  bool found;

  x = 24;
  list.RetrieveItem( x, found );
  if (found)
    list.DeleteItem( x );
  else
	cout << "not found" << endl;

  cout << "list = ";

  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
      cout << x << " ";
  }
  cout << endl;


  x = 45;
  list.RetrieveItem( x, found );
  if (found)
    list.DeleteItem( x );
  else
	cout << "not found" << endl;

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
