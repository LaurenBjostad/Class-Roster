#include "roster.h"
#include <iostream> // It is used as a stream of Input and Output using cin and cout.
#include <sstream> //Defines the template class std::stringstream and other supporting classes used for string manipulation.
#include <vector> //Provides functionality for std::vector, a dynamic array



Roster::Roster()
{
}

//void Student::classRosterArray[i] = {}; //added

//void Roster::parseClass(const string studentData)
void Roster::parseClass(string row)

{
	DegreeProgram dp = DegreeProgram::SECURITY;
	if (row.back() == 'K')  dp = DegreeProgram::NETWORK;
	else if (row.back() == 'E')  dp = DegreeProgram::SOFTWARE;

	/*string tempClassArray[8];
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 8; i++)
	{
		rhs = row.find(",", lhs);
		tempClassArray[i] = row.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}*/

	//for (int i = 0; i < 4; i++)

	int lhs = 0;

	int rhs = row.find(",");
	string tempClassID = row.substr(0, rhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string tempClassFN = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string tempClassLN = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string tempClassEM = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int tempClassA = stod(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int tempClassD1 = stod(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int tempClassD2 = stod(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int tempClassD3 = stod(row.substr(lhs, rhs - lhs));

	add(tempClassID, tempClassFN, tempClassLN, tempClassEM, tempClassA, tempClassD1, tempClassD2, tempClassD3, dp);

}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,int daysInCourse1,int daysInCourse2,int daysInCourse3, DegreeProgram dp)
{
	int completionDays[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	classRosterArray[++arrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, completionDays, dp);
		
	//classRosterArray[arrayIndex] = new Student(studentID, firstName, lastName, emailAddress, age, completionDays[0], completionDays[1], completionDays[2], dp);
	//cout << "Student added to class roster on row" << arrayIndex + 1 << endl;
}
 

// that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= 4; i++)
	{
		if (classRosterArray[i]->Student::getID() == studentID)
		{
			success = true;
			Student* del = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = del;
			Roster::arrayIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " was removed" << endl;
		printAll();
	}
	else cout << "Student " << studentID << " was not found" << endl;
}

Student* Roster::getStudents(int arrayIndex)
{
	for (int i = 0; i <= 4; i++) return classRosterArray[arrayIndex];
}

//The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= 4; i++) Roster::classRosterArray[i]->print();
}

//video 15 pass in booktype? was here


//prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= 4; i++)
	{
		if (classRosterArray[i]->Student::getID() == studentID)
		{
			cout << studentID << ": ";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3.0 << endl;

		}
	} 
}

//A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= 4; i++)
	{
		string email = classRosterArray[i]->Student::getEmail();
		if (email.find('@') == string::npos)
			{
				cout << email << " - Invalid Email" << endl;
			}
		if (email.find('.') == string::npos)
		{
			cout << email << " - Invalid Email" << endl;
		}
		else if (email.find(' ') != string::npos)
		{
			cout << email << " - Invalid Email" << endl;
		}
	/*{
		string email = classRosterArray[i]->Student::getEmail();
		if (email.find('@') != string::npos || email.find('.') != string::npos || email.find(' ') == string::npos)
		cout << email << " - Invalid Email" << endl;
	}*/
	}


}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= 4; i++)
		if (classRosterArray[i]->getDegreeProgam() == dp) classRosterArray[i]->print();
}

//F5
Roster::~Roster()
{
	for (int i = 0; i < sizeof(Student::dayArraySize); i++)
	{
		cout << "Destructor called for " << classRosterArray[i]->getID() << endl;
		classRosterArray[i] = nullptr;
	}
}