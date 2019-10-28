
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

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
	void plusCourtChemin(const string& origine, const string& destination, Robot* vehicule); // Dijkstra


	private:
	Sommet* trouverSommet(const string& numero);
	void viderGraphe();
	int findNext(Sommet noeud);
	vector<Sommet*> tabSommets_;
	vector<Arc*> tabArcs_;
};

