#include "StaticArray.h"
#include <string>

StaticArray::StaticArray(int _maxNumber)
{
	arr = new int[_maxNumber];
	size = 0;
}

int StaticArray::Size() const { return size; }

bool StaticArray::isEmpty() const { return size == 0; }

char* StaticArray::toString() const {
	char *res = new char[100]{ NULL };

	strcat(res, "StaticArray\nHead->");
	for (int i = 0; i < Size(); i++) {
		if (i != 0) {
			strcat(res, ", ");
		}
		char *val = new char[100]{ NULL };

		itoa(arr[i], val, 10);
		strcat(res, val);

		delete val;
	}
	strcat(res, "<-Tail");
	return res;
}

int StaticArray::get(int index) const{
	if (isEmpty()) throw 1;
	else if (index >= size || index < 0) throw 2;
	return arr[index];
}

void StaticArray::set(int index, int value) {
	if (isEmpty()) throw 1;
	else if (index >= size || index < 0) throw 2;
	arr[index] = value;
}

StaticArray::~StaticArray() { delete[] arr; }