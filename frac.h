using namespace std;

class FractionType
{
public:
  FractionType();   // default constructor
  // Function: Initialize the fraction
  // Pre:  None
  // Post: Fraction is initialized

  FractionType(int numerator, int denominator);
  // Function: Initialize the fraction
  // Pre:  None
  // Post: Fraction is initialized to numerator and denominator

  void Initialize(int numerator, int denominator);
  // Function: Initialize the fraction
  // Pre:  None
  // Post: Fraction is initialized to numerator and denominator

  int NumeratorIs();
  // Function: Returns the value of the numerator
  // Pre:  Fraction has been initialized
  // Post: numerator is returned

  int DenominatorIs();
  // Function: Returns the value of the denominator
  // Pre:  Reaction has been initialized 
  // Post: denominator is returned

  bool IsZero();
  // Function: Determines if fraction is zero
  // Pre:  Fraction has been initialized
  // Post: Returns true if numerator is zero

  bool IsNotProper();
  // Function: Determines if fraction is a proper fraction
  // Pre:  Fraction has been initialized
  // Post: Returns true if fraction is greater than or equal to one

  int ConvertToProper();
  // Function: Converts the fraction to a whole number and a 
  //       fractional part
  // Pre:  Fraction has been initialized, is in reduced form, and  
  //       is not a proper fraction
  // Post: Returns whole number
  //       Remaining fraction is original fraction minus the
  //       whole number; fraction is in reduced form 

  void Write();
  // Function: Writes the fraction in the form a/b

private:
  int num;
  int denom;
};
