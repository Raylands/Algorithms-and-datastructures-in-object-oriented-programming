#pragma once
class CNode { // circularly linked list node
private:
	int elem; // linked list element value
	CNode* next; // next item in the list
	friend class CircleList; // provide CircleList access
};