#include <iostream>
#include <string>
#include <cstdlib>
#include "tree.h"
#include "Database.h"

using namespace std;

int main(int argc, char** argv) {
	//Database * library = new Database();
	tree * testTree = new tree();
	testTree->print();
	testTree->add("Hello");
	testTree->add("World");
	testTree->add("Test");
	//Print goes in alphabetical order
	testTree->print();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	testTree->remove("Test");
	testTree->print();
	system("pause");
	delete testTree;
	return 0;
}