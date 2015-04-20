#include <cstdlib>
#include <iostream>
#include <string>
#include "tree.h"
#include "node.h"

using namespace std;

tree::tree() {
	rootNode = NULL;
}

tree::~tree() {
	delete rootNode;
}

string tree::search(string key) {
	if (rootNode) {
		node * tempNode = rootNode;
		while (1) {
			if (key < tempNode->getData()) {
				if (tempNode->getLeft() == NULL) return NULL;
				tempNode = tempNode->getLeft();
			}
			else if (key > tempNode->getData()) {
				if (tempNode->getRight() == NULL) return NULL;
				tempNode = tempNode->getRight();
			}
			else if (key == tempNode->getData()) {
				return tempNode->getData();
			}
		}
	}
	else return NULL;
}

void tree::add(string key) {
	if (!rootNode) {
		rootNode = new node(key);
		rootNode->setData("1");
	}
	else {
		node * tempNode = rootNode;
		while (1) {
			if (key < tempNode->getKey()) {
				if (tempNode->getLeft() == NULL) {
					tempNode->setLeft(new node(key));
					tempNode->getLeft()->setParent(tempNode);
					break;
				}
				tempNode = tempNode->getLeft();
			}
			else if (key > tempNode->getKey()) {
				if (tempNode->getRight() == NULL) {
					tempNode->setRight(new node(key));
					tempNode->getRight()->setParent(tempNode);
					break;
				}
				tempNode = tempNode->getRight();
			}
			else if (key == tempNode->getData()) {
				//This will increment the counter for the data tag in the node.
				tempNode->setData(
					to_string(
						atol(
							tempNode->getData().c_str()) + 1));
				break;
			}
		}
	}
}

void tree::remove(string key) {
	if (rootNode) {
		if (rootNode->getKey() == key) {
			//No child case.
			if (!rootNode->getLeft() && !rootNode->getRight()) {
				rootNode = NULL;
			}
			else if (!rootNode->getLeft()) {
				rootNode = rootNode->getRight();
			}
			else if (!rootNode->getRight()) {
				rootNode = rootNode->getLeft();
			}
			else if (rootNode->getLeft() && rootNode->getRight()) {
				rootNode->doubleChildRule();
			}
		}
		rootNode->delNode(key);
	}
}

void tree::print() {
	if (rootNode) {
		rootNode->print();
	}
	else {
		cout << "Database is empty!" << endl;
	}
}