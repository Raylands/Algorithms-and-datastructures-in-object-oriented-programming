#pragma once
#include "CircleList.hpp"
class LinkedQueue { // queue as doubly linked list
public:
	LinkedQueue(); // constructor
	int size() const; // number of items in the queue
	bool empty() const; // is the queue empty?
	const int& front() const; // the front element
	void enqueue(const int& e); // enqueue element at rear
	void dequeue(); // dequeue element at front
private: // member data
	CircleList C; // circular list of elements
	int n; // number of elements
};
