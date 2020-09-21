#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
    Full_Time_Employee Full_time(1, "Name1", 22);
    Part_Time_Employee Part_time(2, "Name2", 15);

    cout << Full_time.getSalary() << endl;
    cout << Part_time.getSalary() << endl;

    Part_Time_Employee p2 = (Part_Time_Employee)Full_time;
    cout << p2.getSalary() << endl;
}