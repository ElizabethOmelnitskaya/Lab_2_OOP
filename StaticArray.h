#pragma once
#include "interface.IndexedContainer.h"

class StaticArray : public IndexedContainer {
private:
	int *arr;
	int size;
public:
	StaticArray(int);

	int Size() const;
	bool isEmpty() const;
	char* toString() const;

	int get(int) const;
	void set(int, int);

	
	~StaticArray();
};

