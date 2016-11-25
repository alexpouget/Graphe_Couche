#include "Node.h"

using namespace std;


Node::Node()
{
	
}

Node::Node(int c)
{
	content = c;
	init = false;
	finish = false;
}



Node::~Node()
{
}

int Node::getContent()
{
	return content;
}


void Node::setContent(const int& c)
{
	content = c;
}


void Node::addEdge(Edge e)
{
	edgeList.push_back(e);
}

bool Node::isFinal()
{
	return finish;
}

void Node::setFinal(const bool &f)
{
	finish = f;
}

bool Node::isInit()
{
	return init;
}

void Node::setInit(const bool &i)
{
	init = i;
}

std::vector<Edge> Node::getEdgeList()
{
	return edgeList;
}

bool Node::operator==(const Node & other) const
{
	if (content == other.content) {
		return true;
	}
	return false;
}
