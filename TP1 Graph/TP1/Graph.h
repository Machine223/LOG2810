
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

	void afficherGraphe(vector<Sommet> graphe);
	void prendreCommande();
	void afficherCommande();
	Sommet getSommet(int id); // Function needed
	Sommet* getReferenceSommet(int id);
	//void updateSommetObjects(vector<int> objects);

	private:
	Sommet* trouverSommet(const string& numero);
	void viderGraphe();
	int findNext(Sommet noeud);
	vector<Sommet*> tabSommets_;
	vector<Arc*> tabArcs_;
};

