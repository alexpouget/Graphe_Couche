#include "Edge.h"


Edge::Edge(Node* f, Node* t, int c,int l)
{
	from = f;
	to = t;
	cost = c;
	letter = l;
}


Edge::Edge()
{
	cost = 0;
	to = nullptr;
	from = nullptr;
}

Edge::Edge(Edge const& source)
{
	from = new Node(*(source.from));
	to = new Node(*(source.to));
	cost = source.cost;
	letter = source.letter;
}


Edge::~Edge()
{
}


Node * Edge::getDestination()
{
	return to;
}

Node * Edge::getFrom()
{
	return from;
}


int Edge::getCost()
{
	return cost;
}

int Edge::getLetter()
{
	return letter;
}

void Edge::print(std::ostream & stream)
{
	stream << "from : " << from->getContent()
		<< " to : " << to->getContent() << std::endl;
	
}
