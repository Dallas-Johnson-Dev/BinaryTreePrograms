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
	node(string newKey);
	~node();
	node * getRight();
	void setRight(node * newNode);
	node * getLeft();
	void setLeft(node * newNode);
	node * getParent();
	void setParent(node * newNode);
	string getKey();
	void setKey(string newKey);
	//Temporary methods until DRT is put in.
	string getData();
	void setData(string newData);
	void addNode(node * newNode);
	void delNode(string killString);
	//void delNode(node * killNode);
	//These three should probably return strings...
	void noChildRule(string inputKey);
	void singleChildRule(string inputKey);
	void doubleChildRule();
	void print();
};


#endif //__NODE__