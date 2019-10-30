
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


	// Setters
	void setNoeud(int numero, int a, int b, int c);

	// Ajoute un voisin
	void ajouterVoisin(Arc* voisin);

	// Vérifie si le sommet est connecté
	bool isConnectedTo(Sommet* sommet);

	int getDistanceTo(Sommet* sommet); // needed by Kader

	// Vérifie s'il a le voisin

	// Getters
	int getNumero();
	int getNbObjetA();
	int getNbObjetB();
	int getNbObjetC();

	//Setters
	int setNbObjetA(int nb);
	int setNbObjetB(int nb);
	int setNbObjetC(int nb);

	private:
	vector<Objet> vectorObjet_; // a voir quelle data structure on utilise pour les objets pour faciliter le calcul au maximum!
	vector<Arc*> vectorArc_;
	int numero_;
	int nbObjetA_;
	int nbObjetB_;
	int nbObjetC_;
};

