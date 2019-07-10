#pragma once
#include <list>

class Graph {
public:
	std::list<int>* adjacencies;
	int length;
	Graph(int num) : adjacencies(new std::list<int>[num]), length(num) {} // List of lists

	void addEdge(int from, int to);
};