#pragma once
#include <string>
#include <vector>

#include "Sommet.h"
#include "Graph.h"

using namespace std;

class Sommet;
class Graph;
class Arc
{
	public:
	
	// Constructeur
	Arc();
	// Constructeur parametre
	Arc(Sommet * sommets[2], int distance);

	// Destructeur
	~Arc();
	// Setters
	void setDistance(int distance);
	void setIdentifiant(string identifiant);

	// Vérifie s'il contient le sommet
	bool contains(Sommet* sommet);

	// Getters
	int getDistance() const;
	string getIdentifiant() const;
	Sommet** getSommets() const;

	private:
	int distance_; // distance entre Node 1 et Node 2
	string identifiant_; // Node1 - Node2 
	Sommet* sommets_[2]; // sommet_[0]== Node1 et sommet_[1]== Node2
};

