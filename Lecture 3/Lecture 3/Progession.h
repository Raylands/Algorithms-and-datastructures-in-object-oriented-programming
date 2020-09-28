#pragma once
#include <math.h>
#include <iostream>
#include <tuple>

using namespace std;

class Progression {
protected:
	long first;
	long current;

protected:
	virtual tuple<long, long> firstValue() { return { first, current }; };
	virtual long nextValue() = 0;

public:
	Progression(long f = 0) : first(f), current(f) {};

	void printProgression(int n) {
		cout << "First value: " << get<0>(firstValue()) << "\nSecond value:" << get<1>(firstValue()) << "\nFollowing Values:";
		for (int i = 2; i < n; i++)
		{
			cout << " " << nextValue();
		}
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
};
