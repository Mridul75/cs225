#include <iostream>
#include "SortedList plus.h"

using namespace std;

int countVowels( SortedType<char>/*&*/ );  // change: passed list by reference
                                       // not a real solution
int main()
{
  SortedType<char> list;
  char x;

  cout << "enter string: ";
  cin.get(x);
  while (x != '\n' )
  {
	  list.InsertItem( x );
      cin.get(x);
  }

  cout << "list = ";
  list.ResetList();
  while (!list.AtEnd())
  {
	  list.GetNextItem( x );
	  cout << x << " ";
  }
  cout << endl;

  cout << "number of vowels = " << countVowels(list) << endl;

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

int countVowels( SortedType<char> /*&*/l )
{
	int vowelCount = 0;
	char ch;

    l.ResetList();
    while (!l.AtEnd())
    {
	    l.GetNextItem( ch );
		ch = tolower(ch);
	    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		    vowelCount++;
    }

	return vowelCount;
}