#pragma once
#include "MaxHeapArray.h"
#include <vector>

template <class T>
std::vector<T> heapSort(T arr[], int size) {

	MaxHeap<T> heap(arr, size);
	for (int i = size / 2; i >= 0; --i) { // Only do the first half, since the rest are leaves
		heap.heapifyDown(i);
	}

	std::vector<T> toReturn;
	for (int i = 0; i < size; ++i) {
		toReturn.push_back(heap.data[0]);
		heap.removeMax();
	}

	return toReturn;
}
