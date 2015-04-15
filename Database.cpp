#include <iostream>
#include <string>
#include <cstdlib>
#include "tree.h"

using namespace std;

int main(int argc, char** argv) {
	tree * testTree = new tree();
	testTree->modify("ADD", "hello");
	cout << testTree->search("hello");

	return 0;
}