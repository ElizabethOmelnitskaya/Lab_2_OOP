#pragma once

#include "Stack.h"
#include <string>


Stack::Stack()
{
	head = NULL;
	size = 0;
}

int Stack::Size() const { return size; } // вернуть размер стека

bool Stack::isEmpty() const { return head == NULL; }

char* Stack::toString() const {
	node *tmp = head; // текущий элемент
	char *res = new char[100]{ NULL };

	strcat(res, "Stack:\n ");
	do {
		if (tmp != head) {
			strcat(res, ", ");
		}
		char *val = new char[100]{ NULL };
		itoa(tmp->value, val, 10);

		strcat(res, val);
		tmp = tmp->next;

		delete val;
	} while (tmp != NULL);

	strcat(res, " ");

	delete tmp;
	return res;
}

int Stack::pop() {
	if (isEmpty()) throw "Stack is empty!";

	int tmp_val = head->value;

	node *tmp_del = head->next;
	delete head;
	head = tmp_del;
	if (!isEmpty()) head->prev = NULL;
	size--;
	return tmp_val;
}

int Stack::peek() const { return head->value; }

bool Stack::push(int value) {
	node *newNode = new node();

	newNode->value = value;
	newNode->next = head;
	newNode->prev = NULL;
	if (!isEmpty()) {
		head->prev = newNode;
	}
	head = newNode;
	size ++;
	return true;
}

Stack::~Stack()
{
	node *tmp;
	while (head) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
