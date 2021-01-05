#include <string>
#include <iostream>

using namespace std;
class Patient
{
public:
	void enterName();
	void enterAddresse();
	void enterCPR();
	void enterMedicalCaseHistory();
	string getName();
	string getAddresse();
	string getCPR();
	string getMedicalCaseHistory();

private:
	string firstname;
	string lastname;
	string CPRNumber;
	string street;
	string number;
	int	postCode;
	string city;
	string medicalCaseStory;
	friend ifstream& operator>>(ifstream & in, Patient& p);
	friend ofstream& operator<<(ofstream & out, Patient &p);

};