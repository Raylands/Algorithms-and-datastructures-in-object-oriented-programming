#pragma once
class Progression {
protected:
	long first; // first
	long current; // current value

protected:
	virtual long firstValue(); // reset
	virtual long nextValue(); // advance

public:
	Progression(long f = 0) : first(f), current(f) {}
	void printProgression(int n); 
};
