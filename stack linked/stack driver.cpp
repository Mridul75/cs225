#include <iostream>
#include "StackLinked.h"

using namespace std;

int main()
{
  char ch;
  StackType<char> cstack;

  cout << "enter string: ";
  cin.get(ch);
  while (ch != '\n' )
  {
	  cstack.Push( ch );
      cin.get(ch);
  }

  cout << "string has been placed on stack " << endl;

  cout << "in reverse = ";
  while (!cstack.IsEmpty())
  {
	  cstack.Pop( ch );
	  cout << ch;
  }
  cout << endl;

  return 0;
}

