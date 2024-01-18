#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Student0 :virtual public Student {
private:
	bool is_short;
public:
	Student0(char* n, long id, bool flag);
	virtual bool is_outstanding()const { return false; }
	virtual const char* get_name()const { return this->name; }
	virtual const char* get_type()const { return "Preparatory"; }
	virtual const char* get_preparatory_type()const;
	virtual long get_id()const { return this->id; }
	virtual void print()const;
	~Student0();
};