#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student1.h"
#include "Course.h"
using namespace std;

Student1::Student1(char* n, long id, int y, int size, Course** data) :Student(n, id) {
	this->year = y;
	this->courses = new Course * [size];
	this->coNum = size;
	for (int i = 0; i < this->coNum; i++) {
		char* n = new char[strlen(data[i]->get_CoName()) + 1];
		char* l = new char[strlen(data[i]->get_lecturer()) + 1];
		strcpy(n, data[i]->get_CoName());
		strcpy(l, data[i]->get_lecturer());
		this->courses[i] = new Course(n, l, data[i]->get_grade());
	}
}

Course** Student1::get_courses() {
	if (this->courses) {
		Course** courses = new Course * [this->coNum];
		for (int i = 0; i < this->coNum; i++) {
			char* tempName = new char[strlen(this->courses[i]->get_CoName()) + 1];
			char* tempLec = new char[strlen(this->courses[i]->get_lecturer()) + 1];
			strcpy(tempName, this->courses[i]->get_CoName());
			strcpy(tempLec, this->courses[i]->get_lecturer());
			courses[i] = new Course(tempName, tempLec, this->courses[i]->get_grade());
		}
		return courses;
	}
	else if (!this->courses)
		return NULL;
}

void Student1::add_course(Course* c) {
	if (!this->courses) {
		this->courses = new Course * [1];
		this->coNum = 1;
		this->courses[0] = new Course(c);
	}
	else if (this->courses) {
		this->coNum++;
		Course** temp = new Course * [this->coNum];
		for (int i = 0; i < this->coNum - 1; i++) {
			temp[i] = new Course(this->courses[i]);
		}
		delete[]this->courses;
		this->courses = new Course * [this->coNum];
		for (int i = 0; i < this->coNum - 1; i++) {
			this->courses[i] = new Course(temp[i]);
		}
		delete[]temp;
		this->courses[this->coNum - 1] = new Course(c);
	}
}

void Student1::set_courses(Course** courses, int size) {
	delete[]this->courses;
	this->coNum = size;
	this->courses = new Course * [this->coNum];
	for (int i = 0; i < this->coNum; i++) {
		this->courses[i] = new Course(courses[i]);
	}
}

bool Student1::is_outstanding()const {
	if ((this->year == 1 || this->year == 2) && this->get_average() >= 90)
		return true;
	else if ((this->year == 3 || this->year == 4) && this->get_average() >= 85)
		return true;
	return false;
}

float Student1::get_average()const {
	float average = 0;
	for (int i = 0; i < this->coNum; i++) {
		average += this->courses[i]->get_grade();
	}
	average /= this->coNum;
	return average;
}

void Student1::print()const {
	cout << "First Degree student name:" << this->name << endl
		<< "First Degree student id:" << this->id << endl
		<< "First Degree student acedemic year:" << this->year << endl;
	if (this->coNum > 0) {
		cout << "First Degree student courses details:" << endl << endl;
		for (int i = 0; i < this->coNum; i++) {
			cout << "Course number " << i + 1 << " details:" << endl
				<< "Course name:" << this->courses[i]->get_CoName() << endl
				<< "Course lecturer's name:" << this->courses[i]->get_lecturer() << endl
				<< "Course grade:" << this->courses[i]->get_grade() << endl;
		}
		cout << endl;
	}
}

Student1::~Student1() {
	delete[]this->name;
	for (int i = 0; i < this->coNum; i++) {
		delete[]this->courses[i];
	}
	delete[]this->courses;
}