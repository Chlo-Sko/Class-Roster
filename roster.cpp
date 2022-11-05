#pragma once
#include <string>
#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

Roster::Roster() { //empty constructor;
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
Roster::Roster(int capacity) {//Sets max capacity for roster;
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::ParseThenAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex++;
	}

		int rhs = row.find(',');
		string studentID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(',', lhs);
		string firstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(',', lhs);
		string lastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string tempAge = row.substr(lhs, rhs - lhs);
		int age = stoi(tempAge);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		DegreeProgram degreeprogram;
		string tempDegree = row.substr(lhs, rhs - lhs);
		if (tempDegree == "NETWORK") {
			degreeprogram = DegreeProgram::NETWORK;
		}
		else if (tempDegree == "SECURITY") {
			degreeprogram = DegreeProgram::SECURITY;
		}
		else if (tempDegree == "SOFTWARE") {
			degreeprogram = DegreeProgram::SOFTWARE;
		}
		add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
}

void Roster::printAll() {
	for (int i = 0; i <= lastIndex; ++i) {
		classRosterArray[i]->print(); 
	}
}

bool Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < lastIndex; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) //student found
		{
			found = true;
			delete this->classRosterArray[i];
			cout << "Student with ID " << studentID << " was removed. Please see below: " << endl;
			classRosterArray[i] = classRosterArray[lastIndex];
			lastIndex--;
		}
	}
		if (!found) {
			cout << "Error! Student with ID " << studentID << " not found." << endl;
		}
	return found;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int averageDays = 0;

	for (int i = 0; i < 5; ++i) {
		string currentStudent = classRosterArray[i]->GetStudentID();
		if (currentStudent == studentID) {
			averageDays = ((classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1]
				+ classRosterArray[i]->GetDaysInCourse()[2]) / 3);
			cout << "Average days in course for " << studentID << " is: " << averageDays << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string tempEmail = classRosterArray[i]->GetEmailAddress();
		if ((tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) || (tempEmail.find(" ") != string::npos)) {
			cout << tempEmail << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram tempDegree = classRosterArray[i]->GetDegreeProgram();
		if (tempDegree == degreeprogram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string email, 
				int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[Student::daysinCourseArraySize];

	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

Student* Roster::GetStudent(int lastIndex) {
	return classRosterArray[lastIndex];
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}

