#pragma once
#include "PushPopContainer.h"
#include "Node.h"

class Queue : public PushPopContainer {
private:
	node *head, *tail;
	int size;
public:
	Queue();

	int Size() const;
	bool isEmpty() const;
	char* toString() const;

	bool push(int);
	int pop();
	int peek() const;
	
	~Queue();
};