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
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;

	const string studentData[] = 
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,Lauren,Bjostad,Lbjosta@wgu.edu,32,28,2,1,SOFTWARE"
	};
	

	const static int numStudents = 5;
	Roster classRoster;
	
	int i = 0;
	while (i <= 4) 
	{
		/*for (int i = 0; i < 5, i++)*/

		classRoster.parseClass(studentData[i]);//added the for loop
		cout << "Student added to class roster on row " << i + 1 << endl;
		i++;
	};
	//classRoster.parseClass(studentData);

	

	std::cout << "Showing all Students:" << endl;
	classRoster.printAll();

	std::cout << "Showing all Invalid emails:" << endl;
	classRoster.printInvalidEmails();

	
	//Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.
	//loop through classRosterArray and for each element:
	
	std::cout << "Showing Average Amount of Days Spent on a Course:" << endl;
	/*for (int i = 0; i < numStudents; i++) classRoster.printAverageDaysInCourse(classRosterArray[i]->getID());*/
	for (int i = 0; i < 5; i++) classRoster.printAverageDaysInCourse(classRoster.getStudents(i)->getID());


	std::cout << "Showing all Students in the Software Program:" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	std::cout << "Removing Student A3:" << endl;
	classRoster.remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.

	std::cout << "Done. Destructor will run next" << endl;

	return 0;
}

