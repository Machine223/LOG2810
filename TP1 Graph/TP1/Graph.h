
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

		vector<vector<int>> objets_;
		vector<vector<int>> arcs_;
		vector<Sommet> graph_;
		int graphSize_;


		// Constructeur
		Graph();

		// Destructeur
		~Graph();

		void creerGraphe(const string& nomFichier);

		void afficherGraphe();

};

