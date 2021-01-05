#pragma once
#include "Node.hpp"
class CircleList { // a circularly linked list
public:
	CircleList(); // constructor
	~CircleList(); // destructor
	bool empty() const; // is list empty?
	const int& front() const; // element at cursor
	const int& back() const; // element following cursor
	void advance(); // advance cursor
	void add(const int& e); // add after cursor
	void remove(); // remove node after cursor
private:
	CNode* cursor; // the cursor
};