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

const int elem = 7;
const int elemPop = 3;
const int elemPushFront = 5;

int main()
{
	PushPopContainer **arr1 = new PushPopContainer*[2];
	IndexedContainer **arr2 = new IndexedContainer*[1];
	Deque **arr3 = new Deque*[1];

	arr1[0] = new Queue();
	arr1[1] = new Stack() ;

	arr2[0] = new StaticArray(100);

	arr3[0] = new StaticDeque(15);

	for (int i = 1; i <= elem; i++) {
		arr1[0]->push(i);
		arr1[1]->push(i);
	}

	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;

	cout << "There are the first n elements: " << elemPop << endl;
	for (int i = 0; i < elemPop; i++) {
		cout << "Step: " << i + 1 << endl;
		cout << "Out of queue: " << arr1[0]->pop() << endl;
		cout << "Out of stack: " << arr1[1]->pop() << endl;
	}

	cout << "After leaving:" << endl;
	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;

	for (int i = 1; i <= elem; i++) {
		arr2[0]->set(i - 1, i);
		arr2[1]->set(i - 1, i);
	}
	cout << arr2[0]->toString() << endl;

	int index = 0;
	cout << "Input element index:" << endl;
	cin >> index;
	cout << "Element " << index << "from static array: " << arr2[0]->get(index) << endl;
	
	for (int i = 0; i < elem; i++) {
		arr3[0]->pushBack(i);
	}
	cout << arr3[0]->toString() << endl;

	cout << "Front pushing: " << endl;
	for (int i = 0; i < elemPushFront; i++) {
		arr3[0]->pushFront(elem + i);
	}
	cout << "After pushing:" << endl;
	cout << arr3[0]->toString() << endl;

	cout << "Again. Back popping: " << endl;
	for (int i = 0; i < elemPop; i++) {
		cout << "Step " << i + 1 << endl;
		cout << "output from an static array: " << arr3[0]->popBack() << endl;
	}

	cout << "After leaving: " << endl;
	cout << arr3[0]->toString() << endl;

	system("pause");
	return 0;
}