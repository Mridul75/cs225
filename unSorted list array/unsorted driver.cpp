#include <iostream>
#include "unsortedType.h"
  
using namespace std;

int main()
{
  UnsortedType<int> list;
  int x = 10;

  cout << "length = " << list.LengthIs() << endl;
  list.InsertItem( x );
  cout << "length = " << list.LengthIs() << endl;

  list.MakeEmpty();
  list.InsertItem(17);             // 17, 5, 12, 30, 23, 10, 8
  list.InsertItem(5);
  list.InsertItem(12);
  list.InsertItem(30);
  list.InsertItem(23);
  list.InsertItem(10);
  list.InsertItem(8);

  if (list.IsFull())
	  cout << "List is full." << endl;
  else
	  cout << "List is not full." << endl;

  cout << "This list has " << list.LengthIs() << " items." << endl;

  int breakfast = 12;
  bool found;
  list.RetrieveItem(breakfast, found);
  if (found)
	  cout << breakfast << " is in the list, and you should go get breakfast." << endl;
  else
	  cout << breakfast << " is not in the list, but you should still go get breakfast." << endl;
  
  list.InsertItem(breakfast);
  cout << breakfast << " has been inserted into the list." << endl;
  list.DeleteItem(breakfast);
  cout << breakfast << " has been deleted from the list." << endl;

  list.ResetList();
  cout << "List has been reset to the beginning." << endl;

  cout << "List: " << endl;
  int index = list.LengthIs();
  for (index; index > 0; index--)
  {
	  list.GetNextItem(breakfast);
	  cout << breakfast << endl;
	  if (list.AtEnd())
		  cout << "End of list." << endl << endl;
  }

  list.MakeEmpty();
  cout << "The list has been made empty." << endl;
  list.ResetList();
  cout << "List: " << endl;
  for (index; index > 0; index--)
  {
	  list.GetNextItem(breakfast);
	  cout << breakfast << endl;
	  if (list.AtEnd())
		  cout << "End of list." << endl << endl;
  }


  return 0;
}
