
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

	// V�rifie si le sommet est connect�
	bool isConnectedTo(Sommet* sommet); // utiliser dan getDistance

	int getDistanceTo(Sommet* sommet); // needed by Kader // avoir la disatnce entre deux noeud

	// V�rifie s'il a le voisin

	// Getters
	int getNumero();
	int getNbObjetA();
	int getNbObjetB();
	int getNbObjetC();

	//Setters
	void setNbObjetA(int nb);
	void setNbObjetB(int nb);
	void setNbObjetC(int nb);

	private:
	vector<Objet> vectorObjet_; // a voir quelle data structure on utilise pour les objets pour faciliter le calcul au maximum!
	vector<Arc*> vectorArc_;
	int numero_;
	int nbObjetA_;
	int nbObjetB_;
	int nbObjetC_;
};

