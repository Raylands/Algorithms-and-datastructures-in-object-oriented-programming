#include "Student.h"

Student::Student(int ID, string name, int subject1, int subject2, int subject3) 
	: ID(ID), name(name), subject1(subject1), subject2(subject2), subject3(subject3) {}

void Student::getStudent() {
	cout << "ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "First subject: " << subject1 << endl;
	cout << "Second Subject: " << subject2 << endl;
	cout << "Thrid subject: " << subject3 << endl << endl;
}

char Student::totalMarks() {
	int combined = (subject1 + subject2 + subject3) / 3;
	
	//if (combined < 40) return 'C';
	//else if (combined < 60) return 'B';
	//else if (combined >= 60) return 'A';

	return combined >= 40 ? combined >= 60 ? 'A' : 'B' : 'C';
}