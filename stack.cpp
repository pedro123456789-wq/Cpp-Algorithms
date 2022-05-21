#include <iostream>
using namespace std;


// implementation of stack using circular array

class Stack {
private:
	int* array;
	int top = 0;
	int maxSize;

public:
	Stack(int arraySize) {
		maxSize = arraySize;
		array = (int*) malloc(arraySize * sizeof(int));
	}

	void push(int item) {
		if (!isFull()) {
			array[top] = item;
			top++;
		}
	}

	int pop() {
		if (!isEmpty()) {
			top--;
			return array[top];
		} else {
			return -1;
		}
	}

	bool isFull() {
		return (top == maxSize);
	}

	bool isEmpty() {
		return (top == 0);
	}

	void showStack() {
		cout << "[";

		for (int i = 0; i < top; i++) {
			cout << array[i] << ",";
		}

		cout << "]" << endl;
	}
};
