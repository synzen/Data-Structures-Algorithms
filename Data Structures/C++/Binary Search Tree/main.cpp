#include <iostream>
#include "Binary Search Tree.h"
using namespace std;

int main()
{
    cout << "Binary Search Tree" << endl;
	BinarySearchTree<int> tree;
	tree.insert(2);
	tree.insert(3);
	tree.insert(1);
	tree.insert(10);
	tree.insert(5);
	cout << tree.has(10) << endl;
	return 0;
}
