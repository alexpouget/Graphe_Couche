#pragma once
#include <iostream>
#include "Graph.h"
#include "Finder.h"

class Parser
{
public:
	Parser();
	Parser(std::string limite, std::string transition);
	~Parser();

	//crée une verif des fichiers qui redemande a l'infini si pas trouver
	Graph generateGraph();
	Finder generateFinder();

private:
	std::string limite;
	std::string transition;
	
};

