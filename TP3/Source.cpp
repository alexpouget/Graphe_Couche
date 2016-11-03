#include <iostream>
#include <string>
#include "Parser.h"
#include "Node.h"

using namespace std;

void Help();
void Cmd(char& choice);

int main() {
	cout << "Bonjour bienvenue : " << endl << endl;
	
	/*
	cout << "nom du fichier contenant les limites : " << endl;
	string limites;
	getline(cin, limites);
	cout << "nom du fichier contenant les transitions : " << endl;
	string transition;
	getline(cin, transition);
	
	Parser parser(limites, transition);*/
	Parser<int> parser("test8_limite.afdC", "test8.afdC");
	Graph<int> graph = parser.Generate();

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
		break;
	case 'F':
		cout << "Execution fichier" << endl;
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