#pragma once

template <class T>
class DoublyLinkedList {
public:
	class Node {
	public:
		T data;
		Node* next = NULL;
		Node* prev = NULL;

		Node(T d) : data(d) {}
	};
	Node* head = NULL;

	void print() {
		Node* cursor = head;
		while (cursor != NULL) {
			std::cout << cursor->data << std::endl;
			cursor = cursor->next;
		}
		free(cursor);
		cursor = NULL;
	};

	void insert(T data) {
		if (!head) {
			head = new Node(data);
			return;
		}

		Node* cursor = head;
		while (cursor->next) {
			cursor = cursor->next;
		}
		Node* newNode = new Node(data);
		cursor->next = newNode;
		newNode->prev = cursor;
	};
	
	void reverse() {
		if (!head) return;
		Node* prev = NULL;
		Node* current = head;
		Node* next = NULL;
		while (current) {
			next = current->next;
			current->next = prev;
			current->prev = next;
			prev = current;
			current = next;
		}
		head = prev;
	};

	void removeWhere(bool(*f)(T)) {
		if (!head) return;
		Node* prev = NULL;
		Node* current = head;
		while (current) {
			if ((*f)(current->data)) {
				if (!prev) {
					// if prev is null, then we're working with the head
					head = current->next;
					free(head->prev);
					head->prev = NULL;
					current = head;
				}
				else {
					prev->next = current->next;
					if (current->next) {
						current->next->prev = prev;
					}
					free(current);
					current = prev->next;
				}
			}
			else {
				// Just move to the next element
				prev = current;
				current = current->next;
			}
		}
	};

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
	};
};