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

	strcat(res, "Linked list:\n ");
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

// PushPopContainer
int LinkedList::peek() const { return tail->value; }

int LinkedList::pop() {
	if (isEmpty()) throw 1;

	node *tmp_del = tail->prev;
	int tmp_val = tail->value;
	delete tail;
	tail = tmp_del;
	if (tail) tail->next = NULL;
	else head = NULL;
	size--;
	return tmp_val;
}

bool LinkedList::push(int value) {
	node *tmp = new node();

	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = tail;
	if (isEmpty())
		head = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	size++;

	return true;
}

/*// Deque
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
}*/

// IndexedContainer 
int LinkedList::get(int index) const {
	if (isEmpty()) throw 1;
	else if (index >= size || index < 0)
		throw 2;
	node *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	return tmp->value;
}

void LinkedList::set(int index, int value) {
	if (isEmpty()) throw 1;
	else if (index >= size || index < 0) throw 2;
	node *tmp = head;
	for (int i = 1; i <= index; i++)
		tmp = tmp->next;
	tmp->value = value;
}

// InsertableContainer
bool LinkedList::insertAt(int index, int value) {
	if (index > size || index < 0 || isEmpty() && index)
		throw 2;
	int tmp_value;
	node *tmp_node = new node;
	tmp_node->value = value;
	tmp_node->next = head;
	tmp_node->prev = NULL;
	if (isEmpty()) tail = tmp_node;
	else head->prev = tmp_node;
	head = tmp_node;
	size++;
	for (int i = 0; i < index; i++)
	{
		tmp_value = get(i);
		set(i, get(i + 1));
		set(i + 1, tmp_value);
	}

	return true;
}

int LinkedList::removeAt(int index) {
	if (isEmpty()) throw 1;
	else if (index >= size || index < 0) throw 2;

	int tmp_head_val = head->value, tmp_val;
	node *tmp_node = head->next;
	delete head;
	head = tmp_node;
	if (head)
		head->prev = NULL;
	else
		tail = NULL;
	size--;
	for (int i = index - 1; i > 0; i--)
		set(i, get(i - 1));
	if (index)
		set(0, tmp_head_val);
	return tmp_val;
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