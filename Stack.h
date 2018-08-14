
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define MAX_STACK 256

struct StackDisk {
	int data;
	StackDisk* next;
};

class Stack {
public:
	Stack();
	Stack(int _data);

	bool pop(int &_dataOut);
	bool push(int dataIn);

	bool top(int &_dataOut);

	bool isEmpty();
	bool isFull();

	int size();
	void print();

	void arrayToStack(int *arr, int N);

private:
	StackDisk *pHead;
	int count;
};

#endif