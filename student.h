#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public: 
	static const int daysinCourseArraySize = 3;

	//Constructors
	Student();
	Student (string studentID, string firstName, string lastName, string emailAddress, 
		      int age, int daysinCourse[], DegreeProgram degreeprogram);

	//Setters
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(int daysInCourse[]); 
	void SetDegreeProgram(DegreeProgram degreeprogram);

	//Print Function
	void print(); 

	//Getters
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	//Destructor
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeprogram;

};

