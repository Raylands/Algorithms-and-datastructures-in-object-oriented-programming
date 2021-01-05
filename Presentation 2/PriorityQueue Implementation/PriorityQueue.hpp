#pragma once
#include <list>
#include <functional>

template <typename E>
class ListPriorityQueue {
public:
	int size() const;		 // number of elements
	bool empty() const;		 // is the queue empty?
	void insert(const E& e, const std::function<bool(E, E)> f); // insert element
	const E& min() const;	 // minimum element
	const E& max() const;	 // maximum element
	void removeMin();		 // remove minimum
	void removeMax();		 // remove maximum
private:
	std::list<E> L;			 // priority queue contents
};



template <typename E, typename C> // number of elements
int ListPriorityQueue<E, C>::size() const
{
	return L.size();
}

template <typename E, typename C> // is the queue empty?
bool ListPriorityQueue<E, C>::empty() const
{
	return L.empty();
}

template <typename E, typename C> // insert element
void ListPriorityQueue<E, C>::insert(const E& e, const std::function<bool(E, E)> f) {
	typename std::list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && !f(e, *p)) ++p; // find larger element
	L.insert(p, e);								// insert e before p
}

template <typename E, typename C> // minimum element
const E& ListPriorityQueue<E, C>::min() const
{
	return L.front();	// minimum is always at the front
} 

template <typename E, typename C> // remove minimum
void ListPriorityQueue<E, C>::removeMin()
{
	L.pop_front();		// minimum is always at the front
}

template <typename E, typename C> // maxiumum element
const E& ListPriorityQueue<E, C>::max() const
{
	return L.back();	// maximum is always at the back
}

template <typename E, typename C> // remove maximum
void ListPriorityQueue<E, C>::removeMax()
{
	L.pop_back();		// maximum is always at the back
}