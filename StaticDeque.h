#pragma once
#include "Deque.h"
#include "Node.h"

class StaticDeque : public Deque {
private:
	node *head, *tail;
	int size;
	int *arr;
public:
	StaticDeque();

	int Size() const;
	bool isEmpty() const;
	char* toString() const;

	bool pushBack(int);
	bool pushFront(int);
	int popBack();
	int popFront();
	int peekBack() const;
	int peekFront() const;
	
	~StaticDeque();
};

