#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> customer;
	customer.insert(pair<int, string>(1, "Marc"));
	customer.insert(pair<int, string>(2, "Ron"));
	customer.insert(pair<int, string>(3, "Iwan"));

	cout << "Customer with ID 3 is: " << customer.find(3)->second << endl;

	customer.erase(customer.find(1));

	for (auto i : customer)
		cout << i.first << " - " << i.second << endl;

	customer[3] = "Edward";

	for (auto i : customer)
		cout << i.first << " - " << i.second << endl;
}
