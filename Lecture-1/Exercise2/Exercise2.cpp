#include <iostream>

#include "Student.h"

using namespace std;

int main()
{
	Student s(1, "Some Name", 50, 40, 60);
	s.getStudent();
	cout << s.totalMarks();
}
