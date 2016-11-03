#pragma once
#include <iostream>
#include <vector>
//#include "Edge.h"


template <typename T>
class Node
{
public:
	Node();
	Node(T&);
	~Node();

	T getContent();
	void setContent(const T&);
	//void addEdge(Edge<T>&);
	
private:
	T content;
	//vector<Edge<T>> edgeList;
};


