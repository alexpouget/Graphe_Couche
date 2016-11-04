#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"

class Edge;

class Node
{
public:
	Node();
	Node(int&);
	~Node();

	int getContent();
	void setContent(const int&);
	//void addEdge(Edge<T>&);
	
private:
	int content;
	Edge* edge;
	//vector<Edge<T>> edgeList;
};


