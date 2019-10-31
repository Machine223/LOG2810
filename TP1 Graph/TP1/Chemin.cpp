#include "Chemin.h"
Chemin::Chemin()
{
	//Initiaizing  objetsRecolt
	graphSize = 0;
	Time = 0;
	Masse = 0;

}

Chemin::Chemin(Commande command, Graph graph)
{
	//Initiaizing  objetsRecolt
	graph_ = graph;
	graphSize = graph_.graphSize_;
	commande = command;
	for (int i = 0; i < graphSize; i++) {
		vector<int> tmp;
		for (int j = 0; j < nObjectsType; j++)
			tmp.push_back(0);
		objetsRecolt.push_back(move(tmp));
	}

	//Initiaizing  objetsRecolt
	for (int i = 0; i < graphSize; i++) {
		pathBoolean.push_back(0);
	}

	Time = 0;
	Masse = 0;
		
}

void Chemin::setCommand(Commande command)
{
	//Initiaizing  objetsRecolt
	commande = command;
}

void Chemin::setGraph(Graph graph)
{
	//Initiaizing  objetsRecolt
	graph_ = graph;
	graphSize = graph_.graphSize_;
	for (int i = 0; i < graphSize; i++) {
		vector<int> tmp;
		for (int j = 0; j < nObjectsType; j++)
			tmp.push_back(0);
		objetsRecolt.push_back(move(tmp));
	}

	//Initiaizing  objetsRecolt
	for (int i = 0; i < graphSize; i++) {
		pathBoolean.push_back(0);
	}


}

Chemin::~Chemin()
{
}

// return the shortest distance in a given table
int Chemin::shortestDistance(vector<int> distance, vector<bool> isTheShortest)
{
	// Initialization 
	int min = INT_MAX;
	int min_index = 0;

	for (int node = 0; node < graphSize; node++)
		if (isTheShortest[node] == false && distance[node] <= min) {
			min = distance[node];
			min_index = node;
		}
	return min_index;
}

// return the most optimized path to get the command, based on distance and number of objects
int Chemin::minRestObjectsAndDistance(vector<int> arr, vector<int> distance)
{
	int min = INT_MAX;
	int min_index = 0;
	int min_distance = INT_MAX;
	for (int node = 0; node < graphSize; node++) {
		if (arr[node] < min || (arr[node] == min && distance[node] < distance[min_index])) { // if two nodes have the same ammount 
			//of collected objects we choose the one with the smallest distance
			min = arr[node];
			min_index = node;
			min_distance = distance[min_index];
		}
	}

	// seeing if we can find two uncompleted commands which gives a shortest path than found
	for (int node1 = 0; node1 < graphSize; node1++)
		for (int node2 = 0; node2 < graphSize; node2++)
			if ((node2 != node1) && arr[node2] != 0 // node1 different from node2 and Restant[node2] different from 0
				&& ((2 * commande.nObjetsA - objetsRecolt[node1][0] - objetsRecolt[node2][0]) >= commande.nObjetsA)
				&& ((2 * commande.nObjetsB - objetsRecolt[node1][1] - objetsRecolt[node2][1]) >= commande.nObjetsB)
				&& ((2 * commande.nObjetsC - objetsRecolt[node1][2] - objetsRecolt[node2][2]) >= commande.nObjetsC)
				&& (distance[node1] + distance[node2]) < min_distance)
				if ((graph_.graph_[node1].arcs_[node2] == 0) && ((commande.nObjetsA - objetsRecolt[node1][0] + graph_.graph_[node2].objects_[0]) >= commande.nObjetsA)
					&& ((commande.nObjetsB - objetsRecolt[node1][1] + graph_.graph_[node2].objects_[1]) >= commande.nObjetsB)
					&& ((commande.nObjetsC - objetsRecolt[node1][2]) + graph_.graph_[node2].objects_[2] >= commande.nObjetsC))
						// if we have two adjacent vertices 
						min = arr[node1], min_index = node1, min_distance = (distance[node1] + distance[node2]), Emergency = node2;

	return min_index;
}

// A utility function to print the constructed distance array 
int Chemin::printSolution(vector<int> dist)
{
	printf("Vertex \t\t Distance \t\t Objets Reco \n");
	for (int i = 0; i < graphSize; i++)
		printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", i, dist[i], objetsRecolt[i][0], objetsRecolt[i][1], objetsRecolt[i][2]);
	return 0;
}

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
vector<int> Chemin::dijkstra(int src)
{
	vector<int> distance; // the output contain the shortest distance between node with index i and src
	vector<bool> isTheShortest; // isTheShortest[i] is set to true if the shortest path is found
	// Following the Algorithm of Dijkstra and initializing our output to Infinite and isTheShortest to false
	for (int i = 0; i < graphSize; i++) {
		distance.push_back(INT_MAX);
		isTheShortest.push_back(false);
	}
	// Distance of src from src is 0 
	distance[src] = 0;

	// Find shortest path for all nodes 
	for (int cpt = 0; cpt < graphSize; cpt++) {
		// get the shortest distance, in the beggining it's always src
		int min_index = shortestDistance(distance, isTheShortest);

		// Mark the picked node as processed 
		isTheShortest[min_index] = true;
		// Update the distance array values after the node has been picked. 
		for (int node = 0; node < graphSize; node++) {
			// Update distance[node] when its isTheShortest is false, there is an arc from 
			// min_index to node, and the distance from src to  node through min_index is smaller than distance[node] 

			int minDistTmp = distance[min_index] + graph_.graph_[min_index].arcs_[node];
			if (!isTheShortest[node] && graph_.graph_[min_index].arcs_[node] && distance[min_index] != INT_MAX && minDistTmp < distance[node]) {
				distance[node] = minDistTmp;
				pathBoolean[node] = min_index; // Saving the previous node to get to node within the shortest path so far
				objetsRecolt[node][0] = objetsRecolt[min_index][0] + graph_.graph_[node].objects_[0]; //ammount of objects collected from src to node
				objetsRecolt[node][1] = objetsRecolt[min_index][1] + graph_.graph_[node].objects_[1];
				objetsRecolt[node][2] = objetsRecolt[min_index][2] + graph_.graph_[node].objects_[2];
			}
		}

		
			

	}



	return distance;
}

// after each iteration where objects have been picked the objects values on the graph should be updated
void Chemin::updateGraph(vector<int> path)
{
	int c0, c1, c2; // command 0 to object of type A ...
	int tmp;
	int objetsPreleves;
	for (int i = path.size() - 1; i >= 0; i--) { //following the shortest path and picking objects
		if (i != (path.size() - 1)) { //point de depart
			calculateTime(graph_.graph_[path[i]].arcs_[path[i+1]]);
		}
		Sommet node = graph_.graph_[path[i]];
		//cout << "commande" << commande[0] << commande[1] << commande[2];
		c0 = commande.nObjetsA - node.objects_[0];
		c1 = commande.nObjetsB - node.objects_[1];
		c2 = commande.nObjetsC - node.objects_[2];
		commande.nObjetsA = ((c0) < 0) ? 0 : (c0);
		tmp = ((-c0) < 0) ? 0 : (-c0);
		objetsPreleves = node.objects_[0] - tmp;
		if (objetsPreleves != 0) { // un prelevement de poids a été effectué
			Time += objetsPreleves * 10; // temps de prelevement
			Masse += objetsPreleves * POIDS_A;
			graph_.graph_[path[i]].objects_[0] = tmp;
		}
		commande.nObjetsB = ((c1) < 0) ? 0 : (c1);
		tmp = ((-c1) < 0) ? 0 : (-c1);
		objetsPreleves = node.objects_[1] - tmp;
		if (objetsPreleves != 0) { // un prelevement de poids a été effectué
			Time += objetsPreleves * 10; // temps de prelevement
			Masse += objetsPreleves * POIDS_B;
			graph_.graph_[path[i]].objects_[1] = tmp;
		}
		commande.nObjetsC = ((c2) < 0) ? 0 : (c2);
		tmp = ((-c2) < 0) ? 0 : (-c2);
		objetsPreleves = node.objects_[2] - tmp;
		if (objetsPreleves != 0) { // un prelevement de poids a été effectué
			Time += objetsPreleves * 10; // temps de prelevement
			Masse += objetsPreleves * POIDS_C;
			graph_.graph_[path[i]].objects_[2] = tmp;
		}
	}
}

void Chemin::calculateTime(int D)
{
	int k;
	if (RobotPlusRapide == "X")
		k = 1 + Masse;
	else if (RobotPlusRapide == "Y")
		k= 1.5 +0.6*Masse;
	else if (RobotPlusRapide == "Z")
		k = 2.5+0.2*Masse;
	Time += D * k;
}



// driver program to test above function 
void Chemin::plusCourtChemin(int departurePoint)
{
	calculRobotRapide();
	if (graphSize == 0)
		cout << "Graphe vide !!" << endl;
	else if (RobotPlusRapide != "N" || graphSize > 0) {
		//Time += (commande[0] + commande[1] + commande[2]) * 10;
		int startPoint = departurePoint;
		int nPaths = 0;
		vector<int> Paths;
		while ((commande.nObjetsA + commande.nObjetsB + commande.nObjetsC) != 0)
		{
			vector<int> tab = dijkstra(startPoint);
			vector<int> Restant;
			for (int v = 0; v < graphSize; v++) {
				objetsRecolt[v][0] = ((commande.nObjetsA - objetsRecolt[v][0]) < 0) ? 0 : (commande.nObjetsA - objetsRecolt[v][0]);
				objetsRecolt[v][1] = ((commande.nObjetsB - objetsRecolt[v][1]) < 0) ? 0 : (commande.nObjetsB - objetsRecolt[v][1]);
				objetsRecolt[v][2] = ((commande.nObjetsC - objetsRecolt[v][2]) < 0) ? 0 : (commande.nObjetsC - objetsRecolt[v][2]);
				Restant.push_back(objetsRecolt[v][0] + objetsRecolt[v][1] + objetsRecolt[v][2]);
			}
			//printSolution(tab);
			int idChanged;
			if (Emergency == -1) {
				idChanged = minRestObjectsAndDistance(Restant, tab);
			}
			else
			{
				idChanged = Emergency;
				Emergency = -1;
			}
			vector<int> currentPath; // path taken to get to idChanged Node
			currentPath.push_back(idChanged);
			int back = pathBoolean[idChanged];
			while (back != startPoint) {
				currentPath.push_back(back);
				back = pathBoolean[back];
			}
			currentPath.push_back(startPoint);
			//cout << "\n";
			//Sommet* updatedGraph = 
			updateGraph(currentPath);
			/*for (int i = 0; i < graphSize; i++)
				Graph[i] = updatedGraph[i];*/
			nPaths++;
		/*	cout << "Path:: ";*/
			for (int i = 0; i < currentPath.size(); i++) {
				//cout << currentPath[i];
				Paths.push_back(currentPath[currentPath.size() - i - 1]);
			}
			//cout << "\n";
			currentPath.clear();
			for(int i=0; i<graphSize; i++)
				fill(objetsRecolt[i].begin(), objetsRecolt[i].end(), 0);
			fill(pathBoolean.begin(), pathBoolean.end(),0);
			startPoint = idChanged;
			//cout << "NEXT START POINT " << startPoint << "\n";
		}

		vector<int> tab = dijkstra(0);
		calculateTime(tab[startPoint]);
		Paths.push_back(startPoint);
		int back = pathBoolean[startPoint];
		int Dist = 0;
		while (back != 0) {
			Paths.push_back(back);
			back = pathBoolean[back];
		}
		Paths.push_back(0);
		
		cout << "Result: number of traject( " << nPaths << ") : \n";
		for (int i = 0; i < Paths.size(); i++) {
			cout << "=>" << Paths[i] ;
		}
		cout << "\n Robot Choisi est le robot " << RobotPlusRapide << " : \n";
		cout << "temps pris: " << Time << " secondes \n";


	}
	else
		cout << "Chemin Impossible";
}

void Chemin::calculRobotRapide(){
	int masseTotale = commande.nObjetsA * POIDS_A + commande.nObjetsB * POIDS_B + commande.nObjetsC * POIDS_C;
	if (masseTotale = 0) {
		cout << "commande vide !!";
		RobotPlusRapide = "N";
	}
	if (masseTotale <= 5)
		RobotPlusRapide = "X";
	else if (masseTotale <= 10)
		RobotPlusRapide = "Y";
	else if (masseTotale <= 25)
		RobotPlusRapide = "Z";
	else 
		RobotPlusRapide = "N";

}
