#pragma once

template <class T>
int binarySearch(T arr[], int size, int elem) {
	int start = 0;
	int end = size - 1;
	int middle = (end - start) / 2;
	while (true) {
		T middleElem = arr[middle];
		if (middleElem == elem) return middle;
		if (middle == 0 || middle == size) return -1;

		if (elem > middleElem) {
			start = middle + 1;
			middle = start + (end - start) / 2;
		}
		else {
			end = middle - 1;
			middle = start + (end - start) / 2;
		}
	}
	return -1;
}
