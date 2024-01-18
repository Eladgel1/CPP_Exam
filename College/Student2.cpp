#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "Student2.h"
using namespace std;

Student2::Student2(char* n, long id, char* t, char* s) :Student(n, id) {
	this->thesis = new char[strlen(t) + 1];
	this->supervisor = new char[strlen(s) + 1];
	strcpy(this->thesis, t);
	strcpy(this->supervisor, s);
}

void Student2::print()const {
	cout << "Second Degree student name:" << this->name << endl
		<< "Second Degree student id:" << this->id << endl
		<< "Second Degree student thesis:" << this->thesis << endl
		<< "Second Degree student supervisor name:" << this->supervisor << endl << endl;
}

Student2::~Student2() {
	delete[]this->name;
	delete[]this->thesis;
	delete[]this->supervisor;
}