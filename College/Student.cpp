#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(char* n, long id) {
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	this->id = id;
}

Student::~Student() {
	delete[]this->name;
}