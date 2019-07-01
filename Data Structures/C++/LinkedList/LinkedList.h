#pragma once

template <class T>
class LinkedList {
public:
	class Node {
	public:
		T data;
		Node* next = NULL;

		Node(T d) { data = d; }
	};
	Node* head = NULL;


	void print() {
		Node* cursor = head;
		while (cursor != NULL) {
			cout << cursor->data << endl;
			cursor = cursor->next;
		}
		free(cursor);
		cursor = NULL;
	}

	void insert(T data) {
		if (!head) {
			head = new Node(data);
			return;
		}

		Node* cursor = head;
		while (cursor->next) {
			cursor = cursor->next;
		}
		cursor->next = new Node(data);
	};

	void reverse() {
		if (!head) return;
		Node* prev = NULL;
		Node* current = head;
		Node* next = NULL;
		while (current) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	void removeWhere(bool(*f)(T)) {
		if (!head) return;
		Node* prev = NULL;
		Node* current = head;
		while (current) {
			if ((*f)(current->data)) {
				if (!prev) {
					// if prev is null, then we're working with the head
					head = current->next;
					current = head;
				}
				else {
					prev->next = current->next;
					current = current->next;
				}
			}
			else {
				// Just move to the next element
				prev = current;
				current = current->next;
			}

		}
	}

	void clear() {
		if (!head) return;
		Node* prev = NULL;
		Node* current = head;
		while (current) {
			prev = current;
			current = current->next;
			free(prev);
			prev = NULL;
		}
		head = NULL;
	}
};
