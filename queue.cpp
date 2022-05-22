using namespace std;

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
private:
	int* array;
	int queueSize;
	int front = -1;
	int back = 0;

public:
	Queue(int arraySize) {
		array = (int*) malloc(arraySize * sizeof(int));
		queueSize = arraySize;
	}

	void enqueue(int item) {
		if (!isFull()) {
			if (front == -1) {
				front = 0;
			}

			array[back] = item;
			back = (back + 1) % queueSize;
		} else {
			cout << "Queue is full" << endl;
		}
	}

	int dequeue() {
		if (!isEmpty()) {
			front = (front + 1) % queueSize;
			int temp = array[front];

			if (front == back) {
				front = -1;
			}

			return temp;
		} else {
			return -1;

		}
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return (front == ((back + 1) % queueSize));
	}

	void showQueue() {
		if (!isEmpty()) {
			cout << "[";

			for (int i = front; i < back; i++) {
				cout << array[i] << ",";
			}

			cout << "]" << endl;
		} else {
			cout << "Queue is Empty" << endl;
		}
	}
};

#endif /* QUEUE_H_ */
