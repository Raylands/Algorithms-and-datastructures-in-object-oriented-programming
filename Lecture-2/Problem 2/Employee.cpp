#include "Employee.h"

Full_Time_Employee::Full_Time_Employee(int ID, string name, int salary) {
	this->ID = ID;
	this->name = name;
	this->salary = salary;
}

int Full_Time_Employee::getSalary() { return salary; }

explicit Full_Time_Employee::operator Part_Time_Employee() const { return Part_Time_Employee(this->ID, this->name, this->salary); }



Part_Time_Employee::Part_Time_Employee(int ID, string name, int salary) {
	this->ID = ID;
	this->name = name;
	this->salary = salary;
}

int Part_Time_Employee::getSalary() { return salary; }

explicit Part_Time_Employee::operator Full_Time_Employee() const { return Full_Time_Employee(this->ID, this->name, this->salary); }