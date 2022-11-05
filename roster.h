#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using std::string;
using namespace std;

class Roster {
public: 
	int lastIndex; //index in array
	int capacity; //maximum size of roster
	Student** classRosterArray; //array of pointers
	Roster(); //empty constructor
	Roster(int capacity); //capacity of roster
	void ParseThenAdd(string row); //parse the data then use add function to add the data to the array
	void add(string studentID, string firstName, string lastName, string email, int age, 
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); //sets instance variables & updates roster
	void printAll(); //prints a complete tab-separated list of student data in provided format
	bool remove(string studentID); //sets to false unless studentID found, then removes
	void printAverageDaysInCourse(string StudentID); //prints a student's average number of days in the three courses
	void printInvalidEmails(); // verifies student email and displays all invalid 
	void printByDegreeProgram(DegreeProgram degreeprogram);	//prints out student information for a degree program
	Student* GetStudent(int lastIndex);
	~Roster(); //destructor	
};

