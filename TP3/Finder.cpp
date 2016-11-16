#include "Finder.h"
#include "Edge.h"
#include <string>

using namespace std;

Finder::Finder()
{
}


Finder::~Finder()
{
}

Finder::Finder(int & size, int & alphabet, int * min, int *max)
{
	this->size = size;
	this->alphabet = alphabet;
	minimal = new int[alphabet];
	maximal = new int[alphabet];
	for (int i = 0; i < alphabet; i++) {
		minimal[i] = min[i];
		maximal[i] = max[i];
	}
}

void Finder::plusCourtChemin(Graph &graph, std::ostream & out)
{
	
}

void Finder::Recherche(Graph & graph, ostream & out)
{
	Node* startNode;
	int count = 1;
	do
	{
		startNode = graph.getNode(to_string(count));
		count++;
	} while (!startNode->isInit());
	out << startNode->getContent() << endl;

	
	for each (Edge* var in startNode->getEdgeList())
	{
		vector<Edge*> v;
		v.push_back(var);
		r(v);
	}
	


}

void Finder::r(vector<Edge*> result) {
	if (result[result.size() - 1]->getDestination()->isFinal()) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " - ";
		}
		cout << endl;
	}
	for each (Edge* var in result[result.size() - 1]->getDestination()->getEdgeList())
	{
		vector<Edge*> v;
		v.push_back(var);
		r(v);
	}

}
