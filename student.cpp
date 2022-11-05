#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student() //Empty constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysinCourseArraySize; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeprogram = DegreeProgram::UNDECLARED;
}

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string email, 
	               int age, int daysInCourse[], DegreeProgram degreeprogram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	for (int i = 0; i < daysinCourseArraySize; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeprogram = degreeprogram;
}

//Getters

string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeprogram;
}

//Setters

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmailAddress(string email) {
	this->emailAddress = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysinCourseArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeprogram){
	this->degreeprogram = degreeprogram;
}

void Student::print() {
	cout << GetStudentID() << "\t";
	cout << GetFirstName() << "\t";
	cout << GetLastName() << "\t";
	cout << GetEmailAddress() << "\t";
	cout << GetAge() << "\t";
	int* day = GetDaysInCourse();
	cout << day[0] << "\t";
	cout << day[1] << "\t";
	cout << day[2] << "\t";
	cout << degreeprogramStrings[(int)GetDegreeProgram()] << endl;
}

	//Destructor
	Student::~Student(){
		}