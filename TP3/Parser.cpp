#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

Graph Parser::generateGraph()
{
	Graph graph;
	string line;
	int count = 0;
	int nb_etat = 0;
	int init_node = 0;
	int nb_final = 0;
	int nb_edge = 0;
	vector<int> final_node;

	ifstream inTransition;
	inTransition.open(transition);
	while (inTransition) {
		getline(inTransition, line);
		cout << line << endl;
		
		//change t switch
		if (1 == count) {
			nb_etat = atoi(line.c_str());
			for (int i = 0; i < nb_etat; i++) {
				Node n(i+1);
				graph.addNode(n);
				
			}
		}
		if (2 == count) {
			init_node = atoi(line.c_str());
			Node* n;
			n = graph.getNode(line);
			n->setInit(true);
		}
		if (3 == count) {
			nb_final = atoi(line.c_str());
		}
		if (4 == count) {
			string num = "";
			Node* n;
			for (int i = 0; i < line.size(); i++) {
				if (' ' == line[i]) {
					final_node.push_back(atoi(num.c_str()));
					n = graph.getNode(num);
					n->setFinal(true);
					num = "";
					continue;
				}
				num += line[i];
			}
		}
		if (5 == count) {
			nb_edge = atoi(line.c_str());
		}
		if (count > 5) {
			
			int cost = 0;
			int letter = 0;
			Node* from;
			Node* to;
			int c = 0;
			string num = "";
			for (int i = 0; i < line.size(); i++) {
				if (' ' == line[i]) {
					if (0 == c) {
						letter = atoi(num.c_str());
					}
					if (1 == c) {
						from = graph.getNode(num);
					}
					if (2 == c) {
						to = graph.getNode(num);
					}
					if (3 == c) {
						cost = atoi(num.c_str());
					}
					
					num = "";
					c++;
					continue;
				}
				num += line[i];	
				
			}
			if (cost == 0) {
				cost = atoi(num.c_str());
			}
			if (0 == cost && 0==letter) {
				break;
			}
			Edge edge(from, to, cost,letter);
			from->addEdge(edge);

		}
		count++;
	}
	inTransition.close();
	
	return graph;
}

Finder Parser::generateFinder()
{
	string line;
	int size = 0;
	int alphabet = 0;

	cout << "limite : " << endl;
	ifstream inLimite;
	inLimite.open(limite);
	getline(inLimite, line);//first line aplphabet
	alphabet = atoi(line.c_str());
	getline(inLimite, line);//second line size mot
	size = atoi(line.c_str());

	//tableau
	std::vector<int> min;
	std::vector<int> max;
	
	getline(inLimite, line);
	cout << line << endl;
	string num = "";
		
	for (int i = 0; i < line.size(); i++) {
		if (' ' == line[i]) {
			min.push_back(atoi(num.c_str()));
			num = "";
			continue;
		}
		num += line[i];
	}
	min.push_back(atoi(num.c_str()));
	
	getline(inLimite, line);
	cout << line << endl;
	num = "";

	for (int i = 0; i < line.size(); i++) {
		if (' ' == line[i]) {
			max.push_back(atoi(num.c_str()));
			num = "";
			continue;
		}
		num += line[i];
	}
	max.push_back(atoi(num.c_str()));
	inLimite.close();

	return Finder(size,alphabet,min,max);
}

