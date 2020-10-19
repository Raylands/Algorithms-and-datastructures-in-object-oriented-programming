#include "Employee.h"

int Full_Time_Employee::getSalary() { return salary; }

explicit Full_Time_Employee::operator Part_Time_Employee() const { return Part_Time_Employee(this->ID, this->name, this->salary); }


int Part_Time_Employee::getSalary() { return salary; }

explicit Part_Time_Employee::operator Full_Time_Employee() const { return Full_Time_Employee(this->ID, this->name, this->salary); }