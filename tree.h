#ifndef __TREE__
#define __TREE__

#include <cstdlib>
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class node;

/*typedef struct StringReturns {
	string key;
	string node;
};*/

class tree {
private:
	node * rootNode;
public:
	tree();
	~tree();
	string search(string key);
	void add(string key);
	void remove(string key);
	void print();
};

#endif //__TREE__