#include "Queue.hpp"

LinkedQueue::LinkedQueue() // constructor
	: C(), n(0) { ; }

int LinkedQueue::size() const // number of items in the queue
{
	return n;
}

bool LinkedQueue::empty() const // is the queue empty?
{
	return n == 0;
}

// get the front element
const int& LinkedQueue::front() const {
	return C.front(); // list front is queue front - will crash if empty
}

void LinkedQueue::enqueue(const int& e) {
	C.add(e); // insert after cursor
	C.advance(); // . . .and advance
	n++;
}

// dequeue element at front
void LinkedQueue::dequeue() {
	C.remove(); // remove from list front - crashes when empty
	n--;
}