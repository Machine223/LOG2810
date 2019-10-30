
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> // convertir les string en int

#include "Arc.h"
#include "Sommet.h"
#include "Objet.h"
#include "Robot.h"

using namespace std;

class Sommet;
class Arc;
class Graph
{
	public:
	// Constructeur
	Graph();

	// Constructeur par copie
	Graph(const Graph& graphe);

	// Destructeur
	~Graph();

	void creerGraphe(const string& nomFichier);

	void afficherGraphe();
	//void prendreCommande();	// A faire
	//void afficherCommande();  // A faire
	Sommet getSommet(int numero); 
	//Sommet* getReferenceSommet(int id);
	//void updateSommetObjects(vector<int> objects);

	private:
	Sommet* trouverSommet(const string& numero);
	//void viderGraphe(); // A faire
	//int findNext(Sommet noeud);
	std::vector<Sommet *> tabSommets_;
	std::vector<Arc*> tabArcs_;
	int size_;// added
};

