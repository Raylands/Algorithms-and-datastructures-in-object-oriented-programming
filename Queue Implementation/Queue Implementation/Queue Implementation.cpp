#include <iostream>
#include "Queue.hpp"

int main()
{
	LinkedQueue LQ;
	LQ.enqueue(5);
	LQ.enqueue(10);
	LQ.enqueue(15);
	LQ.enqueue(20);
	
	printf("Is the LinkedQueue empty? ");
	printf(LQ.empty() ? "True \n" : "False \n" );
	printf("LinkedQueue size: %d \n", LQ.size());
	printf("LinkedQueue front: %d \n", LQ.front());
	printf("LinkedQueue dequeuing... \n");
	LQ.dequeue();
	printf("LinkedQueue new size: %d \n", LQ.size());
	printf("LinkedQueue new front: %d \n", LQ.front());
}
