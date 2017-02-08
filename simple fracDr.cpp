// Test driver
#include <iostream>
#include "frac.h"

using namespace std;

int main()
{
  FractionType f1, f2, f3(0,5);

  f1.Initialize(2,3);
  
  cout << "f1 = ";
  f1.Write();
  if (f1.IsZero())
	  cout << "f1 = 0" << endl;
  else
	  cout << "f1 =/= 0" << endl;
  if (f1.IsNotProper())
	  {
		  cout << "f1 is not a proper fraction." << endl;
		  cout << "As a proper fraction, f1 = " << f1.ConvertToProper() << ' ';
		  f1.Write();
		  cout << endl;
	  }
  else
	  cout << "f1 is a proper fraction." << endl << endl;




  cout << "f2 = ";
  f2.Write();
  if (f2.IsZero())
	  cout << "f2 = 0" << endl;
  else
	  cout << "f2 =/= 0" << endl;
  if (f2.IsNotProper())
	  {
		  cout << "f2 is not a proper fraction." << endl;
		  cout << "As a proper fraction, f2 = " << f2.ConvertToProper() << ' ';
		  f2.Write();
		  cout << endl;
	  }
  else
	  cout << "f2 is a proper fraction." << endl << endl;

  f2.Initialize(9,4);

  cout << "f2 = ";
  f2.Write();
  if (f2.IsZero())
	  cout << "f2 = 0" << endl;
  else
	  cout << "f2 =/= 0" << endl;
  if (f2.IsNotProper())
	  {
		  cout << "f2 is not a proper fraction." << endl;
		  cout << "As a proper fraction, f2 = " << f2.ConvertToProper() << ' ';
		  f2.Write();
		  cout << endl;
	  }
  else
	  cout << "f2 is a proper fraction." << endl << endl;



  cout << "f3 = ";
  f3.Write();
  if (f3.IsZero())
	  cout << "f3 = 0" << endl;
  else
	  cout << "f3 =/= 0" << endl;
  if (f3.IsNotProper())
	  {
		  cout << "f3 is not a proper fraction." << endl;
		  cout << "As a proper fraction, f3 = " << f3.ConvertToProper() << ' ';
		  f3.Write();
		  cout << endl;
	  }
  else
	  cout << "f3 is a proper fraction." << endl << endl;


  return 0;
}
