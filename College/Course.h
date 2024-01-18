#pragma once
#include <iostream>
using namespace std;

class Course {
private:
	char* name, * lecturer;
	int grade;
public:
	Course(char* n, char* l, int g);
	Course(Course* c);
	const char* get_CoName()const { return this->name; }
	const char* get_lecturer()const { return this->lecturer; }
	int get_grade()const { return this->grade; }
	void set_lecturer(char* l);
	void set_grade(int g) { this->grade = g; }
	~Course();
};