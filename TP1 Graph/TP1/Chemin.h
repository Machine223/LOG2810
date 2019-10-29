#pragma once
#include <string>
#include <vector>

#include "Graph.h"
#include "Robot.h"

using namespace std;

class Chemin
{
	public:
	// Constructeur
	Chemin();
	// Constructeur par paramètres

	// Destructeur
	~Chemin();

	void plusCourtChemin(const string& origine, const string& destination, Robot* robot); // Dijkstra
	void calculRobotRapide(Robot* robot);

	private:

};

