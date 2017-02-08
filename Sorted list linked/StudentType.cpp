#include "StudentType.h"
#include <iomanip>

using namespace std;

StudentType::StudentType()
{
  name = "unknown";
  id = -1;
  gpa = -1.0f;
}

StudentType::StudentType( string n, int i, float g )
{
  name = n;
  id = i;
  gpa = g;
}

string StudentType::GetName( ) 
{
  return name;
}

int StudentType::GetId( ) 
{
  return id;
}

float StudentType::GetGpa( ) 
{
  return gpa;
}

 void StudentType::Initialize( string n, int i, float g ) 
{
  name = n;
  id = i;
  gpa = g;
}

void StudentType::Print(std::ostream& out) const 
{
  out << "name = " << name << "   id = " << id << "   gpa = " 
	  << fixed << setprecision(2) << gpa << endl;
}

bool StudentType::operator==( StudentType otherStudent )
{
	return (id == otherStudent.id);
}

bool StudentType::operator<( StudentType otherStudent )
{
	return (id < otherStudent.id);
}

bool StudentType::operator!=( StudentType otherStudent )
{
	return (!(*this == otherStudent));
}

bool StudentType::operator<=( StudentType otherStudent )
{
	return ((*this < otherStudent) || (*this == otherStudent));
}

bool StudentType::operator>( StudentType otherStudent )
{
	return (!(*this <= otherStudent));
}

bool StudentType::operator>=( StudentType otherStudent )
{
	return (!(*this < otherStudent));
}
