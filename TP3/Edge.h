#pragma once
#include "Node.h"

class Node;

class Edge
{
public:
	Edge(Node*, Node*, int);
	Edge();
	~Edge();

	Node* getDestination();
	int getCost();

private:
	Node* from;
	Node* to;
	int cost;
};

