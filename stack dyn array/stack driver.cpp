#include <iostream>
#include "StackType dyn.h"
#include <cctype>

using namespace std;

int main()
{
  char ch;
  StackType<char> cstack(20);
  StackType<char> cstackCopy(20);
  StackType<char> cstackReverse(20);

  cout << "enter string: ";
  cin.get(ch);
  while (ch != '\n' && !cstack.IsFull() )
  {
	  cstack.Push( ch );
	  if (isalpha(ch))
	  {
		  cstackCopy.Push(tolower(ch));
	  }
      cin.get(ch);
  }

  cout << "string has been placed on stack " << endl;

  cout << "in reverse = ";
  while (!cstack.IsEmpty())
  {
	  cstack.Pop( ch );
	  cout << ch;
	  if (isalpha(ch))
	  {
		  cstackReverse.Push(tolower(ch));
	  }
  }

  cout << endl;

  char ch2;
  bool equal = true;

  while (!cstackCopy.IsEmpty() && !cstackReverse.IsEmpty() && equal)
  {
	  cstackCopy.Pop(ch);
	  cstackReverse.Pop(ch2);
	  if (ch != ch2)
		  equal = false;
  }

  if (equal)
	  cout << "the phrase is a palindrome." << endl;

  else
	  cout << "the phrase is not a palindrome." << endl;

  return 0;
}

