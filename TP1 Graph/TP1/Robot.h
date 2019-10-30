#pragma once
#include <string>

#include "Graph.h"
#include "Sommet.h"

using namespace std;

const double MASSE_MAX_X = 5.0;
const double MASSE_MAX_Y = 10.0;
const double MASSE_MAX_Z = 25.0;
const double CONSTANTE_X = 1.0;
const double CONSTANTE_Y = 1.5;
const double CONSTANTE_Z = 2.5;
const double FORCE_X = 1.0;
const double FORCE_Y = 0.6;
const double FORCE_Z = 0.2;

class Sommmet;
class Arc;
class Robot
{
	public:
	// Constructeur par défaut
	Robot();
	// Constructeur par paramètres
	Robot(string type);	

	// Destructeur
	~Robot();

	// Setters
	

	// Getters
	double getConstante() const;
	double getMassTotal() const;
	double getMassMax() const;

	// Cacul de temps 
	double calculerKx(); // calcul de la distance 
	//double calculDistance(Sommet* sommet1, Sommet* sommet2);
	double calculerT();

	private:

	double massTotal_;	// masse accumuler dans le robot si celle ci est attein doit revenir au point de depart, voir si on on peut faire un parcours double
	double masseMax_;	// masse maximal pouvant etre porter	X = 5 Y = 10 Z = 25 
	double constante_;	// contante de calcul de la distance	X = 1 Y = 1.5 Z = 2.5 
	double force_;		// constance de calcul de la distance	X = 1 Y = 0.6 Z = 0.2 
	char type_;		// X Y Z 
};

