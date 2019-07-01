#include <iostream>
#include "MinHeapArray.h"
using namespace std;

int main() {
	cout << "Min Heap Array" << endl;
	MinHeap<int> heap;
	heap.insert(3);
	heap.insert(5);
	heap.insert(7);
	heap.insert(4);
	heap.insert(5);
	heap.print();
	heap.removeMin();
	heap.print();
	return 0;
}
