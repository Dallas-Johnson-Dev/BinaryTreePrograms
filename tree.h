#ifndef __TREE__
#define __TREE__

#include <cstdlib>
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

class tree {
private:
	node * rootNode;
public:
	tree();
	~tree();
	string search(string key);
	void modify(string operation, string key);
};

#endif //__TREE__