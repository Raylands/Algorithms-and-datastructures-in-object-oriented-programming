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

template <typename E>
VectorStack<E>::VectorStack() { ; } // constructor from capacity

template <typename E>
int VectorStack<E>::size() const {
	return (t);
} // number of items in the stack

template <typename E> bool VectorStack<E>::empty() const {
	return (t > -1);
} // is the stack empty?

template <typename E> // return top of stack
const E& VectorStack<E>::top() const {
	return S[t];
}

template <typename E> // push element onto the stack
void VectorStack<E>::push(const E& e) {
	t++;
	S.push_back(e);
}

template <typename E> // pop the stack
void VectorStack<E>::pop() {
	if (!S.empty()) {
		S.erase(S.end() - 1);
		t--;
	}
}