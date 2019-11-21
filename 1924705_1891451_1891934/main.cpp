//********************************************************************************
// Nom         : main.cpp
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : Main du programme
//********************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

#include "Graph.h"
#include "Sommet.h"
#include "Chemin.h"
#include "Commande.h"
#include <stdlib.h>

using namespace std;

void afficherMenu();

int main()
{
	// Permet l'affichage des accents
	setlocale(LC_ALL, "");

	// Initialisation des variables
	bool quit = false;
	int option;
	bool first = false;

	// Initialisation des objets
	Graph graphe;
	string nomFichier = "entrepot.txt";
	Commande commande;
	Chemin chemin;
	
	while (!quit) {
		system("CLS");
		afficherMenu();

		cin >> option;
		switch (option)
		{
		case 1: {
			if (!first) {
				graphe.creerGraphe(nomFichier);
				first = true;
			}
			break;
		}
		case 2: {
			graphe.afficherGraphe();
			break;
		}
		case 3: {
			commande.prendreCommande();
			break;
		}
		case 4: {
			commande.afficherCommande();
			break;
		}
		case 5: {
			chemin.setCommand(commande);
			chemin.setGraph(graphe);
			chemin.plusCourtChemin(0); //Le point de depart et d'arriver est toujours le noeud 0.
			chemin.reset();
			break;
		}
		case 6: {
			quit = true;
			break;
		}
		default:
			break;
		}
		system("pause");
	}
	return 0;
}

// Menu principal
void afficherMenu()
{
	cout << "================================================" << endl << endl;
	cout << "1. Cr�er le graphe." << endl;
	cout << "2. Afficher le graphe." << endl;
	cout << "3. Prendre une commande." << endl;
	cout << "4. Afficher la commande." << endl;
	cout << "5. Trouver le plus court chemin." << endl;
	cout << "6. Quitter." << endl << endl;
	cout << "================================================" << endl << endl;
	cout << "Choisir une des options en haut :" << endl << endl;
}