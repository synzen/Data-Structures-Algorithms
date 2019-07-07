
#include <iostream>
using namespace std;
void swapPositions(int arr[], int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}


int partition(int arr[], int start, int end) {
	// first element is pivot
	//cout << "start = " << start << ", end = " << end << endl;
	int elem = arr[start];
	int divider = end + 1;
	for (int j = end; j >= 0; --j) {
		if (arr[j] >= elem) continue;
		divider -= 1;
		swapPositions(arr, divider, j);	
	}
	swapPositions(arr, divider - 1, start);
	return divider - 1;
}


void quicksort(int arr[], int start, int end) {
	if (start >= end) return;
	int divider = partition(arr, start, end);
	quicksort(arr, start, divider - 1);
	quicksort(arr, divider + 1, end);
}

