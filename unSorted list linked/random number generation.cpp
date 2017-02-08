#include <iostream>
#include <time.h>

using namespace std;

int main()
{
  srand((unsigned int) time(0));    // set the random number generator seed

  for (int i = 1; i<=50; i++)
  {
    cout << "A random number between 1 and 10 is " << 1 + rand() % 10 << endl;  // generate a random number
  }

  return 0;
}