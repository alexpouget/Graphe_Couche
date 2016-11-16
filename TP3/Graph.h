#pragma once
#include <map>
#include <iostream>
#include <string>
#include "Node.h"

class Graph
{
public:
	Graph();
	~Graph();

	void addNode(Node&);
	void listNode(std::ostream&);

	Node* getNode(std::string);
private:
	std::map<std::string, Node> nodeList;
};

