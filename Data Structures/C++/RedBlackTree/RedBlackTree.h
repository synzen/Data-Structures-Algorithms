#pragma once
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
	public:
		T data;
		bool red = false;
		Node* left = NULL;
		Node* right = NULL;

		Node(T d, bool red = false) : data(d) {}
		bool isRed() { return red; }
		bool isBlack() { return !red; }
		void setRed() { red = true; }
		void setBlack() { red = false; }
	};
	Node* root = NULL;

	void insert(T data) {
		if (!root) {
			root = new Node(data);
			return;
		}
	}
};