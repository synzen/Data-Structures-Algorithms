#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
	cout << "Doubly Linked List" << endl;
	DoublyLinkedList<int> list;
	list.insert(12);
	list.insert(13);
	list.insert(14);
	list.insert(15);
	list.removeWhere([](int data) -> bool { return data == 13; });
	list.print();
	list.reverse();
	list.print();
	return 0;
}
