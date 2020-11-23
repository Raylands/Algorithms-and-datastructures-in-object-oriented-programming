#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, string> a;
	a.insert(pair<int,string>(1,"a"));
	a.insert(pair<int,string>(3,"h"));
	auto p = a.find(3);
	a.erase(p);

	for (auto i : a)
		cout << i.first << " " << i.second << endl;
}
