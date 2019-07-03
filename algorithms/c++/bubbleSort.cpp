void bubbleSort(int arr[], int size) {
	if (size == 1) return;
	for (int i = 0; i < size; ++i) {
		bool swapped = false;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] <= arr[i + 1]) continue; // Already at their correct positions
			int temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
			swapped = true;
		}
		if (!swapped) break; // No swaps were made, thus all positions are positioned correctly
	}
}
