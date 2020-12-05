#pragma once
#include <string>
using std::string;

#include "Enum.hpp"

class Client
{
private:
	unsigned int ID;
	string first_name;
	string last_name;
	Reason reason;

public:
	Client() { ; }
	Client(unsigned _ID, string _first_name, string _last_name, Reason _reason = Reason::Not_applicable) :
		ID(_ID), first_name(_first_name), last_name(_last_name), reason(_reason) { ; }
	
	string get_Name();
	string get_First_Name();
	string get_Last_Name();
	Reason get_Reason();
};
