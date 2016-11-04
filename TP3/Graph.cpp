#include "Graph.h"


Graph::Graph()
{

}

Graph::~Graph()
{
}

void Graph::addNode(Node& n)
{
	nodeList.insert({ std::to_string(n.getContent()), n });
}

void Graph::listNode(std::ostream & stream)
{
	for (std::map<std::string, Node>::iterator it = nodeList.begin(); it != nodeList.end(); it++) {
		stream << it->second.getContent() << std::endl;
	}
}

