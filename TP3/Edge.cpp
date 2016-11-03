#include "Edge.h"
/*
template<typename T>
Edge<T>::Edge(Node<T>* f, Node<T>* t, int c)
{
	from = f;
	to = t;
	cost = c;
}
*/
template<typename T>
Edge<T>::Edge()
{
	cost = 0;
	//to = nullptr;
	//from = nullptr;
}

template<typename T>
Edge<T>::~Edge()
{
}

/*template<typename T>
T * Edge<T>::getDestination()
{
	return to;
}*/

template<typename T>
int Edge<T>::getCost()
{
	return cost;
}

template class Edge<int>;
