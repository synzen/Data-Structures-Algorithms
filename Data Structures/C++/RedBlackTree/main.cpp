#include <iostream>
#include "RedBlackTree.h"
using namespace std;

int main()
{
	cout << "Red Black Tree" << endl;
	//RedBlackTree<int> tree;
	//tree.insert(10);
	//tree.insert(20);
	//// tree.insert(30);
	//// tree.insert(15);
	//tree.printInorder(tree.root);
	//cout << endl;
	RedBlackTree<int> tree2;
	tree2.insert(10);
	tree2.insert(20);
	tree2.insert(30);
	tree2.insert(15);
	tree2.insert(100);
	tree2.insert(75);
	tree2.insert(90);
	tree2.insert(1);
	tree2.insert(2);
	//cout << endl << endl;
	//cout << tree2.root->right->data << endl;
	//tree2.insert(12);

	tree2.printInorder(tree2.root);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
