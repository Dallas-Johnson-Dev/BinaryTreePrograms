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
			if (key < rootNode->getData()) {
				if (tempNode->getLeft() == NULL) return NULL;
				tempNode = tempNode->getLeft();
			}
			else if (key > rootNode->getData()) {
				if (tempNode->getRight() == NULL) return NULL;
				tempNode = tempNode->getRight();
			}
			else if (key == rootNode->getData()) {
				return tempNode->getData();
			}
		}
	}
	else return NULL;
}

void tree::modify(string operation, string key) {
	if (operation == "ADD")
	{
		if (!rootNode) {
			rootNode = new node("key", count++);
		}
	}
	else if (operation == "REMOVE") 
	{

	}
}