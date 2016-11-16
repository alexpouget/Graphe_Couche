#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"

class Edge;


class Node
{
public:
	Node();
	Node(int);
	~Node();

	int getContent();
	void setContent(const int&);
	void addEdge(Edge*);
	bool isFinal();
	void setFinal(const bool&);
	bool isInit();
	void setInit(const bool&);
	std::vector<Edge*> getEdgeList();
private:
	int content;
	std::vector<Edge*> edgeList;
	bool finish;
	bool init;
};


