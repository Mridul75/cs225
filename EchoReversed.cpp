#include <iostream>

using namespace std;

void EchoReversed();

int main( void )
{
  cout << "enter string: ";

  EchoReversed();

  cout << endl;

  return 0;
}

void EchoReversed()
{
  char c;

  cin.get( c );

  if (c =='\n')
	 cout << endl;
  else
  {
	 EchoReversed();
	 cout << c;
  }
}