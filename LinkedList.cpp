#include <iostream>
using namespace std;

class Node {
private:
	int value;
	Node* next = 0;

public:
	Node(int newValue) {
		value = newValue;
	}

	int getValue() {
		return value;
	}

	void setNextNode(Node* newNode) {
		next = newNode;
	}

	Node* getNextNode() {
		return next;
	}
};

class LinkedList {
private:
	Node* head = 0;
	Node* currentNode = 0;
	int length = 1;

public:
	LinkedList(Node* rootNode) {
		head = rootNode;
	}

	void addNode(Node* newNode) {
		if (head->getNextNode() == 0) {
			head->setNextNode(newNode);
		} else {
			currentNode->setNextNode(newNode);
		}

		currentNode = newNode;
		length++;
	}

	void insertNode(Node* newNode, int index) {
		if (index > length - 1) {
			cout << "Index out of range" << endl;
			return;
		} else if (index == 0) {
			newNode->setNextNode(head);
			head = newNode;
		} else if (index == length - 1) {
			currentNode->setNextNode(newNode);
			currentNode = newNode;
		} else {
			Node* previousNode = this->getElement(index - 1);
			Node* nextNode = this->getElement(index);

			previousNode->setNextNode(newNode);
			newNode->setNextNode(nextNode);
		}
	}

	Node* getElement(int index) {
		int currentIndex = 0;
		Node* currentNode = head;

		if (index > length - 1) {
			cout << "Index out of range" << endl;
			return NULL;
		}

		while (currentIndex < index) {
			currentNode = currentNode->getNextNode();
			currentIndex++;
		}

		return currentNode;
	}

	void removeElement(int index) {
		if (index > length - 1) {
			cout << "Index out of range" << endl;
			return;
		} else if (index == 0) {
			head = head->getNextNode();
		} else if (index == length - 1) {
			currentNode = this->getElement(index - 1);
		} else {
			Node* previousElement = this->getElement(index - 1);
			previousElement->setNextNode(this->getElement(index + 1));
		}
	}

	void showList() {
		cout << "<- Linked List Representation ->" << endl;

		Node* current = head;
		cout << "[";

		while (current->getNextNode() != 0) {
			cout << current->getValue() << " ";
			current = current->getNextNode();
		}

		cout << current->getValue() << "]" << endl;
	}
};
