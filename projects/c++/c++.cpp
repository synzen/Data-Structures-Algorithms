#include <iostream>
#include "insertionSort.h"
#include "quickSort.h"
#include "GraphDirectedList.h"
#include "depthFirstSearch.h"
#include "breadthFirstSearch.h"

using namespace std;

int main()
{
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
	
	vector<int> dOrder = depthFirstSearch(graph, 2);
	vector<int> bOrder = breadthFirstSearch(graph, 2);
	for (auto i : bOrder) {
		cout << i << " ";
	}
}
