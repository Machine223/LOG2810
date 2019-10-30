#pragma once
#include <string>
#include <vector>

#include "Sommet.h"
#include "Robot.h"
#include "Graph.h"

using namespace std;

class Sommet;
class Graph;
class Arc
{
	public:
	// Destructeur
	~Arc();

	// Constructeur
	Arc();
	// Constructeur parametre
	Arc(Sommet * sommets[2], int distance);

	// Setters
	void setDistance(int distance);
	void setIdentifiant(string identifiant);

	

	// Vérifie s'il contient le sommet
	bool contains(Sommet* sommet);

	// Getters
	int getDistance() const;
	string getIdentifiant() const;
	Sommet* getTerminal(Sommet* sommetOrigine) const;
	Sommet** getSommets() const
	{
		return (Sommet**)sommets_;
	}

	private:
	int distance_;
	string identifiant_;
	Sommet* sommets_[2];
};

