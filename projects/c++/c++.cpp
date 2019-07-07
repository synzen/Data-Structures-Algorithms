#include <iostream>
#include "insertionSort.h"
#include "quickSort.h"
using namespace std;

int main()
{
	int arr[5] = { 9,2,5,10,7 };
	quicksort(arr, 0, 4);
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << " ";
	}
}

