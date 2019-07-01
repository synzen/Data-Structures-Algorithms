#include <iostream>
#include "MaxHeapArray.h"
using namespace std;

int main () {
	MaxHeap<int> heap;
	heap.insert(3);
	heap.insert(5);
	heap.insert(7);
	heap.insert(4);
	heap.insert(5);
	heap.print();
	heap.removeMax();
	heap.print();
	return 0;
}
