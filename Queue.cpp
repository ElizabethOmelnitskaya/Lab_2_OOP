#include "Queue.h"
#include <string>

Queue::Queue()
{
	head = tail = NULL;
	size = 0;
}

int Queue::Size() const { return size; }

bool Queue::isEmpty() const { return size == 0; }

char* Queue::toString() const {
	node *tmp = head; // текущий элемент
	char *res = new char[100]{ NULL };

	strcat(res, "Queue\nHead ->");
	
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

	strcat(res, "<- Tail");

	delete tmp;
	return res;
}
	
int Queue::pop() {
	if (isEmpty()) throw "Queue is empty!";

	int tmp_val = head->value;

	node *tmp_del = head->next;

	delete head;
	head = tmp_del;

	if (isEmpty()) tail = NULL;
	else head->prev = NULL;
	size--;

	return tmp_val;
}

int Queue::peek() const {
	if (isEmpty()) throw "Queue is empty!";
	return head->value;
}

bool Queue::push(int value) {
	node *newNode = new node();

	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = tail;

	if (isEmpty()) head = newNode;
	else tail->next = newNode;
	tail = newNode;
	size ++;
	return true;
}

Queue::~Queue()
{
	node *tmp;

	while (head) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}