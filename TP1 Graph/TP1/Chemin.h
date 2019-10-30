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
#define POIDS_A 1;
#define POIDS_B 3;
#define POIDS_C 6;


using namespace std;

class Chemin
{
	public:
	// Constructeur
		Chemin(vector<int> command, Graph graph);
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
	void calculateTime(vector<int> path);


	Graph graph_;
	vector<int> commande;
	vector<vector<int>> objetsRecolt;
	vector<int> pathBoolean;
	vector<int>	Paths;
	string RobotPlusRapide;
	double Time;
	int Masse;

	int graphSize;
	int Emergency = -1;
	int nObjectsType=3;
};

