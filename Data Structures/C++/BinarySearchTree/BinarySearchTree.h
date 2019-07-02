#pragma once

// Assuming equal elements go on the LEFT side

template <class T>
class BinarySearchTree {
public:
	class Node {
	public:
		T data;
		Node* left = 0;
		Node* right = 0;

		Node(T d) : data(d) {}
	};
	Node* root = 0;

	void insert(T data) {
		if (!root) {
			root = new Node(data);
			return;
		}

		Node* current = root;
		while (current) {
			if (data > current->data) {
				if (current->right) current = current->right;
				else {
					current->right = new Node(data);
					return;
				}
			}
			else {
				if (current->left) current = current->left;
				else {
					current->left = new Node(data);
					return;
				}
			}
		}
	}

	bool has(T d) {
		Node* current = root;
		while (current) {
			if (current->data == d) return true;
			if (d > current->data) current = current->right;
			else current = current->left;
		}
		return false;
	}

	Node* removeRoot(Node* root) {
		if (!root->left && !root->right) return 0;
		if (!root->left) return root->right;
		if (!root->right) return root->left;
		Node* parent = root;
		Node* cur = root->right;
		if (!cur->left) {
			cur->left = parent->left;
			return cur;
		}
		while (cur->left) {
			parent = cur;
			cur = cur->left;
		}
		parent->left = cur->right;
		root->val = cur->val;
		return root;
	}

	Node* min() {
		if (!root) return 0;
		Node* current = root;
		while (current->left) {
			current = current->left;
		}
		return current;
	}
	
	Node* max() {
		if (!root) return 0;
		Node* current = root;
		while (current->right) {
			current = current->right;
		}
		return current;
	}

	void remove(T value) {
		Node* parent = 0;
		Node* cur = root;
		while (cur) {
			if (value < cur->data) {
				parent = cur;
				cur = cur->left;
			}
			else if (value > cur->data) {
				parent = cur;
				cur = cur->right;
			}
			else {
				if (!parent) return removeRoot(cur);
				else if (parent->left == cur) parent->left = removeRoot(cur);
				else parent->right = removeRoot(cur);
			}
		}
		return root;
	}
};
