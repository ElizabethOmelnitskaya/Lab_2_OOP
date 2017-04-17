#include "LinkedList.h"
#include <string>


LinkedList::LinkedList()
{
	head = tail = NULL;
	size = 0;
}

int LinkedList::Size() const { return size; }

bool LinkedList::isEmpty() const { return size == 0; }

char* LinkedList::toString() const {
	node *tmp = head;
	char *res = new char[100]{ NULL };

	strcat(res, "Linked list\nHead ->");
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

// PushPopContainer
int LinkedList::peek() const {
	if (isEmpty()) return emptyIntValue;
	return tail->value;
}

int LinkedList::pop() {
	if (isEmpty()) return emptyIntValue;

	node *tmp = tail;
	int tmp_val = tmp->value;
	tail->prev->next = NULL;
	tail = tail->prev;
	size --;

	if (isEmpty()) head = NULL;

	delete tmp;

	return tmp_val;
}

bool LinkedList::push(int value) {
	node *newNode = new node();

	newNode->value = value;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		size++;
		return true;
	}
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;

	size ++;
	return true;
}

// Deque
bool LinkedList::pushFront(int value) {
	node *newNode = new node();

	newNode->value = value;

	if (isEmpty()) {
		head = newNode;
		tail = newNode;
		size ++;
		return true;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	size++;
	return true;
}

bool LinkedList::pushBack(int value) {
	return push(value);
}

int LinkedList::popFront() {
	if (isEmpty()) return emptyIntValue;

	node *tmp_del = head;
	int tmp_val = tmp_del->value;
	head = head->next;

	delete tmp_del;

	size--;

	if (isEmpty()) tail = NULL;
	else head->prev = NULL;

	return tmp_val;
}

int LinkedList::popBack() {
	return pop();
}

int LinkedList::peekFront() const {
	if (isEmpty()) return emptyIntValue;

	return head->value;
}

int LinkedList::peekBack() const {
	return peek();
}

// IndexedContainer 
int LinkedList::get(int index) const {
	node *element = elementAtIndex(index);
	return element == NULL ? emptyIntValue : element->value;
}

void LinkedList::set(int index, int value) {
	if (index == Size()) {
		push(value);
	}
	else {
		node *element = elementAtIndex(index);
		if (element == NULL) return;
		element->value = value;
	}
}

// InsertableContainer
bool LinkedList::insertAt(int index, int value) {
	if (index == Size()) {
		return push(value);
	}
	else if (index == 0) {
		return pushFront(value);
	}
	else {
		node *element = elementAtIndex(index);

		if (element == NULL) return false;

		node *newNode = new node();
		newNode->value = value;

		newNode->prev = element->prev;
		element->prev->next = newNode;
		newNode->next = element;
		element->prev = newNode;

		size++;

		return true;
	}
}

int LinkedList::removeAt(int index) {
	if (isEmpty()) return emptyIntValue;
	if (checkIndex(index)) return emptyIntValue;

	if (index == 0) {
		return popFront();
	}
	else if (index == Size() - 1) {
		return pop();
	}
	else {
		node *element = elementAtIndex(index);

		element->prev->next = element->next;
		element->next->prev = element->prev;

		int value = element->value;
		size--;

		return value;
	}
}

LinkedList::~LinkedList()
{
	node *tmp;

	while (head) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}