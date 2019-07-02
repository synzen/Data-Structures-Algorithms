#pragma once
#include <vector>
/*
1) Every node has a color either red or black.

2) Root of tree is always black.

3) There are no two adjacent red nodes (A red node cannot have a red parent or red child).

4) Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes.
*/

template <class T>
class RedBlackTree {
public:
	class Node {
	private:
		bool red = false;
	public:
		T data;
		Node* left = NULL;
		Node* right = NULL;

		Node(T d, bool r = false) : data(d), red(r) {}
		bool isRed() { return red; }
		bool isBlack() { return !red; }
		void setRed() { red = true; }
		void setBlack() { red = false; }
	};
	Node* root = NULL;

	Node* rotateNodeLeft(Node* node) {
		Node* newRoot = node->right;
		node->right = newRoot->left;
		newRoot->left = node;
		if (node == root) root = newRoot;
		return newRoot;
		
	}

	Node* rotateNodeRight(Node* node) {
		Node* newRoot = node->left;
		node->left = newRoot->right;
		newRoot->right = node;
		if (node == root) root = newRoot;
		return newRoot;
	}

	void insert(T data) {
		if (!root) {
			root = new Node(data); // Black by default
			return;
		}
		std::vector<Node*> grandparents;
		Node* grandparent = NULL;
		Node* parent = NULL;
		Node* uncle = NULL;
		Node* me = root;

		// First insert normally as you would for a BST
		while (true) {
			if (data > me->data) {
				if (me->right) {
					// Keep traversing down
					grandparents.push_back(parent);
					grandparent = parent;
					parent = me;
					if (grandparent) uncle = grandparent->left == parent ? grandparent->right : grandparent->left;
					me = me->right;
				}
				else {
					// Add here
					Node* newNode = new Node(data, true);
					me->right = newNode;
					grandparents.push_back(parent);
					grandparent = parent;
					parent = me;
					if (grandparent) uncle = grandparent->left == parent ? grandparent->right : grandparent->left;
					me = newNode;
					break;
				}
			}
			else if (data <= me->data) {
				if (me->left) {
					grandparents.push_back(parent);
					grandparent = parent;
					parent = me;
					if (grandparent) uncle = grandparent->left == parent ? grandparent->right : grandparent->left;
					me = me->left;
				}
				else {
					// Add here
					Node* newNode = new Node(data, true);
					me->left = newNode;
					grandparents.push_back(parent);
					grandparent = parent;
					parent = me;
					if (grandparent) uncle = grandparent->left == parent ? grandparent->right : grandparent->left;
					me = newNode;
					break;
				}
			}
		}

		// Then balance the tree if needed
		if (parent == root || (parent && parent->isBlack())) return;

		int grandparentsSize = grandparents.size();
		if (uncle && uncle->isRed()) { // The uncle may be NULL - in that case, NULL = black. Go to the else block below.
			int currentGrandparentIndex = grandparentsSize - 1; // this is equal to the above grandparent variable
			Node* currentGrandparent = grandparents[currentGrandparentIndex];
			while (currentGrandparentIndex >= 0) {
				parent->setBlack();
				uncle->setBlack();
				if (grandparent == root) grandparent->setBlack();
				else grandparent->setRed();
				currentGrandparentIndex -= 2; // the node is updated to every node's own respective grandparent, so 2 generations before it
			}
		}
		else {
			Node* grandgrandparent = grandparentsSize - 2 < 0 ? 0 : grandparents[grandparentsSize - 2];
			if (grandparent->left == parent) {
				if (parent->left == me) {
					Node* grandparentReplacement = rotateNodeRight(grandparent);
					if (grandgrandparent) {
						if (grandgrandparent->left == grandparent) grandgrandparent->left = grandparentReplacement;
						else grandgrandparent->right = grandparentReplacement;
					}
					grandparent->setRed();
					parent->setBlack();
				}
				else if (parent->right == me) {
					Node* parentReplacement = rotateNodeLeft(parent); // parentReplacement = this newly added node, after it was rotated right
					grandparent->left = parentReplacement;
					Node* grandparentReplacement = rotateNodeRight(grandparent);
					if (grandgrandparent) {
						if (grandgrandparent->left == grandparent) grandgrandparent->left = grandparentReplacement;
						else grandgrandparent->right = grandparentReplacement;
					}
					grandparent->setRed();
					parentReplacement->setBlack();
				}
			}
			else if (grandparent->right == parent) {
				if (parent->right == me) {
					Node* grandparentReplacement = rotateNodeLeft(grandparent);
					if (grandgrandparent) {
						if (grandgrandparent->left == grandparent) grandgrandparent->left = grandparentReplacement;
						else {
							grandgrandparent->right = grandparentReplacement;
						}
					}
					grandparent->setRed();
					parent->setBlack();
				}
				else if (parent->left == me) {
					Node* parentReplacement = rotateNodeRight(parent); // parentReplacement = this newly added node, after it was rotated right
					grandparent->right = parentReplacement;
					Node* grandparentReplacement = rotateNodeLeft(grandparent);
					if (grandgrandparent) {
						if (grandgrandparent->left == grandparent) grandgrandparent->left = grandparentReplacement;
						else grandgrandparent->right = grandparentReplacement;
					}
					grandparent->setRed();
					parentReplacement->setBlack();
				}
			}
		}
	}

	/* Given a binary tree, print its nodes in inorder*/
	void printInorder(Node* node)
	{
		if (node == NULL)
			return;

		/* first recur on left child */
		printInorder(node->left);

		/* then print the data of node */
		std::cout << node->data << "(" << node->isRed() << ") ";

		/* now recur on right child */
		printInorder(node->right);
	}

};