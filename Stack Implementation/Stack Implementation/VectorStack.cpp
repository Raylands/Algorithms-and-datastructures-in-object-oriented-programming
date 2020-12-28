#include "VectorStack.hpp"

template <typename E>
VectorStack<E>::VectorStack() { ; } // constructor from capacity

template <typename E>
int VectorStack<E>::size() const {
	return (t);
} // number of items in the stack

template <typename E> bool VectorStack<E>::empty() const {
	return (t>-1);
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