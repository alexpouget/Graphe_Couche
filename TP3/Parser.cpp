#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Parser::Parser()
{
	
}

Parser::Parser(string l, string t)
{
	limite = l;
	transition = t;
}


Parser::~Parser()
{
}

Graph Parser::Generate()
{
	string line;

	ifstream inTransition(transition);
	while (inTransition) {
		getline(inTransition, line);
		cout << line << endl;
	}
	inTransition.close();

	ifstream inLimite(limite);
	while (inLimite) {
		getline(inLimite, line);
		cout << line << endl;
	}
	inLimite.close();

	return Graph();
}
