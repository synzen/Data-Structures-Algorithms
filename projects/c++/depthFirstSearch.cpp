#include <iostream>
#include <vector>
#include "Graph.h"

void _visitNode(Graph graph, int start, bool* visited, std::vector<int>* order) { // Last parameter is purely to record the order of elements visited
	visited[start] = true;
	order->push_back(start);

	for (int i : graph.adjacencies[start]) {
		if (!visited[i]) _visitNode(graph, i, visited, order);
	}
}

std::vector<int> depthFirstSearch(Graph graph, int start) {
	std::list<int>* adjacencies = graph.adjacencies;
	bool *visited = new bool[graph.length];
	for (int i = 0; i < graph.length; ++i) {
		visited[i] = false;
	}

	std::vector<int> order;
	_visitNode(graph, start, visited, &order);
	return order;
}

