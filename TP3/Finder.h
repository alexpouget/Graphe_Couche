#pragma once
#include "Graph.h"
#include <iostream>

class Finder
{
public:
	Finder();
	~Finder();
	Finder(Finder const & source);
	Finder(int&, int&, std::vector<int>, std::vector<int>);

	void plusCourtChemin(Graph&, std::ostream &);
	void Recherche(Graph&, std::ostream &);
	int getAlphabet();
	int getSize();
	std::vector<Edge> r(std::vector<Edge>, std::vector<int>,Graph);
	bool minLetter(std::vector<int> util);
	int getCost(std::vector<Edge> v);
private:
	std::vector<int> minimal;
	std::vector<int> maximal;
	int size;
	int alphabet;
};

