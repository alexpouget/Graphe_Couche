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

void Finder::rechercheEdge(Graph &graph, int start, int end)
{
	Node* startNode,*endNode;
	startNode = graph.getNode(to_string(start));
	endNode = graph.getNode(to_string(end));
	vector<Edge> eresult;
	vector<Edge> retour;
	int cost = 0;
	for each (Edge var in startNode->getEdgeList())
	{
		vector<Edge> v;
		v.push_back(var);
		eresult = findEdge(v, graph, endNode);
		if (!eresult.empty()) {
			if (cost == 0 || cost > getCost(eresult)) {
				cost = getCost(eresult);
				retour = eresult;
			}
		}
	}
	if (!retour.empty()) {
		cout << " cost = " << cost << endl;
		cout << " chemin " << endl;
		cout << retour[0].getFrom()->getContent();
		for (int i = 0; i < retour.size(); i++) {
			cout << " - " << retour[i].getDestination()->getContent();
		}
		cout << endl << " lettre lu " << endl;
		for (int i = 0; i < retour.size(); i++) {
			cout << " - " << retour[i].getLetter();
		}
		cout << endl << endl;
	}
	
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
	out << "start node : "<< startNode->getContent() << endl;

	vector<Edge> eresult;
	vector<Edge> retour;
	int cost = 0;
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
			if (cost == 0 || cost > getCost(eresult)) {
				cost = getCost(eresult);
				retour = eresult;
			}
		}
	}
	if (!retour.empty()) {
		out << " cost = "<<cost<<endl;
		out << " chemin " << endl;
		out << retour[0].getFrom()->getContent();
		for (int i = 0; i < retour.size(); i++) {
			out <<" - " << retour[i].getDestination()->getContent();
		}
		out << endl << " lettre lu " << endl;
		for (int i = 0; i < retour.size(); i++) {
			out << " - " << retour[i].getLetter();
		}
		out << endl << endl;
	}
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

int Finder::getAlphabet()
{
	return alphabet;
}

int Finder::getSize()
{
	return size;
}

std::vector<Edge> Finder::findEdge(std::vector<Edge> result, Graph graph, Node *end)
{
	vector<Edge> retour;
	if (*result[result.size()-1].getDestination() == *end){
		return result;
	}
	else if (result.size() < getSize() && !graph.getNode(to_string(result[result.size() - 1].getDestination()->getContent()))->getEdgeList().empty())
	{
		vector<Edge> res;
		int cost = 0;
		for each (Edge var in graph.getNode(to_string(result[result.size() - 1].getDestination()->getContent()))->getEdgeList())
		{
			vector<Edge> tmp = result;
			tmp.push_back(var);
			res = findEdge(tmp,graph,end);
			if (!res.empty() && (cost == 0 || cost > getCost(res))) {
				retour = res;
				cost = getCost(retour);
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
		count += v[i].getCost();
	}
	return count;
}
