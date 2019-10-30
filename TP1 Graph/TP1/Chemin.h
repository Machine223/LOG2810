#pragma once
#include <string>
#include <vector>

#include "Graph.h"
#include "Robot.h"

#include <limits.h> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <stdio.h> 


using namespace std;

class Chemin
{
	public:
	// Constructeur
		Chemin();
	// Constructeur par paramètres

	// Destructeur
		~Chemin();

	void plusCourtChemin(int departurePoint); // Dijkstra
	void calculRobotRapide(Robot* robot);



private:

		int shortestDistance(vector<int> distance, vector<bool> isTheShortest);
		int minRestObjectsAndDistance(vector<int> arr, vector<int> distance);
		int printSolution(vector<int> dist);
		vector<int> dijkstra(int src);
		void updateGraph(vector<int> path);
		Graph graph_;
		vector<int> commande;
		vector<vector<int>> objetsRecolt;
		vector<int> pathBoolean;
		vector<int>	Paths;
		int graphSize;
		int Emergency = -1;
		int nObjectsType=3;
};

