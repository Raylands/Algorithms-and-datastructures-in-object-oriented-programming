#pragma once
#include <iostream>

using namespace std;

class Student {
private:
	int ID;
	string name;
	int subject1;
	int subject2;
	int subject3;

public:
	Student(int ID, string name, int subject1, int subject2, int subject3);

	void getStudent();
	char totalMarks();
};