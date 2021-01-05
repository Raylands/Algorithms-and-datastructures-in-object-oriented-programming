#include "Patient.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Patient::enterName() {
	cout << "\nEnter firstname: ";
	cin >> firstname;
	cout << "Enter lastname: ";
	cin >> lastname;
	cout << endl;
}
void Patient::enterAddresse() {
	cout << "Enter addresse: \n   Streetname: ";
	cin >> street;
	cout << "   Number: ";
	cin >> number;
	cout << "   Postal code: ";
	cin >> postCode;
	cout << "   City: ";
	cin >> city;
	cout << endl;
}
void Patient::enterCPR() {
	cout << "Enter CPR-number: ";
	cin >> CPRNumber;

}
void Patient::enterMedicalCaseHistory() {
	cout << "Enter Medical Case History: ";
	cin >>medicalCaseStory;
}
string Patient::getName() {
	return firstname + " " + lastname;
}
string Patient::getAddresse() {
	return street + " " + number + " \n" + to_string(postCode) + " " + city;
}

string Patient::getCPR(){
	return CPRNumber;
}
string Patient::getMedicalCaseHistory() {
	return medicalCaseStory;
}

ifstream& operator>>(ifstream & in, Patient &p)
{
	in >> p.firstname >> p.lastname >> p.CPRNumber >> p.street >> p.number >> p.postCode >> p.city >> p.medicalCaseStory;
	return in;
}
ofstream& operator<<(ofstream & out, Patient &p)
{
	out << p.firstname <<" "<< p.lastname << " " << p.CPRNumber << " " << p.street << " " << p.number << " " << p.postCode << " " << p.city << " " << p.medicalCaseStory << " ";
	return out;
}

