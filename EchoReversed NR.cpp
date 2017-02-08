// Demonstrates reversing a string without recursion.

#include <iostream>

using namespace std;

const int MAX_LINE = 100;

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
  char c, line[MAX_LINE];
  int i = -1;

  cin.get( c );
  while (c != '\n')
  {
	 i++;
	 line[i] = c;
	 cin.get( c );
  }

  cout << endl;
  for (; i >=0; i--)
	 cout << line[i];
}