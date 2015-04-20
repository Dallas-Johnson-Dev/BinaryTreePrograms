#include <iostream>
#include <cstdlib>
#include <string>
#include "node.h"

using namespace std;

node::node() {
	key = "";
	data = "";
	left = NULL;
	right = NULL;
}

node::node(string newKey) {
	key = newKey;
	left = NULL;
	right = NULL;
	data = "1";
}

node::~node() {
	delete left;
	delete right;
}

string node::getKey() {
	return key;
}

void node::setKey(string newKey) {
	key = newKey;
}

node * node::getRight() {
	return right;
}

node * node::getLeft() {
	return left;
}

void node::setRight(node * newNode) {
	right = newNode;
}

void node::setLeft(node * newNode) {
	left = newNode;
}

node * node::getParent() {
	return parent;
}

void node::setParent(node * newNode) {
	parent = newNode;
}

string node::getData() {
	return data;
}

void node::setData(string newData) {
	data = newData;
}

void node::addNode(node * newNode) {
	if (newNode->getKey() < key) {
		if (left) {
			left->addNode(newNode);
		}
	}
	else if (newNode->getKey() > key) {
		if (right) {
			right->addNode(newNode);
		}
	}
	else if (newNode->getKey() == key) {
		setData(to_string(
					atol(
						data.c_str()) + 1));
	}
}

void node::delNode(string killString) {
	if (killString == key) {
		if (left && right){
			doubleChildRule();
		}
		else if (left || right) {
			singleChildRule(killString);
		}
		else {
			noChildRule(killString);
		}
	}
	else if (killString < key) {
		if (left) {
			left->delNode(killString);
		}
		else return;
	}
	else if (killString > key) {
		if (right) {
			right->delNode(killString);
		}
		else return;
	}
}

void node::noChildRule(string inputKey) {
	if (!parent) delete this;
	if (parent->getLeft()) {
		if (parent->getLeft()->getKey() == inputKey) {
			parent->setLeft(NULL);
		}
	}
	else if (parent->getRight()->getKey() == inputKey) {
		parent->setRight(NULL);
	}
	delete this;
}

void node::singleChildRule(string inputKey) {
	//HANDLE THE ROOT CASE IN THE TREE
	if (parent->getLeft()) {
		if (parent->getLeft()->getKey() == inputKey) {
			if (left) {
				parent->setLeft(left);
			}
			else if (right) {
				parent->setLeft(right);
			}
			else parent->setRight(NULL);
		}
	}
	else if (parent->getRight()->getKey() == inputKey) {
		if (left) {
			parent->setRight(left);
		}
		else if (right) {
			parent->setRight(right);
		}
		else parent->setRight(NULL);
	}
}

void node::doubleChildRule() {
	node * curNode = right;
	while (curNode->getLeft() != NULL) {
		curNode = curNode->getLeft();
	}
	key = curNode->getKey();
	data = curNode->getData();
	delete curNode;
}

void node::print() {
	if (left) {
		left->print();
	}
	cout << "There are " << data << " copies of " << key << "." << endl;
	if (right) {
		right->print();
	}
}