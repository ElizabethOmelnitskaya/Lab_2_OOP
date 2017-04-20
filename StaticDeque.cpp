#include "StaticDeque.h"
#include <string>

StaticDeque::StaticDeque(int default_value)
{
	if (size <= 0) throw 4;
	this->size = size;
	arr = new int [size];
	for (int i = 0; i < size; i++)
		arr[i] = default_value; //значение по умолчанию
}

StaticDeque::~StaticDeque() { delete[] arr; }

int StaticDeque::Size() const { return size; }

bool StaticDeque::isEmpty() const { return size == 0; }

char* StaticDeque::toString() const {
	node *tmp = head;
	char *res = new char[100]{ NULL };

	strcat(res, "StaticDeque\nHead ->");
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

bool StaticDeque::pushBack(int value) {
	int *tmp_arr = new int [size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i] = arr[i];
	tmp_arr[size] = value;

	delete[] arr;

	arr = tmp_arr;
	size++;

	return true;
}

bool StaticDeque::pushFront(int value) {
	int *tmp_arr = new int [size + 1];
	for (int i = 0; i < size; i++)
		tmp_arr[i + 1] = arr[i];
	tmp_arr[0] = value;
	delete[] arr;
	arr = tmp_arr;
	size++;
	return true;
}

int StaticDeque::peekBack() const { return arr[size - 1]; }

int StaticDeque::peekFront() const { return arr[0]; }

int StaticDeque::popBack() {
	if (isEmpty()) throw 1;
	else if (size == 1) throw 3;

	int *tmp_arr = new int [size - 1], res_val = arr[size - 1];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i];

	delete[] arr;

	arr = tmp_arr;
	size--;

	return res_val;
}

int StaticDeque::popFront() {

	if (isEmpty())
		throw 1;
	else if (size == 1)
		throw 3;
	int *tmp_arr = new int[size - 1], res_val = arr[0];
	for (int i = 0; i < size - 1; i++)
		tmp_arr[i] = arr[i + 1];

	delete[] arr;
	
	arr = tmp_arr;
	size--;
	
	return res_val;
}