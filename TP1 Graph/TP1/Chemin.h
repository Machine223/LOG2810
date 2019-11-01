//********************************************************************************
// Nom         : Chemin.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : représente notre calcul du meilleur chemin pour récuperer les objets
//********************************************************************************

#include <string>
#include <vector>
#include "Graph.h"
#include "Commande.h"

#include <vector>
#include <algorithm>
#define POIDS_A 1;
#define POIDS_B 3;
#define POIDS_C 6;


using namespace std;

class Chemin
{
	public:
	// Constructeur
	Chemin();
	// Constructeur par parametre
	Chemin(Commande command, Graph graph);
	//Destructeur
	~Chemin();

	void plusCourtChemin(int departurePoint); // Dijkstra
	void calculRobotRapide();
	void reset();

	void setCommand(Commande command);
	void setGraph(Graph graph);

	int shortestDistance(vector<int> distance, vector<bool> isTheShortest);
	int minRestObjectsAndDistance(vector<int> arr, vector<int> distance);
	int printSolution(vector<int> dist);
	vector<int> dijkstra(int src);
	void updateGraph(vector<int> path);
	void calculateTime(int D);


	Graph graph_;
	Commande commande;
	vector<vector<int>> objetsRecolt;
	vector< int> pathBoolean;
	vector< int>	Paths;
	string RobotPlusRapide;
	double Time;
	int Masse;

	int graphSize;
	int Emergency = -1;
	int nObjectsType=3;
};

