#pragma once

template <class T>
void insertionSort(T arr[], int size) {
	for (int i = 1; i < size; ++i) {
		T currentElem = arr[i];
		int borderIndex = i - 1;
		while (borderIndex >= 0 && currentElem < arr[borderIndex]) {
			arr[borderIndex + 1] = arr[borderIndex];
			arr[borderIndex] = currentElem;
			borderIndex -= 1;
		}
	}
}
