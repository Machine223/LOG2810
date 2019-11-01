//********************************************************************************
// Nom         : Sommet.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : représente les sommets de notre graphe
//********************************************************************************

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Sommet
{
	public:
	
	Sommet();
	Sommet(int i, vector<int> arcList, vector<int> o);
	
	int id;
	vector<int> arcs_;
	vector<int> objects_;
};

