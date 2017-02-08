#include <fstream>
#include <iostream>
  
using namespace std;

#include "hw1 unsortedType.h"

int main()
{

  int a = 15, b = 27, c = 384, d = 85, e = 3, f = -100, g = 1993;
  UnsortedType<int> list1, list2, list3;

  list1.InsertItem( a );
  list1.InsertItem( b );
  list1.InsertItem( c );
  cout << "list1 = ";
  list1.Print(cout);

  list2.InsertItem( d );
  list2.InsertItem( e );
  list2.InsertItem( f );
  list2.InsertItem( g );
  cout << "list2 = ";
  list2.Print(cout);

  list3 = list1.Merge( list2 );
  cout << "list1 = ";
  list1.Print(cout);
  cout << "list2 = ";
  list2.Print(cout);
  cout << "list3 = ";
  list3.Print(cout);

  list3.Split( b, list1, list2 );
  cout << "list1 = ";
  list1.Print(cout);
  cout << "list2 = ";
  list2.Print(cout);
  cout << "list3 = ";
  list3.Print(cout);

  return 0;
}
