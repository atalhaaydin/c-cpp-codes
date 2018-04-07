#include "QueueNode.h"
#include <iostream>

int main(void) {
    Queue<int> q;
	int temp;
	q.enqueue(1);
	q.enqueue(50);
	q.enqueue(30);
	q.enqueue(80);
	q.enqueue(10);
	q.enqueue(7);
    q.printQueue();
	while(!q.isEmpty()) {
		q.dequeue(temp);
	}
	q.printQueue();
    return 0;
}
