#include <iostream>
#include <string>

using namespace std;

class StudentType 
{ 
public:

  StudentType();     // default constructor
  StudentType( string name, int id, float gpa ); 

  void Initialize( string name, int id, float gpa );
  void Print(std::ostream&) const;
  string GetName();
  int GetId();
  float GetGpa();
  bool operator==( StudentType otherStudent );
  bool operator!=( StudentType otherStudent );
  bool operator<( StudentType otherStudent );
  bool operator<=( StudentType otherStudent );
  bool operator>( StudentType otherStudent );
  bool operator>=( StudentType otherStudent );

private:
  string name;
  int      id;  // unique key
  float   gpa;
};
 
