#pragma once
#include "Graph.h"
#include <iostream>

class Finder
{
public:
	Finder();
	~Finder();
	Finder(int&, int&, int*, int*);

	void plusCourtChemin(Graph&, std::ostream &);
	void Recherche(Graph&, std::ostream &);
	void r(std::vector<Edge*>);
private:
	int* minimal;
	int* maximal;
	int size;
	int alphabet;
};

