#ifndef __NODE__
#define __NODE__

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class node {
private:
	node * parent;
	node * left;
	node * right;
	string key;
	//Temporary until we integrate the DRT into this.
	string data;
	int count;
	bool isRoot;

public:
	node();
	~node();
	node * getRight();
	void setRight(node * newNode);
	node * getLeft();
	void setLeft(node * newNode);
	//Temporary methods until DRT is put in.
	string getData();
	void setData(string newData);
	void addNode(node * newNode);
	void delNode(node * killNode);
	void noChildRule();
	void singleChildRule();
	void doubleChildRule();
};


#endif //__NODE__