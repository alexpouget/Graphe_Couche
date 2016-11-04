#include "Edge.h"


Edge::Edge(Node* f, Node* t, int c)
{
	from = f;
	to = t;
	cost = c;
}


Edge::Edge()
{
	cost = 0;
	to = nullptr;
	from = nullptr;
}


Edge::~Edge()
{
}


Node * Edge::getDestination()
{
	return to;
}


int Edge::getCost()
{
	return cost;
}
