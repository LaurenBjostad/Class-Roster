#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age;
	for (int i = 0; i < dayArraySize; i++) this->completionDays[i] = 0;
	this->degreeProgam = DegreeProgram::SECURITY;
}
//Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completionDays[], DegreeProgram degreeProgam);
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int completionDays[], DegreeProgram degreeProgam)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) this->completionDays[i] = completionDays[i];
	this->degreeProgam = degreeProgam;
}
Student::~Student() {}
//getters//
string Student::getID() { return this->studentID; }
string Student::getFirst() { return this->firstName; }
string Student::getLast() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->completionDays; }
DegreeProgram Student::getDegreeProgam() { return this->degreeProgam; }
//setters//
void Student::setID(string ID) { this->studentID = studentID; }
void Student::setFirst(string first) { this->firstName = firstName; }
void Student::setLast(string last) { this->lastName = lastName; }
void Student::setEmail(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age; }
void Student::setDays(int completionDays[])
{
	for (int i = 0; i < 3; i++) this->completionDays[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgam) { this->degreeProgam = degreeProgam;}

void Student::printHeader()
{
	std::cout << "Student ID\t";
	std::cout << "First Name\t";
	std::cout << "Last Name\t";
	std::cout << "Email\t";
	std::cout << "Age\t";
	std::cout << "Days in Course1\t";
	std::cout << "Days in Course2\t";
	std::cout << "Days in Course3\t";
	std::cout << "Degree Program\t";
	std::cout << endl;
}
void Student::print()
{
	std::cout << this->studentID << "\t";
	std::cout << this->firstName << "\t";
	std::cout << this->lastName << "\t";
	std::cout << this->emailAddress << "\t";
	std::cout << this->age << "\t";
	std::cout << this->completionDays[0] << "\t";
	std::cout << this->completionDays[1] << "\t";
	std::cout << this->completionDays[2] << "\t";
	std::cout << degreeProgamStrings[(int)this->degreeProgam];
	std::cout << endl;
}