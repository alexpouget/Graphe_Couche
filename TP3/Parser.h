#pragma once
#include <iostream>
#include "Graph.h"

template <typename T>
class Parser
{
public:
	Parser();
	Parser(std::string limite, std::string transition);
	~Parser();

	//crée une verif des fichiers qui redemande a l'infini si pas trouver
	Graph<T> Generate();

private:
	std::string limite;
	std::string transition;
	
};

