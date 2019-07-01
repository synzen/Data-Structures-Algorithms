#include <iostream>
using namespace std;

template <class T>
class Node {
	public:
	T data;
	Node<T>* next = NULL;

	Node(T d) {
		data = d;
	}
};

template <class T>
class LinkedList {
	public:
	Node<T>* head = NULL;

	void insert(T data) {
		if (!head) {
			head = new Node<T>(data);
			return;
		}

		Node<T>* cursor = head;
		while (cursor->next) {
			cursor = cursor->next;
		}
		cursor->next = new Node<T>(data);		
	};

	void print() {
		Node<T>* cursor = head;
		while (cursor != NULL) {
			cout << cursor->data << endl;
			cursor = cursor->next;
		}
		free(cursor);
		cursor = NULL;
	}

	void reverse() {
		if (!head) return;
		Node<T>* prev = NULL;
		Node<T>* current = head;
		Node<T>* next = NULL;
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
		Node<T>* prev = NULL;
		Node<T>* current = head;
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
		Node<T>* prev = NULL;
		Node<T>* current = head;
		while (current) {
			prev = current;
			current = current->next;
			free(prev);
			prev = NULL;
		}
		head = NULL;
	}
};

int main()
{
	return 0;
}

