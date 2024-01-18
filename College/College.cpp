#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "Student0.h"
#include "Student1.h"
#include "Student2.h"
#include "College.h"
using namespace std;

College::College() {
	this->data = NULL;
	this->num_of_students = 0;
}

bool College::add_student() {
	Student** temp = NULL;
	int type, choice, year;
	long id;
	char stName[20], thesis[20], supervisor[20];
	cout << "Enter student id:";
	cin >> id;
	cout << endl;
	if (!this->data) {
		cout << "Enter new student details:" << endl << endl;
		this->num_of_students = 1;
		this->data = new Student * [1];
		cout << "Enter student name:";
		cin >> stName;
		cout << endl;
		cout << "Select student type:" << endl << endl << "1 - Preparatory Student" << endl << "2 - First Degree Student" << endl << "3 - Second Degree Student" << endl << endl;
		cin >> type;
		cout << endl;
		if (type == 1) {
			cout << "Select kind of preparatory:" << endl << endl << "1 - Short Preparatory" << endl << "2 - Long Preparatory" << endl << endl;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				this->data[0] = new Student0(stName, id, true);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[0]->print();
				return true;
			}
			if (choice == 2) {
				this->data[0] = new Student0(stName, id, false);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[0]->print();
				return true;
			}
			if (choice < 1 || choice>2) {
				cout << "Invalid input,try again" << endl << endl;
				return false;
			}
		}
		if (type == 2) {
			cout << "Enter first degree student academic year:";
			cin >> year;
			cout << endl;
			if (year < 1 || year>4) {
				cout << "Invalid input,try again" << endl;
				return false;
			}
			else {
				this->data[0] = new Student1(stName, id, year, 0, NULL);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[0]->print();
				return true;
			}
		}
		if (type == 3) {
			cout << "Enter second degree student thesis subject and supervisor name:";
			cin >> thesis >> supervisor;
			cout << endl;
			this->data[0] = new Student2(stName, id, thesis, supervisor);
			cout << "Student Added Successfully!" << endl << endl;
			this->data[0]->print();
			return true;
		}
		if (type < 1 || type>3) {
			cout << "Invalid input,try again" << endl << endl;
			return false;
		}
	}
	else if (this->data) {
		for (int i = 0; i < this->num_of_students; i++) {
			if (this->data[i]->get_id() == id) {
				cout << "There is already a student with this ID" << endl << endl;
				return false;
			}
		}
		temp = new Student * [this->num_of_students];
		char* tempName;
		for (int i = 0; i < this->num_of_students; i++) {
			if (this->data[i]->get_type() == "Preparatory") {
				tempName = new char[strlen(this->data[i]->get_name()) + 1];
				strcpy(tempName, this->data[i]->get_name());
				temp[i] = new Student0(tempName, this->data[i]->get_id(), dynamic_cast<Student0*>(data[i])->get_preparatory_type());
			}
			if (this->data[i]->get_type() == "First") {
				tempName = new char[strlen(this->data[i]->get_name()) + 1];
				strcpy(tempName, this->data[i]->get_name());
				temp[i] = new Student1(tempName, this->data[i]->get_id(), dynamic_cast<Student1*>(this->data[i])->get_year(), dynamic_cast<Student1*>(this->data[i])->get_coNum(), dynamic_cast<Student1*>(data[i])->get_courses());
			}
			if (this->data[i]->get_type() == "Second") {
				tempName = new char[strlen(this->data[i]->get_name()) + 1];
				char* tempThesis = new char[strlen(dynamic_cast<Student2*>(this->data[i])->get_thesis()) + 1];
				char* tempSupervisor = new char[strlen(dynamic_cast<Student2*>(data[i])->get_supervisor()) + 1];
				strcpy(tempName, this->data[i]->get_name());
				strcpy(tempThesis, dynamic_cast<Student2*>(data[i])->get_thesis());
				strcpy(tempSupervisor, dynamic_cast<Student2*>(data[i])->get_supervisor());
				temp[i] = new Student2(tempName, this->data[i]->get_id(), tempThesis, tempSupervisor);
			}
		}
		delete[]this->data;
		this->num_of_students++;
		this->data = new Student * [this->num_of_students];
		for (int i = 0; i < (this->num_of_students - 1); i++) {
			if (temp[i]->get_type() == "Preparatory") {
				tempName = new char[strlen(temp[i]->get_name()) + 1];
				strcpy(tempName, temp[i]->get_name());
				this->data[i] = new Student0(tempName, temp[i]->get_id(), dynamic_cast<Student0*>(temp[i])->get_preparatory_type());
			}
			if (temp[i]->get_type() == "First") {
				tempName = new char[strlen(temp[i]->get_name()) + 1];
				strcpy(tempName, temp[i]->get_name());
				this->data[i] = new Student1(tempName, temp[i]->get_id(), dynamic_cast<Student1*>(temp[i])->get_year(), dynamic_cast<Student1*>(temp[i])->get_coNum(), dynamic_cast<Student1*>(temp[i])->get_courses());
			}
			if (temp[i]->get_type() == "Second") {
				tempName = new char[strlen(temp[i]->get_name()) + 1];
				char* tempThesis = new char[strlen(dynamic_cast<Student2*>(temp[i])->get_thesis()) + 1];
				char* tempSupervisor = new char[strlen(dynamic_cast<Student2*>(temp[i])->get_supervisor()) + 1];
				strcpy(tempName, temp[i]->get_name());
				strcpy(tempThesis, dynamic_cast<Student2*>(temp[i])->get_thesis());
				strcpy(tempSupervisor, dynamic_cast<Student2*>(temp[i])->get_supervisor());
				this->data[i] = new Student2(tempName, temp[i]->get_id(), tempThesis, tempSupervisor);
			}
		}
		cout << "Enter new student details:" << endl << endl << "Enter student name:";
		cin >> stName;
		cout << endl;
		cout << "Select student type:" << endl << endl << "1 - Preparatory Student" << endl << "2 - First Degree Student" << endl << "3 - Second Degree Student" << endl << endl;
		cin >> type;
		cout << endl;
		int tempIndex = this->num_of_students - 1;
		if (type == 1) {
			cout << "Select kind of preparatory:" << endl << endl << "1 - Short Preparatory" << endl << "2 - Long Preparatory" << endl << endl;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				this->data[tempIndex] = new Student0(stName, id, true);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[tempIndex]->print();
				return true;
			}
			if (choice == 2) {
				this->data[tempIndex] = new Student0(stName, id, false);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[tempIndex]->print();
				return true;
			}
			if (choice < 1 || choice>2) {
				cout << "Invalid input,try again" << endl << endl;
				return false;
			}
		}
		if (type == 2) {
			cout << "Enter first degree student academic year:";
			cin >> year;
			cout << endl;
			if (year < 1 || year>4) {
				cout << "Invalid input,try again" << endl;
				return false;
			}
			else {
				this->data[tempIndex] = new Student1(stName, id, year, 0, NULL);
				cout << "Student Added Successfully!" << endl << endl;
				this->data[tempIndex]->print();
				return true;
			}
		}
		if (type == 3) {
			cout << "Enter second degree student thesis subject and supervisor name:";
			cin >> thesis >> supervisor;
			cout << endl;
			this->data[tempIndex] = new Student2(stName, id, thesis, supervisor);
			cout << "Student Added Successfully!" << endl << endl;
			this->data[tempIndex]->print();
			return true;
		}
		if (type < 1 || type>3) {
			cout << "Invalid input,try again" << endl << endl;
			return false;
		}
	}
}

bool College::add_grade(long id, char* coName, char* lecName, int g) {
	for (int i = 0; i < this->num_of_students; i++) {
		if (this->data[i]->get_type() == "First") {
			if (g >= 0 && g <= 100) {
				if (dynamic_cast<Student1*>(this->data[i])) {
					if (dynamic_cast<Student1*>(this->data[i])->get_id() == id) {
						int num_of_courses = dynamic_cast<Student1*>(data[i])->get_coNum();
						Course** courses = dynamic_cast<Student1*>(this->data[i])->get_courses();
						for (int j = 0; j < num_of_courses; j++) {
							if (strcmp(courses[j]->get_CoName(), coName) == 0) {
								courses[j]->set_lecturer(lecName);
								courses[j]->set_grade(g);
								if (dynamic_cast<Student1*>(this->data[i])) {
									dynamic_cast<Student1*>(this->data[i])->set_courses(courses, num_of_courses);
									return true;
								}
							}
						}
						Course* c = new Course(coName, lecName, g);
						dynamic_cast<Student1*>(this->data[i])->add_course(c);
						return true;
					}
				}
			}
		}
	}
	cout << "There is no first degree student with this ID" << endl << endl;
	return false;
}

void College::print_all()const {
	cout << "All Students Details:" << endl << endl;
	for (int i = 0; i < this->num_of_students; i++) {
		this->data[i]->print();
		if (this->data[i]->get_type() == "First") {
			if (dynamic_cast<Student1*>(this->data[i])) {
				cout << "First Degree Student Average:" << dynamic_cast<Student1*>(this->data[i])->get_average() << endl << endl;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
}

void College::print_excellent()const {
	cout << "All outstanding students names and ID's:" << endl << endl;
	for (int i = 0; i < this->num_of_students; i++) {
		if (this->data[i]->is_outstanding()) {
			cout << this->data[i]->get_name() << " - " << this->data[i]->get_id() << endl;
		}
	}
	cout << endl << endl;
}

void College::print_by_index(int index)const {
	cout << "Details of student number " << index + 1 << ":" << endl << endl;
	this->data[index]->print();
	if (this->data[index]->get_type() == "First") {
		if (dynamic_cast<Student1*>(this->data[index])) {
			cout << "First Degree Student Average:" << dynamic_cast<Student1*>(this->data[index])->get_average() << endl;
		}
	}
	cout << endl;
}

void College::find_types(Student** arr, int size, int* count0, int* count1, int* count2) {
	(*count0) = (*count1) = (*count2) = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i]->get_type() == "Preparatory")
			(*count0)++;
		if (arr[i]->get_type() == "First")
			(*count1)++;
		if (arr[i]->get_type() == "Second")
			(*count2)++;
	}
}

int College::find_supervisor(char* s) {
	int countS = 0;
	for (int i = 0; i < this->num_of_students; i++) {
		if (dynamic_cast<Student2*>(this->data[i])) {
			if (strcmp(dynamic_cast<Student2*>(this->data[i])->get_supervisor(), s) == 0) {
				cout << this->data[i]->get_name() << " learn at " << s << " supervisor" << endl;
				countS++;
			}
		}
	}
	return countS;
}

void College::menu() {
	int choice, index, grade, count0, count1, count2, countS;
	bool flag = false;
	long id;
	char coName[20], LecName[20], supervisor[20];
	cout << "Welcome to SCE college,choose one of the options below:" << endl << endl;
	while (true) {
		cout << "1 - Add student" << endl
			<< "2 - Add grade" << endl
			<< "3 - Print all" << endl
			<< "4 - Print excellent" << endl
			<< "5 - Print student by index" << endl
			<< "6 - Types of student" << endl
			<< "7 - Supervisor" << endl
			<< "8 - Quit" << endl << endl;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			flag = this->add_student();
			if (flag) {
				cout << endl << "Adding the student was successful!" << endl << endl;
			}
			else if (!flag) {
				cout << endl << "Adding the student was not successful" << endl << endl;
			}
			break;
		case 2:
			if (!this->data) {
				cout << "There are no students at the college,try another action" << endl << endl;
				continue;
			}
			cout << "Please enter student ID,course name,lecturer name and grade you like to add:" << endl << endl;
			cin >> id >> coName >> LecName >> grade;
			cout << endl;
			flag = this->add_grade(id, coName, LecName, grade);
			if (flag) {
				cout << endl << "Adding the grade was successful!" << endl << endl;
			}
			else if (!flag) {
				cout << endl << "Adding the grade was not successful" << endl << endl;
			}
			break;
		case 3:
			if (!this->data) {
				cout << "There are no students at the college,try another action" << endl << endl;
				continue;
			}
			this->print_all();
			break;
		case 4:
			if (!this->data) {
				cout << "There are no students at the college,try another action" << endl << endl;
				continue;
			}
			this->print_excellent();
			break;
		case 5:
			if (!this->data) {
				cout << "There are no students at the college,try another action" << endl << endl;
				continue;
			}
			cout << "Select an index of a student you would like to see is/her details :" << endl << endl;
			cin >> index;
			cout << endl;
			if (index < 0 || index >= this->num_of_students) {
				cout << "Invalid index input,try again" << endl << endl;
				continue;
			}
			this->print_by_index(index);
			break;
		case 6:
			this->find_types(this->data, this->num_of_students, &count0, &count1, &count2);
			cout << endl << "There are " << count0 << " preparatory students, " << count1 << " first degree students,and " << count2 << " second degree students" << endl << endl;
			break;
		case 7:
			if (!this->data) {
				cout << "There are no students at the college,try another action" << endl << endl;
				continue;
			}
			cout << "Please enter supervisor name:";
			cin >> supervisor;
			cout << endl;
			countS = find_supervisor(supervisor);
			cout << endl << endl;
			cout << "there are " << countS << " students that learn at " << supervisor << endl << endl;
			break;
		case 8:
			cout << "Goodbye" << endl;
			exit(1);
			break;
		default:
			cout << "Invalid input,try again" << endl << endl;
			continue;
		}
	}
}

College::~College() {
	for (int i = 0; i < this->num_of_students; i++) {
		delete[]this->data[i];
	}
	delete[]this->data;
}