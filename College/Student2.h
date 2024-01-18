#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Student2 :virtual public Student {
private:
	char* thesis, * supervisor;
public:
	Student2(char* n, long id, char *t,char *s);
	virtual bool is_outstanding()const { return true; }
	virtual const char* get_type()const { return "Second"; }
	virtual const char* get_name()const { return this->name; }
	virtual const char* get_thesis()const { return this->thesis; }
	virtual const char* get_supervisor()const { return this->supervisor; }
	virtual long get_id()const { return this->id; }
	virtual void print()const;
	~Student2();
};