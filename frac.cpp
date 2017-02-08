// Implementation file for class FractionType
#include "frac.h"
#include <iostream>

int GreatestCommonDivisor( /* in */ int a, /* in */ int b );

FractionType::FractionType()
// Function: Initialize the fraction
// Pre:  None
// Post: numerator and denominator set to 1
{
  num = 1;
  denom = 1;
}

FractionType::FractionType(int numerator, int denominator)
// Function: Initialize the fraction
// Pre:  None
// Post: numerator is stored in num; denominator is stored in 
//       denom
{
  num = numerator;
  denom = denominator;
}

void FractionType::Initialize(int numerator, int denominator)
// Function: Initialize the fraction
// Pre:  None
// Post: numerator is stored in num; denominator is stored in 
//       denom
{
  num = numerator;
  denom = denominator;
}

int FractionType::NumeratorIs()
// Function: Returns the value of the numerator
// Pre:  Fraction has been initialized
// Post: numerator is returned
{
  return num;
}

int FractionType::DenominatorIs()
// Function: Returns the value of the denominator
// Pre:  Reaction has been initialized 
// Post: denominator is returned
{
  return denom;
}  

bool FractionType::IsZero()
// Function: Determines if fraction is zero
// Pre:  Fraction has been initialized
// Post: Returns true if numerator is zero
{
  return (num == 0);
}

bool FractionType::IsNotProper()
// Function: Determines if fraction is a proper fraction
// Pre:  Fraction has been initialized
// Post: Returns true if num is greater than or equal to denom
{
  return (num >= denom);
}

int FractionType::ConvertToProper()
// Function: Converts the fraction to a whole number and a 
//       fractional part
// Pre:  Fraction has been initialized, is in reduced form, and
//       is not a proper fraction
// Post: Returns num divided by denom
//       num is original num % denom; denom is not changed
{
  int result;
  result = num / denom;
  num = num % denom;
  return result;
}

int GreatestCommonDivisor( /* in */ int a,
                           /* in */ int b )
    //..................................................................
    // PRE:  a >= 0  &&  b > 0
    // POST: FCTVAL == Greatest common divisor of a and b
    //                 (Algorithm: the Euclidean algorithm)
    //..................................................................
{
    int temp = a % b;
    while (temp > 0) {  // INV (prior to test):
                        //    No integer > b evenly divides
                        //    both a<entry> and b<entry>
        a = b;
        b = temp;
        temp = a % b;
    }
    // ASSERT: b == Greatest common divisor of a<entry> and b<entry>
    return b;
}

void FractionType::Write()
// Function: Writes the fraction in the form a/b
{
	cout << num << '/' << denom << endl;
}