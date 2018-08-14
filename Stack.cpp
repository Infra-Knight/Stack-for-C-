
#include "Stack.h"

Stack::Stack()  {
	pHead = NULL;
	count = 0;
}

Stack::Stack(int _data) {
	pHead = new StackDisk;
	pHead->next = NULL;
	pHead->data = _data;
}

bool Stack::pop(int &_dataOut){
	if (isEmpty()) return false;
	else {
		_dataOut = pHead->data;
		StackDisk* pTemp = pHead;
		pHead = pHead->next;
		count--;
		delete pTemp;
		return true;
	}
}

bool Stack::push(int _dataIn) {
	if (pHead == NULL) {
		pHead = new StackDisk;
		pHead->data = _dataIn;
		pHead->next = NULL;
		count++;
		return true;
	}
	if (count == MAX_STACK) return false;
	StackDisk *pNew = new StackDisk;
	pNew->data = _dataIn;
	pNew->next = pHead;
	pHead = pNew;
	count++;
}

bool Stack::top(int &_dataOut) {
	if (pHead == NULL) return false;
	_dataOut = pHead->data;
	return true;
}

bool Stack::isEmpty() {
	if (pHead == NULL) return true;
	else return false;
}

bool Stack::isFull() {
	if (count == MAX_STACK) return true;
	else return false;
}

int Stack::size() {
	return count;
}

void Stack::print() {
	if (count == 0) {
		cout << "Stack is empty..." << endl;
		return;
	}

	StackDisk *pTemp = pHead;
	cout << "Top -> ";
	while (pTemp != NULL) {
		cout << pTemp->data;
		if (pTemp->next != NULL) {
			cout << " -> ";
		}
		pTemp = pTemp->next;
	}
	cout << endl;
}

void Stack::arrayToStack(int *arr, int N) {
	for (int i = 0; i < N; i++) {
		push(arr[i]);
	}
}