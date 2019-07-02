#pragma once

template <class T>
class LinkedList {
public:
	class Node {
	public:
		T data;
		Node* next = 0;

		Node(T d) : data(d) {}
	};
	Node* head = 0;


	void print() {
		Node* cursor = head;
		while (cursor != 0) {
			std::cout << cursor->data << std::endl;
			cursor = cursor->next;
		}
		free(cursor);
		cursor = 0;
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
		Node* prev = 0;
		Node* current = head;
		Node* next = 0;
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
		Node* prev = 0;
		Node* current = head;
		while (current) {
			if ((*f)(current->data)) {
				if (!prev) {
					// if prev is 0, then we're working with the head
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
		Node* prev = 0;
		Node* current = head;
		while (current) {
			prev = current;
			current = current->next;
			free(prev);
			prev = 0;
		}
		head = 0;
	}
};
