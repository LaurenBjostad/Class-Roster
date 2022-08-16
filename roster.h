#pragma once
#include <string> //This header contains the standard string classes and templates in C++.
#include <iostream> // It is used as a stream of Input and Output using cin and cout.
#include <sstream> //Defines the template class std::stringstream and other supporting classes used for string manipulation.
#include <vector> //Provides functionality for std::vector, a dynamic array.
#include "student.h"
using std::count;
using std::endl;
using std::left;
using std::setw;

class Roster
{
private:
	int totalStudents = -1;
	const static int numStudents = 5;
	const static int numItems = 9;
	Student* classRosterArray[numItems];
	const string studentData[];
public:
	Roster();
	Student* getStudents(int totalStudents);
	void parseClass(string studentData);
	void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age,int daysInCourse1,int daysInCourse2,int daysInCourse3, DegreeProgram dp);
	
	//E3
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram dp);

	~Roster();
};