#include "Sommet.h"




Sommet::Sommet(int numero, int nbObjetA, int nbObjetB, int nbObjetC)
{
	this->numero_ = numero;
	this->nbObjetA_ = nbObjetA;
	this->nbObjetB_ = nbObjetB;
	this->nbObjetC_ = nbObjetC;

}

Sommet::~Sommet()
{
	vectorArcVoisin_.erase(vectorArcVoisin_.begin(), vectorArcVoisin_.end());
}

// Ajoute un voisin
void Sommet::ajouterVoisin(Arc * voisin)
{
	vectorArcVoisin_.push_back(voisin);
	degre_++;
}

bool Sommet::isConnectedTo(Sommet * sommet)
{
	// Cherche selon le degre du noeud s'il a ce voisin dans ca liste d'arc
	for (int i = 0; i < degre_; i++)
		if (vectorArcVoisin_[i]->contains(sommet))
			return true;
	return false;
}

int Sommet::getDistanceTo(Sommet * sommet)
{
	// Vérifie s'il a le voisin
	if (this->isConnectedTo(sommet)) {
		return vectorArcVoisin_[0]->getDistance();
	}
	return 0;
}



int Sommet::getNumero()const
{
	return numero_;
}

int Sommet::getNbObjetA()const
{
	return nbObjetA_;
}

int Sommet::getNbObjetB()const
{
	return nbObjetB_;
}

int Sommet::getNbObjetC()const
{
	return nbObjetC_;
}

vector<Sommet*> Sommet::getVoisin() const
{
	vector<Sommet*> noeudsVoisins;
	// Recherche dans mon vectorArcVoisin_ pour identifier tout les voisins de ce sommet
	for (int i = 0; i < vectorArcVoisin_.size(); i++)
	{
		Sommet** iteratorSommetsArc = vectorArcVoisin_[i]->getSommets(); // retourn un Sommet**

		if (iteratorSommetsArc[0]->getNumero() != numero_)
			noeudsVoisins.push_back(iteratorSommetsArc[0]);
		else
			noeudsVoisins.push_back(iteratorSommetsArc[1]);
	}
	return noeudsVoisins;
}

void Sommet::setNbObjetA(int nb)
{
	nbObjetA_ = nb;
}

void Sommet::setNbObjetB(int nb)
{
	nbObjetB_ = nb;
}

void Sommet::setNbObjetC(int nb)
{
	nbObjetC_ = nb;
}
