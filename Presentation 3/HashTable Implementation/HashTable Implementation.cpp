#include "HashTableImpl.h"
#include "Patient.h"
#include <string>
#include <list>

#include <fstream>
#include <iostream>
using namespace std;

int maxlistlenght = 0; 
char menu();

int main()
{
	HashTable<string, Patient, CycleShiftHash> h(100);
	HashTable<string, Patient, CycleShiftHash>::Entry res;

	string s;
	Patient patient;
	char answer;
	ofstream out;
	ifstream inf("patientrecord.txt");
	if (!inf.fail())
	{
		while (!inf.eof())
		{
			inf >> patient;
			if (inf.eof()) break; // weirdness of eof
			cout << "CPR of " << patient.getName() << ": " << patient.getCPR() << endl;
			h.put(patient.getCPR(), patient);
		}
		inf.close();
	}
	out.open("patientrecord.txt", std::ios_base::app);
	do
	{
		switch (answer = menu())
		{
		case 'e':
		case 'E':
			cout << "\nEnter Patient data: ";
			patient.enterName();
			patient.enterAddresse();
			patient.enterCPR();
			patient.enterMedicalCaseHistory();
			h.put(patient.getCPR(), patient);
			out << patient;
			break;
		case 's':
		case 'S':
			cout << "\nSearch Patient - enter CPR: ";
			cin >> s;
			HashTable<string, Patient, CycleShiftHash>::Iterator p = h.begin();
			p = h.find(s);
			if (p == h.end())
				cout << endl << "Not found! " << endl;
			else
			{
				res = *p;
				patient = res.value();
				cout << endl << patient.getCPR() << endl << patient.getName() << endl << patient.getAddresse() << endl << patient.getMedicalCaseHistory() << endl << endl;
			}
			break;
		}
	} while ((answer != 'f') && (answer != 'F'));

	cout << "Max list depth " << maxlistlenght;

	system("pause");
}

char menu()
{
	char answer;
	cout << "\n\nSelect action: \n";
	cout << "Press S for search for patient by CPR\n";
	cout << "Press E for enter new patient\n";
	cout << "Press F for finish\n";
	cin >> answer;
	system("CLS");

	return answer;
}