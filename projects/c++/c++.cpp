#include <iostream>
#include "insertionSort.h"
#include "quickSort.h"
#include "GraphDirectedList.h"
#include "depthFirstSearch.h"
#include "breadthFirstSearch.h"
#include "binarySearch.h"
#include "heapSort.h"

using namespace std;

int main()
{
	cout << "Quicksort" << endl;
	int arr[5] = { 9,2,5,10,7 };
	quicksort(arr, 0, 4);
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	GraphDirectedList graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);
	graph.addEdge(2, 3);
	graph.addEdge(3, 3);
	
	cout << "Depth first search" << endl;
	vector<int> dOrder = depthFirstSearch(graph, 2);
	for (auto i : dOrder) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Breadth first search" << endl;
	vector<int> bOrder = breadthFirstSearch(graph, 2);
	for (auto i : bOrder) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Binary search" << endl;
	int sortedArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int index = binarySearch(sortedArr, 10, 0);
	cout << index << endl;

	cout << "Heap sort" << endl;
	int heapArr[7] = { 1,5,2,19,6,3 };
	vector<int> sorted = heapSort(heapArr, 5);
	for (auto i : sorted) {
		cout << i << " ";
	}
	cout << endl;

}
