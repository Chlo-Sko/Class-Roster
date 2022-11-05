#pragma once
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	cout << "C867: Scripting and Programming Applications" << ": Written in C++ by Chloe Skorpikova, Student ID: 001128673" << endl << endl;

	const string studentDataTable[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Chloe,Skorpikova,cskorpi@wgu.edu,30,6,17,5,SOFTWARE"
	};
	int numStudents = 5;

	Roster* classRoster = new Roster(numStudents);	

	for (int i = 0; i < numStudents; i++) {
		classRoster->ParseThenAdd(studentDataTable[i]);
	}

	cout << "Displaying all students:" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Displaying invalid email addresses:" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	cout << "Displaying average days in course:" << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->GetStudent(i)->GetStudentID());
	}
	cout << endl;

	cout << "Displaying by degree program:" << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster->remove("A3");
	classRoster->printAll();
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster->remove("A3");
	cout << endl;

	system("pause");

	classRoster->~Roster();

	return 0;
}