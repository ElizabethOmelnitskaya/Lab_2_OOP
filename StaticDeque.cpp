#include "StaticDeque.h"
#include <string>

StaticDeque::StaticDeque(int default_value)
{
	head = NULL;
	tail = NULL;
	size = 0;
}

StaticDeque::~StaticDeque() { delete[] arr; }

int StaticDeque::Size() const { return size; }

bool StaticDeque::isEmpty() const { return size == 0; }

char* StaticDeque::toString() const {
	node *tmp = head;
	char *res = new char[100]{ NULL };

	strcat(res, "StaticDeque:\n ");
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

	strcat(res, "  ");
	delete tmp;
	return res;
}

bool StaticDeque::pushBack(int value) {
	node *newNode = new node();

	newNode->value = value;

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	size++;

	return true;
}

bool StaticDeque::pushFront(int value) {
	node *newNode = new node();

	newNode->value = value;

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	size++;
	return true;
}

int StaticDeque::peekBack() const { return arr[size - 1]; }

int StaticDeque::peekFront() const { return arr[0]; }

int StaticDeque::popBack() {
	if (isEmpty()) return -1;

	int value = tail->value;
	if (Size() == 1) {
		delete tail;

		tail = NULL;
		head = NULL;
	}
	else {
		node *elemPop = tail;
		tail = tail->prev;
		tail->next = NULL;

		delete elemPop;
	}
	size--;

	return value;
}

int StaticDeque::popFront() {

	if (isEmpty()) return -1;

	int value = tail->value;
	if (Size() == 1) {
		delete tail;

		tail = NULL;
		head = NULL;
	}
	else {
		node *elemPop = head;
		head = head->next;
		head->prev = NULL;

		delete elemPop;
	}
	size--;
	
	return value;
}