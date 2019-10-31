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

	int nObjetsA;
	int nObjetsB;
	int nObjetsC;


	// Constructeur
	Commande() : nObjetsA(0), nObjetsB(0), nObjetsC(0) {};
	// Destructeur
	~Commande();

	void reset();

	void prendreCommande();
	void afficherCommande();

};