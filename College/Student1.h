#pragma once
#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

class Student1 :virtual public Student {
private:
	int year, coNum;
	Course** courses;
public:
	Student1(char* n, long id, int y,int size,Course **data);
	virtual bool is_outstanding()const;
	virtual const char* get_type()const { return "First"; }
	virtual const char* get_name()const { return this->name; }
	virtual long get_id()const { return this->id; }
	virtual int get_year()const { return this->year; }
	virtual int get_coNum()const { return this->coNum; }
	virtual Course** get_courses();
	virtual void add_course(Course *c);
	virtual void set_courses(Course** courses,int size);
	virtual float get_average()const;
	virtual void print()const;
	~Student1();
};