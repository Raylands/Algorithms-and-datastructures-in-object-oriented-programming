#include "Client.hpp"

string Client::get_Name()
{
	return first_name + " " + last_name;
}

string Client::get_First_Name()
{
	return first_name;
}


string Client::get_Last_Name()
{
	return last_name;
}

Reason Client::get_Reason()
{
	return reason;
}