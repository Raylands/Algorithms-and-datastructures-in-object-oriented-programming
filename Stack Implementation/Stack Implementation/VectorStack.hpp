#pragma once
#include <vector>

template <typename E>
class VectorStack {
public:
	VectorStack(); // constructor from capacity
	int size() const; // number of items in the stack
	bool empty() const; // is the stack empty?
	const E& top() const; // get the top element
	void push(const E& e); // push element onto stack
	void pop(); // pop the stack

private: // member data
	std::vector<E> S = {}; // vector of stack elements
	int t = -1;
};