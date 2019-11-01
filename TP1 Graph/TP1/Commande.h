//********************************************************************************
// Nom         : Commande.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : Permet à l'utilisateur de placer une commande d'objet
//********************************************************************************

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> // convertir les string en int


using namespace std;

class Commande
{
	public:
	// Constructeur
	Commande() : nObjetsA(0), nObjetsB(0), nObjetsC(0) {};
	// Destructeur
	~Commande();

	void reset();

	void prendreCommande();
	void afficherCommande();

	int nObjetsA;
	int nObjetsB;
	int nObjetsC;
};