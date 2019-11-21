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
	
	Chemin(); // Constructor
	Chemin(Commande command, Graph graph);
	~Chemin();

	void plusCourtChemin(int pointDepart); // give the shortest path to collect the objects
	void calculRobotRapide(); // give the fast robot
	void reset(); // reset the class attributes

	void setCommand(Commande command); // set the "commande" attribute
	void setGraph(Graph graph); // set the gaph_ attribute

	
	

private:


	Graph graph_; // the graph
	Commande commande; // the command
	vector<vector<int>> objetsRecolt; // Objects collected by the robot taking a specific way
	vector< int> pathBoolean; // Path taken to get to a specific vertex
	
	string RobotPlusRapide; //  X Y or Z
	double Time; // in seconds
	double Masse; // represent the weight lifted by the robot in its traject

	int graphSize; //total number of vertices
	int Emergency = -1; // used in case where a shortest path found combaining two other vertices
	int nObjectsType=3; // total number of object types

	int shortestDistance(vector<int> distance, vector<bool> isTheShortest); //find the minimum value in an array
	int minRestObjectsAndDistance(vector<int> arr, vector<int> distance); //choose the most appropriate vertex
	vector<int> dijkstra(int src);  // Dijkstra
	void updateGraph(vector<int> path); // Update the graph with new values after the robot has been lift the objects
	void calculateTime(double D); // Calculate the time spent by the robot
};

