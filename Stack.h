#pragma once
#include "PushPopContainer.h"
#include "Node.h"

class Stack : public PushPopContainer {
private:
	node *head;
	int size;// Емкость стека
public:
	Stack(); 

	int Size() const; // получить размер стека
	bool isEmpty() const; // пуст ли стек
	char *toString() const;

	int peek() const;
	int pop(); // удалить элемент из стека
	bool push(int); // добавить элемент в стек

	~Stack();
};
