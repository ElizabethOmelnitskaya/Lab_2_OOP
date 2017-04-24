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


int main()
{
	int elem;
	int elemPop;

	/*PushPopContainer **arr1 = new PushPopContainer*[2];
	IndexedContainer **arr2 = new IndexedContainer*[1];*/
	Deque**arr3 = new Deque*[1];

	//arr1[0] = new Queue();
	//arr1[1] = new Stack() ;

	//arr2[0] = new StaticArray(20);

	arr3[0] = new StaticDeque(20);

	/*cout << "Input elem: ";
	cin >> elem;

	cout << "Input elemPop: ";
	cin >> elemPop;

	for (int i = 1; i <= elem; i++) {
		arr1[0]->push(i);
		arr1[1]->push(i);
	}

	cout << arr1[0]->toString() << endl << endl;
	cout << arr1[1]->toString() << endl << endl;

	cout << "There are the first n elements: " << elemPop << endl << endl;
	for (int i = 0; i < elemPop; i++) {
		cout << "Step: " << i + 1 << endl;
		cout << "Out of queue: " << arr1[0]->pop() << endl;
		cout << "Out of stack: " << arr1[1]->pop() << endl << endl;
	}

	cout << "After leaving:" << endl;
	cout << arr1[0]->toString() << endl;
	cout << arr1[1]->toString() << endl;

	for (int i = 1; i <= elem; i++) { 
		arr2[0]->set(i - 1, i);
	}

	cout << arr2[0]->toString() << endl;

	cout << "Input element index:" << endl;
	int index = 0;
	cin >> index;

	cout << "Element" << index << " from static array = " << arr2[0]->get(index) << endl;*/

	Container *arr[3];

	arr[0] = new Stack;
	arr[1] = new StaticDeque(20);
	arr[2] = new Queue;

	for (Container*c : arr){
		PushPopContainer*A=dynamic_cast<PushPopContainer*>(c);
		if (A != NULL) {
			A->push(1);
			A->push(2);
			A->push(3);
		}
		Deque*D = dynamic_cast<Deque*>(c);
		if (D != NULL) {
			D->pushFront(1);
			D->pushFront(2);
			D->pushFront(3);
			D->pushBack(1);
			D->pushBack(2);
			D->pushBack(3);
		}
	}

	for (Container*c : arr){
		cout << c->toString() << endl;
		cout << c->Size() << endl;
	}
	cout << endl;
	for (Container*c : arr){
		PushPopContainer*A = dynamic_cast<PushPopContainer*>(c);
		if (A != NULL) {
			while (!c->isEmpty()){
				cout << A->pop() << endl;
				cout << c->Size() << endl;
			}
		}
		cout << endl;
		Deque*D = dynamic_cast<Deque*>(c);
		if (D != NULL) {
			while (!c->isEmpty()){
				cout << D->popBack() << endl;
				cout << c->Size() << endl;
			}
		}
	}
	system("pause");
	return 0;
}