#include <iostream>
#include "StudentType.h"

using namespace std;

int main()
{
  StudentType x( "Barack Obama", 123, 3.75 );
  StudentType y;

  x.Print( cout );
  y.Print( cout );

  y.Initialize( "Michelle Obama", 321, 4.00 );
  y.Print( cout );

  if (x == y)
	  cout << "same" << endl;
  else
	  cout << "different" << endl;

  if (x == x)
	  cout << "same" << endl;
  else
	  cout << "different" << endl;

  return 0;
}


