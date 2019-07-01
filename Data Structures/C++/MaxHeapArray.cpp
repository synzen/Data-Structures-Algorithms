#include <iostream>
#include <vector>
using namespace std;

// arr[(i-1)/2] = parent node
// arr[(2*i)+1] = left child
// arr[(2*i)+2] = right child

template <class T>
class MaxHeap {
public:
	vector<T> data;
	
	void insert(T d) {
		data.push_back(d);
		int size = data.size();
		if (size == 1) return;
		heapifyUp(size - 1);
	}

	void heapifyUp(int i) {
		int value = data[i];
		int parentIndex = parentIndexOf(i);

		while (parentIndex >= 0 && value > data[parentIndex]) {
			// swap the parent and the current nodes until the max heap is satisfied
			data[i] = data[parentIndex];
			data[parentIndex] = value;
			i = parentIndex;
			parentIndex = parentIndexOf(i);
		}
	}

	void heapifyDown(int i) {
		int size = data.size();
		int largestIndex = i;
		int value = data[i];
		do {
			if (largestIndex != i) {
				data[i] = data[largestIndex];
				data[largestIndex] = value;
				i = largestIndex;
			}
			int leftChildIndex = leftChildIndexOf(i);
			if (leftChildIndex < size && data[leftChildIndex] > data[i]) largestIndex = leftChildIndex;

			int rightChildIndex = rightChildIndexOf(i);
			if (rightChildIndex < size && data[rightChildIndex] > data[i]) largestIndex = rightChildIndex;
		} while (largestIndex != i);
		
	}

	void removeMax() {
		if (data.size() == 0) return;

		data.erase(data.begin());
		data.insert(data.begin(), data[data.size() - 1]);
		data.erase(data.end() - 1);
		
		heapifyDown(0);
	}

	void print() {
		for (auto i = data.begin(); i != data.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
	}

	int parentIndexOf(int index) {
		return (index - 1) / 2;
	}

	int leftChildIndexOf(int index) {
		return (index * 2) + 1;
	}

	int rightChildIndexOf(int index) {
		return (index * 2) + 2;
	}
	
};


int main()
{
	return 0;
}
