#include <iostream>
#include "SortedList.h"
#include "StudentType.h"

using namespace std;

void ListAllStudents( SortedType<StudentType>& );
void AddNewStudent( SortedType<StudentType>& );
void LookUpStudent( SortedType<StudentType>& );
void DeleteById( SortedType<StudentType>& );
void HighestGPA( SortedType<StudentType>& );
void DeleteByName( SortedType<StudentType>& );

int main()
{
	SortedType<StudentType> studentList;
	StudentType student;
	int selection = 0;
	bool quit = false;

	cout << "Student List Program, Main Menu:" << endl 
		 << "What would you like to do?" << endl
		 << "Type 1 to list all students." << endl
		 << "Type 2 to add a new student to the list." << endl
		 << "Type 3 to look up a student by ID number." << endl
		 << "Type 4 to delete a student by ID number." << endl
		 << "Type 5 to look up the student with the highest GPA." << endl
		 << "Type 6 to delete a student by name." << endl
		 << "Type 0 to quit." << endl;

	do {
		cin >> selection;
		switch (selection)
		{
			case 1: ListAllStudents(studentList);
					break;
			case 2: AddNewStudent(studentList);
					break;
			case 3: LookUpStudent(studentList);
					break;
			case 4: DeleteById(studentList);
					break;
			case 5: HighestGPA(studentList);
					break;
			case 6: DeleteByName(studentList);
					break;
			case 0: quit = true;
					break;
			default: cout << "Invalid selection." << endl;
					 break;
		}
	} while (!quit);


	return 0;
}

void ListAllStudents( SortedType<StudentType> &studentList )
{
	studentList.ResetList();
	StudentType student;

	cout << "Students:" << endl;
	cout << "---------" << endl;

	while (!studentList.AtEnd())
	{
		studentList.GetNextItem(student);
		student.Print(cout);
		/*cout << "Name: " << student.GetName() << endl;
		cout << "ID Number: " << student.GetId() << endl;
		cout << "GPA: " << student.GetGpa() << endl << endl;*/
	}

	studentList.ResetList();
}

void AddNewStudent( SortedType<StudentType> &studentList )
{
	StudentType student;
	string name;
	int id;
	float gpa;
	bool duplicate;
	StudentType same;

	cout << "Type first name: ";
	cin >> name;
	cout << "Type ID number: ";
	do {
		cin >> id;
		same.Initialize(name, id, 1.0);
		studentList.RetrieveItem(same, duplicate);
		if (duplicate)
			cout << "A student with this ID number already exists in the list. " << 
			endl << "Please enter a different ID number. " << endl;
	} while (duplicate == true);
	cout << "Type GPA: ";
	cin >> gpa;
	cout << endl << endl;

	student.Initialize(name, id, gpa);
	studentList.InsertItem(student);
}

void LookUpStudent( SortedType<StudentType> &studentList )
{
	int id;
	bool found;
	StudentType student;
	
	cout << "Enter ID number: ";
	cin >> id;
	student.Initialize("name", id, 1.0);

	studentList.RetrieveItem(student, found);
	if (found)
	{
		cout << "Student found." << endl;
		student.Print(cout);
	}
	else
		cout << "Student not found." << endl;
}

void DeleteById( SortedType<StudentType> &studentList )
{
	StudentType student;
	int id;

	cout << "Enter ID number: ";
	cin >> id;
	student.Initialize("name", id, 1.0);

	studentList.DeleteItem(student);
	cout << "Student has been deleted." << endl;
}

void HighestGPA( SortedType<StudentType> &studentList )
{
	float max = 0.0f;
	studentList.ResetList();
	bool end = studentList.AtEnd();
	StudentType student;
	SortedType<StudentType> maxList;

	while (!end)
	{
		studentList.GetNextItem(student);
		if (student.GetGpa() > max)
		{
			max = student.GetGpa();
			maxList.MakeEmpty();
			maxList.InsertItem(student);
		}
		else if (student.GetGpa() == max)
			maxList.InsertItem(student);
		end = studentList.AtEnd();
	}

	maxList.ResetList();
	cout << "Highest GPA ";
	ListAllStudents(maxList);

	//while (!end)
	//{
	//	studentList.GetNextItem(student);
	//	if (student.GetGpa() > max)
	//		max = student.GetGpa();
	//	end = studentList.AtEnd();
	//}

	//studentList.ResetList();
	//end = studentList.AtEnd();

	//while (!end)
	//{
	//	studentList.GetNextItem(student);
	//	if (student.GetGpa() == max)
	//		student.Print(cout);
	//	end = studentList.AtEnd();
	//}
}

void DeleteByName( SortedType<StudentType> &studentList )
{
	string name;
	StudentType student;
	
	cout << "Enter first name of student to be deleted: ";
	cin >> name;

	studentList.ResetList();
	bool more = !studentList.AtEnd();
	bool deleted = false;
	char answer;

	while (more && !deleted)
	{
		studentList.GetNextItem(student);
		if (name == student.GetName())
		{
			student.Print(cout);
			cout << "Is this the student you wish to delete? Y/N";
			cin >> answer;
			switch (answer)
			{
				case 'y':
				case 'Y': studentList.DeleteItem(student);
						  cout << "Student has been deleted." << endl;
						  deleted = true;
						  break;
				case 'n':
				case 'N':
				default : break;
			}
		}
		more = !studentList.AtEnd();
	}

	if (!deleted)
		cout << "Student could not be deleted because they were not in the list to begin with." << endl;
}