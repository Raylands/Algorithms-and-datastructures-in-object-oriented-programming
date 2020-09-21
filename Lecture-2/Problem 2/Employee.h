#pragma once

#include <iostream>

using namespace std;

class Full_Time_Employee;
class Part_Time_Employee;

class Employee {
public:
	Employee(int ID, string name, int salary) : ID(ID), name(name), salary(salary);
	virtual int getSalary() = 0;
protected:
	int ID;
	string name;
	int salary;
};


class Full_Time_Employee : Employee{
public:
	Full_Time_Employee(int ID, string name, int salary) : Employee(ID, name, salary) {};
	~Full_Time_Employee() {};
	int getSalary() override;

	explicit operator Part_Time_Employee() const;
};


class Part_Time_Employee : Employee {
public:
	Part_Time_Employee(int ID, string name, int salary) : Employee(ID, name, salary) {};
	~Part_Time_Employee() {};
	int getSalary() override;

	explicit operator Full_Time_Employee() const;
};