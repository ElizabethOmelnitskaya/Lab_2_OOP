#include "interface.Container.h"
#include "PushPopContainer.h"
#include "interface.IndexedContainer.h"
#include "interface.InsertableContainer.h"
#include "Deque.h"
#include "Stack.h"
#include "Queue.h"
#include "StaticArray.h"
#include "StaticDeque.h"
#include "LinkedList.h"
#include <iostream>
#include <conio.h>

using namespace std;

const int countElements = 15;
const int countPopping = 5;
const int countPushFront = 5;

int main()
{
	PushPopContainer **arr1 = new PushPopContainer*[3];
	IndexedContainer **arr2 = new IndexedContainer*[2];
	Deque **arr3 = new Deque*[3];

	arr1[0] = new Queue();
	arr1[1] = new Stack() ;
	arr1[2] = new LinkedList;

	arr2[0] = new StaticArray(100);

	arr3[0] = new StaticDeque();

	for (int i = 1; i <= countElements; i++) {
		arr1[0]->push(i);
		arr1[1]->push(i);
		arr1[2]->push(i);
	}

	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;
	cout << arr1[2]->toString() << endl;

	cout << "Popping first n elements, n = " << countPopping << endl;

	for (int i = 0; i < countPopping; i++) {
		cout << "Stage " << i + 1 << endl;
		cout << "Popped from stack = " << arr1[0]->pop() << endl;
		cout << "Popped from queue = " << arr1[1]->pop() << endl;
		cout << "Popped from linked list = " << arr1[2]->pop() << endl;
	}

	cout << "After popping" << endl;

	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;
	cout << arr1[2]->toString() << endl;

	for (int i = 1; i <= countElements; i++) {
		arr2[0]->set(i - 1, i);
		arr2[1]->set(i - 1, i);
	}

	cout << arr2[0]->toString() << endl;
	cout << arr2[1]->toString() << endl;

	cout << "Input element index:" << endl;
	int index = 0;
	cin >> index;

	cout << "Element" << index << " from static array = " << arr2[0]->get(index) << endl;
	cout << "Element" << index << " from linked list = " << arr2[1]->get(index) << endl;

	for (int i = 0; i < countElements; i++) {
		arr3[0]->pushBack(i);
		arr3[1]->pushBack(i);
	}

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;

	cout << "Front pushing: " << endl;

	for (int i = 0; i < countPushFront; i++) {
		arr3[0]->pushFront(countElements + i);
		arr3[1]->pushFront(countElements + i);
	}

	cout << "After pushing:" << endl;

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;

	cout << "Back popping: " << endl;

	for (int i = 0; i < countPopping; i++) {
		cout << "Stage " << i + 1 << endl;
		cout << "Popped from static array = " << arr3[0]->popBack() << endl;
		cout << "Popped from linked list = " << arr3[1]->popBack() << endl;
	}

	cout << "After popping: " << endl;

	cout << arr3[0]->toString() << endl;
	cout << arr3[1]->toString() << endl;

	_getch();

	return 0;
}