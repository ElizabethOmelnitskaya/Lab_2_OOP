#pragma once
#include "interface.InsertableContainer.h"
#include "PushPopContainer.h"
#include "Node.h"

class LinkedList : public InsertableContainer, public PushPopContainer
{
private:
	node *head, *tail;
	int size;
public:
	LinkedList();

	// Container
	int Size() const;
	bool isEmpty() const;
	char* toString() const;

	/*// Deque
	bool pushFront(int);
	bool pushBack(int);
	int popFront();
	int popBack();
	int peekFront() const;
	int peekBack() const;*/

	// PushPopContainer
	bool push(int);
	int peek() const;
	int pop();

	// IndexedContainer
	int get(int) const;
	void set(int, int);

	// InsertableContainer
	bool insertAt(int, int);
	int removeAt(int);

	~LinkedList();
};