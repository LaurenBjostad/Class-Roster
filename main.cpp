#include "roster.h"

int main()
{	//F1
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
	std::cout << "+ Scripting & Programming - Applications +" << endl;
	std::cout << "++++++++++    LANGUAGE USED:    ++++++++++" << endl;
	std::cout << "++++++++++          C++         ++++++++++" << endl;
	std::cout << "++++++++++      STUDENT ID:     ++++++++++" << endl;
	std::cout << "++++++++++       010267626      ++++++++++" << endl;
	std::cout << "++++++++++         NAME:        ++++++++++" << endl;
	std::cout << "++++++++++    Lauren Bjostad    ++++++++++" << endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++\n" << endl;

	const string studentData[] = 
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Lauren,Bjostad,Lbjosta@wgu.edu\t,32,28,2,1,SOFTWARE"
	};
	

	const static int numStudents = 5;
	Roster classRoster;

	int i = 0;
	while (i <= 4) 
	{

		classRoster.parseClass(studentData[i]);
		cout << "Student added to class roster on row " << i + 1 << endl;
		i++;
	};
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	std::cout << "Showing all Students:\n" << endl;
	classRoster.printAll();

	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	std::cout << "Showing all Invalid emails:\n" << endl;
	classRoster.printInvalidEmails();
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	
	//Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.
	//loop through classRosterArray and for each element:
	
	std::cout << "Showing Average Amount of Days Spent on a Course:\n" << endl;
	for (int i = 0; i < 5; i++) classRoster.printAverageDaysInCourse(classRoster.getStudents(i)->getID());
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;

	std::cout << "Showing all Students in the Software Program:\n" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	std::cout << "Removing Student A3:\n" << endl;
	classRoster.remove("A3");
	
	//expected: the above line should print a message saying such a student with this ID was not found.
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++\n" << endl;
	std::cout << "Done. Destructor will run next\n" << endl;
	return 0;
}

