#pragma once
#include <list>
#include "Graph.h"

class GraphDirectedList : public Graph {
public:
	GraphDirectedList(int size) : Graph(size) {}

	void addEdge(int from, int to) {
		adjacencies[from].push_back(to);
	}
};