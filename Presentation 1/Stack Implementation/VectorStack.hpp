#pragma once
#include <vector>

template <typename E>
class VectorStack {
public:
	VectorStack();			// constructor from capacity
	int size() const;		// number of items in the stack
	bool empty() const;		// is the stack empty?
	const E& top() const;	// get the top element
	void push(const E& e);	// push element onto stack
	void pop();				// pop the stack

private: // member data
	std::vector<E> S = {};	// vector of stack elements
};

template <typename E>
VectorStack<E>::VectorStack() { ; } // constructor from capacity

template <typename E>	// number of items in the stack
int VectorStack<E>::size() const {
	return (S.size());
} 

template <typename E>	// is the stack empty?
bool VectorStack<E>::empty() const {
	return (S.empty());
} 

template <typename E>	// return top of stack
const E& VectorStack<E>::top() const {
	return S.back();
}

template <typename E>	// push element onto the stack
void VectorStack<E>::push(const E& e) {
	S.push_back(e);
}

template <typename E>	// pop the stack
void VectorStack<E>::pop() {
	if (!S.empty()) {
		S.erase(S.end()-1);
	}
}