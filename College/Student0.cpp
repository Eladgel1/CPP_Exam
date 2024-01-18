#include <iostream>
#include "Student0.h"
using namespace std;

Student0::Student0(char* n, long id, bool flag):Student(n,id) {
	this->is_short = flag;
}

const char* Student0::get_preparatory_type()const {
	if (this->is_short) {
		return "short";
	}
	return "long";
}

void Student0::print()const {
	cout << "Preparatory student name:" << this->name << endl
		<< "Preparatory student id:" << this->id << endl
		<< this->name << " studies in a " << get_preparatory_type() << " preparatory" << endl << endl;
}

Student0::~Student0() {
	delete[]this->name;
}