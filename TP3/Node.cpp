#include "Node.h"

using namespace std;


Node::Node()
{
	
}

Node::Node(int& c)
{
	content = c;
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


void Node::addEdge(Edge* e)
{
	edgeList.push_back(e);
}
