//********************************************************************************
// Nom         : Graph.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : implémentation de Graph.h
//********************************************************************************

#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <utility>

Graph::Graph()
{
	graphSize_ = 0;
}

Graph::~Graph()
{
	
}

void Graph::creerGraphe(const string & nomFichier)
{

	ifstream fichier(nomFichier, ios::in); //declaration du fichier en mode lecture et ouverture du fichier 
	if (fichier.is_open())
	{
		string temp, temp1, temp2, temp3;
		while (fichier.peek() != '\n')
		{
			getline(fichier, temp, ',');
			getline(fichier, temp1, ',');
			getline(fichier, temp2, ',');
			getline(fichier, temp3, '\n');
			objets_.push_back({ stoi(temp1), stoi(temp2), stoi(temp3) });
			graphSize_++;
		}

		getline(fichier, temp);

		// initialise un tableau temporaire avec des zero
		for (int i = 0; i < graphSize_; i++) {
			vector<int> tmp;
			for (int j = 0; j < graphSize_; j++) {
				tmp.push_back(0);
			}
			arcs_.push_back(move(tmp));
		}

		while (fichier.peek() != '\n' && !fichier.eof())
		{
			getline(fichier, temp1, ','); // Noeud1
			getline(fichier, temp2, ','); // Noeud2
			getline(fichier, temp3, '\n'); // la distance
			arcs_[stoi(temp1)][stoi(temp2)] = stoi(temp3);
			arcs_[stoi(temp2)][stoi(temp1)] = stoi(temp3);
		}

		for (int i = 0; i < graphSize_; i++) {
			Sommet sommet(i, arcs_[i], objets_[i]);
			graph_.push_back(sommet);
		}
		graphSize_ = graph_.size();
		fichier.close();
	}
	else
		cout << "******** Le fichier est introuvable ! **********"<< endl<<endl;

}

void Graph::afficherGraphe()
{
	//(Noeud0, NbObjetA, nbObjetB, nbObjetC, ((noeud voisin1 0, distance1 0), (noeud voisin2 0, distance2 0),
		//..., (noeud voisinn 0, distancen 0)))
	// affichage des numero de noeuds


	// affichage des objets de chaque noeuds
	cout << "Votre graphe est " <<  endl;

	for (int i = 0; i < graphSize_; i++) {
		int counter = 0;
		cout << "(Noeud " << i << ", ";
		for (int j = 0; j < 3; j++) {
			cout << graph_[i].getObjects_()[j] << " ,";
		}
		// affichage des arcs 
		cout << "(";
		for (int j = 0; j < graphSize_; j++) {
			if (graph_[i].getArcs_()[j] != 0) {
				counter++;
				cout << "( noeud voisin" << counter << " " << j << ", distance" << counter << " " << graph_[i].getArcs_()[j] << "),";
			}
		}
		cout << ")" << endl;
	}
}

int Graph::getNbMaxObjet(char objet)
{
	int counterA = 0;
	int counterB = 0;
	int counterC = 0;
	for (int i = 0; i < graphSize_; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)counterA += graph_[i].objects_[j];
			if (j == 1)counterB += graph_[i].objects_[j];
			if (j == 2)counterC += graph_[i].objects_[j];
		}
	}

	switch (objet) {
		case 'A': {
			return counterA;
			break;
		}
		case 'B': {
			return counterB;
			break;
		}
		case 'C': {
			return counterC;
			break;
		}
		default : {
			return 0;
			break;
		}
	}
}

int Graph::getGraphSize_()
{
	return graphSize_;
}

vector<Sommet> Graph::getGraph_()
{
	return graph_;
}
