
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Arc.h"
#include "Robot.h"
#include "Graph.h"
#include "Objet.h"

using namespace std;

class Arc;
class Sommet
{
	public:
	// Constructeur
	Sommet(int numero, int nbObjetA , int nbObjetB, int nbObjetC);
	// Destructeur
	~Sommet();

	// Ajoute un voisin
	void ajouterVoisin(Arc* voisin);

	// Vérifie si le sommet est connecté
	bool isConnectedTo(Sommet* sommet);

	int getDistanceTo(Sommet* sommet);	

	// Getters
	int getNumero() const;
	int getNbObjetA()const;
	int getNbObjetB()const;
	int getNbObjetC()const;
	vector<Sommet*> getVoisin() const; // retourne un vecteur de sommets voisins

	//Setters
	void setNbObjetA(int nb);
	void setNbObjetB(int nb);
	void setNbObjetC(int nb);

	private:
	vector<Arc*> vectorArcVoisin_;
	int degre_;
	int numero_;
	int nbObjetA_;
	int nbObjetB_;
	int nbObjetC_;
};

