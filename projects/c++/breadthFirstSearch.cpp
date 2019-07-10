#include <vector>
#include <queue>
#include "Graph.h"

std::vector<int> breadthFirstSearch(Graph graph, int start) {
	bool* visited = new bool[graph.length];
	for (int i = 0; i < graph.length; ++i) {
		visited[i] = false;
	}

	std::vector<int> order;
	
	std::queue<int> toVisit;
	toVisit.push(start);
	
	while (toVisit.size() > 0) {
		int currentVertex = toVisit.front();
		visited[currentVertex] = true;
		order.push_back(currentVertex);
		for (auto vertex : graph.adjacencies[currentVertex]) {
			if (!visited[vertex]) toVisit.push(vertex);
		}
		toVisit.pop();
	}
	return order;
}
