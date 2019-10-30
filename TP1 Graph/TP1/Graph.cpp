#include "Graph.h"
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>


Graph::Graph()
{
}

//Graph::Graph(const Graph & graphe)
//{
//	for (int i = 0; i < graphe.tabSommets_.size(); i++)
//		tabSommets_.push_back(new Sommet(*(graphe.tabSommets_[i])));
//
//	for (int i = 0; i < graphe.tabArcs_.size(); i++)
//		tabArcs_.push_back(new Arc(*(graphe.tabArcs_[i])));
//}


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
			tabSommets_.push_back(new Sommet(stoi(temp), stoi(temp1), stoi(temp2), stoi(temp3)));
		}

		getline(fichier, temp);

		while (fichier.peek() != '\n')
		{
			Sommet* sommets[2];			// on creer l'attribut pour Arc pour recevoir les sommets adjacent et leur distance
			getline(fichier, temp1, ','); // Noeud1
			sommets[0] = trouverSommet(temp1);
			getline(fichier, temp2, ','); // Noeud2
			sommets[1] = trouverSommet(temp2);

			// Creation de l'arc et de la distance entre deux noeuds
			getline(fichier, temp3, '\n'); // la distance
			Arc* monArc = new Arc(sommets, stoi(temp3));
			monArc->setIdentifiant(to_string(sommets[0]->getNumero()) + "-" + to_string(sommets[1]->getNumero()));
			// ajouter les voisins a monArc  
			sommets[0]->ajouterVoisin(monArc);
			sommets[1]->ajouterVoisin(monArc);

			tabArcs_.push_back(monArc);
		}
	}
}

Sommet Graph::getSommet(int numero)
{
	for (int i = 0; i < tabSommets_.size(); i++)
		if (tabSommets_[i]->getNumero() == numero)
			return *(tabSommets_[i]);

}

Sommet * Graph::trouverSommet(const string & numero)
{
	for (int i = 0; i < tabSommets_.size(); i++)
		if (tabSommets_[i]->getNumero() == stoi(numero))
			return tabSommets_[i];
	return NULL;
}
