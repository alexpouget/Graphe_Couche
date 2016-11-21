#include <iostream>
#include <string>
#include <fstream>
#include "Parser.h"
#include "Node.h"

using namespace std;

void Help();
void Cmd(char& choice);
void writeFile();
Graph* graph;

int main() {
	cout << "Bonjour bienvenue : " << endl << endl;
	
	
	cout << "nom du fichier contenant les limites : " << endl;
	string limites;
	//getline(cin, limites);
	cout << "nom du fichier contenant les transitions : " << endl;
	string transition;
	//getline(cin, transition);
	
	//Parser parser(limites, transition);*/
	Parser parser("test23_limite.afdC", "test23.afdC");
	Graph graph2 = parser.generateGraph();
	
	Finder finder = parser.generateFinder();
	finder.Recherche(graph2, cout);
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
	cout << "P - Plus court chemin :  calculer le plus court chemin" << endl;
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
		break;
	case 'E':
		cout << "Execution ecrire" << endl;
		break;
	case 'R':
		cout << "Execution recherche" << endl;
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