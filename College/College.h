#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class College {
private:
	Student** data;
	int num_of_students;
public:
	College();
	virtual bool add_student();
	virtual bool add_grade(long id, char* coName, char* lecName, int g);
	virtual void print_all()const;
	virtual void print_excellent()const;
	virtual void print_by_index(int index)const;
	virtual void find_types(Student** arr, int size, int* count0, int* count1, int* count2);
	virtual int find_supervisor(char* s);
	virtual void menu();
	~College();
};