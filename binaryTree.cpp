#include <iostream>
using namespace std;

class Node {
private:
	int value;
	Node* left;
	Node* right;

public:
	Node(int newValue) {
		value = newValue;
		left = NULL;
		right = NULL;
	}

	int getValue() {
		return value;
	}

	void setLeft(Node* newNode) {
		left = newNode;
	}

	Node* getLeft() {
		return left;
	}

	void setRight(Node* newNode) {
		right = newNode;
	}

	Node* getRight() {
		return right;
	}

	void displayNode() {
		cout << "Node -> " << value << endl;
	}
};

class BinaryTree {
private:
	Node* rootNode;

public:
	BinaryTree(Node* firstNode) {
		rootNode = firstNode;
	}

	Node* getRoot() {
		return rootNode;
	}

	void addNode(Node* newNode) {
		bool isPlaced = false;
		Node* currentNode = rootNode;

		while (!isPlaced) {
			if (newNode->getValue() > currentNode->getValue()) {
				if (currentNode->getRight() != NULL) {
					currentNode = currentNode->getRight();
				} else {
					currentNode->setRight(newNode);
					isPlaced = true;
				}
			} else {
				if (currentNode->getLeft() != NULL) {
					currentNode = currentNode->getLeft();
				} else {
					currentNode->setLeft(newNode);
					isPlaced = true;
				}
			}
		}

		cout << "Added new node" << endl;
	}


	Node* getNode(int value){
		Node* currentNode = rootNode;
		bool isFound = false;
		bool isFinished = false;

		while (!isFinished){
			if (value == currentNode->getValue()){
				isFinished = true;
				isFound = true;
			}
			else if (value > currentNode->getValue()){
				if (currentNode->getRight()){
					currentNode = currentNode->getRight();
				}else{
					isFinished = true;
					isFound = false;
				}
			}else{
				if (currentNode->getLeft()){
					currentNode = currentNode->getLeft();
				}else{
					isFinished = true;
					isFound = false;
				}
			}
		}

		if (isFound){
			return currentNode;
		}else{
			return NULL;
		}
	}
	
	
	

	void inOrderTraversal(Node* node) {
		//left subtree, root, right subtree
		// used to display nodes in tree in ascending order

		if (node->getLeft()) {
			inOrderTraversal(node->getLeft());
		}

		node->displayNode();

		if (node->getRight()) {
			inOrderTraversal(node->getRight());
		}
	}

	void postOrderTraversal(Node* node) {
		//right subtree, left subtree, root
		//shows order in which nodes need to be deleted to minimize number of operations required to delete the tree

		if (node->getRight()) {
			postOrderTraversal(node->getRight());
		}

		if (node->getLeft()) {
			postOrderTraversal(node->getLeft());
		}

		node->displayNode();
	}

	void preOrderTraversal(Node* node) {
		//root node, left subtree, right subtree
		//outputs the nodes in which the nodes should be added to reconstruct the tree

		node->displayNode();

		if (node->getRight()) {
			preOrderTraversal(node->getRight());
		}

		if (node->getLeft()) {
			preOrderTraversal(node->getLeft());
		}
	}
};
