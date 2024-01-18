#pragma once
#include <iostream>
using namespace std;

class Student {
protected:
	char* name;
	long id;
public:
	Student(char* n, long id);
	virtual bool is_outstanding()const = 0;
	virtual const char* get_name()const = 0;
	virtual const char* get_type()const = 0;
	virtual long get_id()const = 0;
	virtual void print()const = 0;
	~Student();
};