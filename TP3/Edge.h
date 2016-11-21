#pragma once
#include "Node.h"

class Node;

class Edge
{
public:
	Edge(Node*, Node*, int,int);
	Edge();
	Edge(Edge const&);
	~Edge();

	Node* getDestination();
	Node * getFrom();
	int getCost();
	int getLetter();
	void print(std::ostream & stream);
	

private:
	Node* from;
	Node* to;
	int cost;
	int letter;
};

