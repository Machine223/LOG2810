//********************************************************************************
// Nom         : Graph.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : représente notre graph avec les sommets et les arcs
//********************************************************************************
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> // convertir les string en int

#include "Sommet.h"

using namespace std;

class Graph
{
	public:

	// Constructeur
	Graph();

	// Destructeur
	~Graph();

	void creerGraphe(const string& nomFichier);

	void afficherGraphe();
	int getNbMaxObjet(char objet);
	
	vector<vector<int>> objets_;
	vector<vector<int>> arcs_;
	vector<Sommet> graph_;
	int graphSize_;
};

