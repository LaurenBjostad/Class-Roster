#pragma once
#include "degree.h"
#include <iomanip> //Header providing parametric manipulators:https://cplusplus.com/reference/iomanip/ //setw
#include <iostream>// It is used as a stream of Input and Output using cin and cout.
#include <string>//This header contains the standard string classes and templates in C++.
using namespace std;


using std::count;
using std::endl;
using std::left;
using std::setw;

class Student
{
public:
	const static int dayArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int completionDays[dayArraySize];
	DegreeProgram degreeProgam;
public:
	Student();
	//Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completionDays[], DegreeProgram degreeProgam);
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completionDays[], DegreeProgram degreeProgam);
	~Student();
//getters
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgam();
//setters
	void setID(string ID);
	void setFirst(string first);
	void setLast(string last);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int completionDays[]);
	void setDegreeProgram(DegreeProgram dp);
	static void printHeader();
	void print();
};