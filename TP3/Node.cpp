#include "Node.h"

using namespace std;

template<typename T>
Node<T>::Node()
{
	
}

template<typename T>
Node<T>::Node(T& c)
{
	content = c;
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
T Node<T>::getContent()
{
	return content;
}

template<typename T>
void Node<T>::setContent(const T& c)
{
	content = c;
}
/*
template<typename T>
void Node<T>::addEdge(Edge& edge)
{
	edgeList.push_back(edge);
}*/

template class Node<int>;