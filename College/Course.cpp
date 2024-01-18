#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(char* n, char* l, int g) {
	this->name = new char[strlen(n) + 1];
	this->lecturer = new char[strlen(l) + 1];
	strcpy(this->name, n);
	strcpy(this->lecturer, l);
	this->grade = g;
}

Course::Course(Course *c) {
	this->name = new char[strlen(c->name) + 1];
	this->lecturer = new char[strlen(c->lecturer) + 1];
	strcpy(this->name, c->name);
	strcpy(this->lecturer,c->lecturer);
	this->grade = c->grade;
}

void Course::set_lecturer(char* l) {
	delete[]this->lecturer;
	this->lecturer = new char [strlen(l) + 1];
	strcpy(this->lecturer, l);
}

Course::~Course() {
	delete[]this->name;
	delete[]this->lecturer;
}