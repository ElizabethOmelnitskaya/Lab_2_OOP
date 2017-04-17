#pragma once
#include "PushPopContainer.h"
#include "Node.h"

class Stack : public PushPopContainer {
private:
	node *head;
	int size;// ������� �����
public:
	Stack(); 

	int Size() const; // �������� ������ �����
	bool isEmpty() const; // ���� �� ����
	char *toString() const;

	int peek() const;
	int pop(); // ������� ������� �� �����
	bool push(int); // �������� ������� � ����

	~Stack();
};
