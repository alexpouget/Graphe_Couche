#include <iostream>
#include <string>
#include <fstream>
#include "Parser.h"
#include "Node.h"

using namespace std;

void Help();
void Cmd(char& choice);
void writeFile();
void writeShortPath();
void recherche();
Graph* graph;
Finder finder;

int main() {
	cout << "Bonjour bienvenue : " << endl << endl;
	
	
	cout << "nom du fichier contenant les limites : " << endl;
	string limites;
	//getline(cin, limites);
	cout << "nom du fichier contenant les transitions : " << endl;
	string transition;
	//getline(cin, transition);
	
	//Parser parser(limites, transition);*/
	Parser parser("test11limite.afdC", "test11.afdC");
	Graph graph2 = parser.generateGraph();
	finder = parser.generateFinder();
	graph = &graph2;
	Help();
	
	system("PAUSE");
	return 0;
}

//affiche les commande à l'ecran
void Help() {
	cout << "Commande disponible : " << endl;
	cout << "H - Help : affiche la liste des commandes" << endl;
	cout << "G - Graphe : afficher a l'ecran les noeuds" << endl;
	cout << "F - Fichier : ecrit les noeuds dans un fichier" << endl;
	//cout << "P - Plus court chemin :  calculer le plus court chemin" << endl;
	cout << "A - Afficher : afficher les plus courts chemins" << endl;
	cout << "E - Ecrire : ecrire dans un fichier" << endl;
	cout << "R - Recherche : recherche arrete" << endl;
	cout << "Q - Quitter :  Quitte le programme" << endl << endl;

	char choice;
	cin >> choice;
	cin.ignore(cin.rdbuf()->in_avail(), '/n'); // vide le buffer de cin technique recommandée
	cin.clear();
	cout << endl;
	cout << "vous avez choisi : " << choice << endl<< endl;
	Cmd(choice);
}

//traite les commandes entrées
void Cmd(char& choice) {
	if (96 < choice && 123 > choice) {
		choice = choice - 32;
	}
	switch (choice)
	{
	case 'H':
		cout << "Execution help"<< endl;
		Help();
		break;
	case 'G':
		cout << "Execution graphe" << endl;
		graph->listNode(cout);
		Help();
		break;
	case 'F':
		cout << "Execution fichier" << endl;
		writeFile();
		Help();
		break;
	case 'P':
		cout << "Execution plus court chemin" << endl;
		break;
	case 'A':
		cout << "Execution afficher" << endl;
		finder.Recherche(*graph, cout);
		Help();
		break;
	case 'E':
		cout << "Execution ecrire" << endl;
		writeShortPath();
		Help();
		break;
	case 'R':
		cout << "Execution recherche" << endl;
		recherche();
		Help();
		break;
	case 'Q':
		cout << "Execution quitter" << endl;
		exit(0);
		break;
	default:
		cout << "Commande inconnue" << endl;
		Help();
		break;
	}
}

void writeFile() {
	ofstream out;
	out.open("out.txt");
	graph->listNode(out);
	out.close();
	cout << "noeud ecris dans fichier out.txt" << endl << endl;
}

void writeShortPath()
{
	ofstream out;
	out.open("out.txt");
	finder.Recherche(*graph, out);
	out.close();
	cout << "plus court chemin ecris dans fichier out.txt" << endl << endl;
}

void recherche() {
	cout << "point de depart : " << endl;
	string start;
	getline(cin, start);
	
	cout << "point d'arrivé : " << endl;
	string end;
	getline(cin, end);
	cout << endl << endl; 
	int nstart = atoi(start.c_str());
	int nfin = atoi(end.c_str());
	finder.rechercheEdge(*graph, nstart, nfin);
}
