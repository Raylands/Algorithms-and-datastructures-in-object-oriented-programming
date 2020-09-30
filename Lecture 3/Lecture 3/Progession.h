#pragma once
#include <math.h>
#include <iostream>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

class Progression {
protected:
	long first;
	long current;

protected:
	virtual tuple<long, long> firstValue() { return { first, current }; };
	virtual long nextValue() = 0;
	virtual long nextValue(vector<long> &tmp_vec, vector<long> &current_vec, vector<long> &first_vec) = 0;

public:
	Progression(long f = 0) : first(f), current(f) {};

	void printProgression(int n) {
		vector<long> tmp_vec, current_vec, first_vec;
		cout << "First value: " << get<0>(firstValue()) << "\nSecond value:" << get<1>(firstValue()) << "\nFollowing Values:";
		for (int i = 2; i < n; i++)
		{
			cout << " " << nextValue(tmp_vec, current_vec, first_vec);
		}
		cout << endl;

		cout << endl << "First value:	";
		for (const auto& i : first_vec)
			cout << setw(5) << i << ' ';
		cout << endl << "Current value:	";
		for (const auto& i : current_vec)
			cout << setw(5) << i << ' ';
		cout << endl << "Tmp value:	";
		for (const auto& i : tmp_vec)
			cout << setw(5) << i << ' ';
		cout << endl;
	};
};


class Absolute : public Progression
{
private:
	long tmp;
public:
	Absolute(long f = 2, long c = 200) : Progression(f) { current = c; };

	long nextValue() {
		tmp = current;
		current = abs(first - current);
		first = tmp;
		return current;
	}

	long nextValue(vector<long> &tmp_vec, vector<long> &current_vec, vector<long> &first_vec) {
		tmp = current;
		current = abs(first - current);
		first = tmp;

		tmp_vec.push_back(tmp);
		current_vec.push_back(current);
		first_vec.push_back(first);

		return current;
	}
};
