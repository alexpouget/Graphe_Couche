#pragma once
#include "Node.h"

template <typename T>
class Edge
{
public:
	//Edge(Node<T>*, Node<T>*, int);
	Edge();
	~Edge();

	//T* getDestination();
	int getCost();

private:
	//Node<T>* from;
	//Node<T>* to;
	int cost;
};

