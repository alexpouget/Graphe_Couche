#pragma once
#include <iostream>
#include "Graph.h"

class Parser
{
public:
	Parser();
	Parser(std::string limite, std::string transition);
	~Parser();

	//crée une verif des fichiers qui redemande a l'infini si pas trouver
	Graph Generate();

private:
	std::string limite;
	std::string transition;
	
};

