#pragma once
#include <math.h>
#include <iostream>

using namespace std;

class Progression {
protected:
	long first; // first
	long current; // current value

protected:
	virtual void firstValue(long f) = 0; // reset
	virtual void nextValue() = 0; // advance

public:
	Progression(long f = 0) : first(f), current(f) {};
	Progression(long f = 0, long c = 0) : first(f), current(c) {};
	void printProgression() { cout << "First Value: " << first << endl << "Current Value: " << current <<endl << endl; };
};


class Absolute : public Progression
{
public:
	Absolute(long f = 2, long c = 200) : Progression(f,c) {};
	void firstValue(long f) { first = f; };
	void nextValue() { current = abs(first - current); };
};
