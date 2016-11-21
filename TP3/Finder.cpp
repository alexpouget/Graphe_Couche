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

Finder::Finder(Finder const& source)
{
	maximal = source.maximal;
	minimal = source.minimal;
	
}

Finder::Finder(int & size, int & alphabet,std::vector<int> min,std::vector<int> max)
{
	this->size = size;
	this->alphabet = alphabet;
	minimal = min;
	maximal = max;
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

	vector<Edge> eresult;
	for each (Edge var in startNode->getEdgeList())
	{
		std::vector<int> util;
		for (int i = 0; i < alphabet; i++) {
			util.push_back(0);
		}
		vector<Edge> v;
		v.push_back(var);
		eresult = r(v,util,graph);
		if (!eresult.empty()) {
			//cout << eresult[0].getFrom()->getContent();
			for (int i = 0; i < eresult.size(); i++) {
				cout << " - " << eresult[i].getLetter();
					//<< eresult[i].getDestination()->getContent();
			}
			cout << endl << endl;
		}
	}
	


}

int Finder::getAlphabet()
{
	return alphabet;
}

int Finder::getSize()
{
	return size;
}

vector<Edge> Finder::r(vector<Edge> result, std::vector<int> util,Graph graph) {
	//s++;
	util[(result[result.size() - 1].getLetter())-1]++;
	vector<Edge> retour;
	if (result[result.size() - 1].getDestination()->isFinal() && result.size()==getSize() && minLetter(util)) {
		return result;
	}
	else if (result.size() < getSize() && !graph.getNode(to_string(result[result.size() - 1].getDestination()->getContent()))->getEdgeList().empty())
	{
		vector<Edge> res;
		int cost = 0;
		for each (Edge var in graph.getNode(to_string(result[result.size() - 1].getDestination()->getContent()))->getEdgeList())
		{
			vector<Edge> tmp = result;
			if (util[var.getLetter() - 1] < this->maximal[var.getLetter() - 1]) {
				tmp.push_back(var);
				res = r(tmp, util, graph);
				if (!res.empty() && (cost == 0 || cost > getCost(res))){
					retour = res;
					cost = getCost(retour);
				}
			}
		}	
	}
	return retour;
}

bool Finder::minLetter(vector<int> util) {
	for (int i = 0; i < alphabet; i++) {
		if (util[i] < minimal[i]) {
			return false;
		}
	}
	return true;
}

int Finder::getCost(vector<Edge> v) {
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		count = v[i].getCost();
	}
	return count;
}
