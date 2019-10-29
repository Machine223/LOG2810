#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>


Graph::Graph()
{
}

Graph::Graph(const Graph & graphe)
{
	for (int i = 0; i < graphe.tabSommets_.size(); i++)
		tabSommets_.push_back(new Sommet(*(graphe.tabSommets_[i])));

	for (int i = 0; i < graphe.tabArcs_.size(); i++)
		tabArcs_.push_back(new Arc(*(graphe.tabArcs_[i])));
}


Graph::~Graph()
{
}

void Graph::creerGraphe(const string & nomFichier)
{
	ifstream fichier(nomFichier);
	if (fichier.is_open())
	{
		string temp1, temp2, temp3, temp;
		while (fichier.peek() != '\n')
		{
			getline(fichier, temp, ',');
			getline(fichier, temp1, ',');
			getline(fichier, temp2, ',');
			getline(fichier, temp3, ',');
			tabSommets_.push_back(new Sommet(stoi(temp), stoi(temp1), stoi(temp2), stoi(temp3)));
		}

		getline(fichier, temp);

		while (fichier.peek() != '\n')
		{
			/*Sommet* sommets[2];
			getline(fichier, temp, ',');
			sommets[0] = findSommet(temp);
			getline(fichier, temp, ',');
			sommets[1] = findSommet(temp);
			getline(fichier, temp, ';');

			Arc* arc = new Arc(sommets, stoi(temp));
			arc->setIdentifiant(sommets[0]->getNumero() + "-" + sommets[1]->getNumero());
			sommets[0]->ajouterVoisin(arc);
			sommets[1]->ajouterVoisin(arc);

			tabArcs_.push_back(arc);*/
		}
	}
}
