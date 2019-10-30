#include "Arc.h"


Arc::Arc()
{
}

Arc::Arc(Sommet * sommets[2], int distance)
{
	sommets_[0] = sommets[0];
	sommets_[1] = sommets[1];
	distance_ = distance;
}

// Destructeur
Arc::~Arc()
{
	if (sommets_[0] != nullptr)
		delete sommets_[0];
	if (sommets_[1] != nullptr)
		delete sommets_[1];
}

Arc::Arc()
{
	sommets_[0] = sommets_[1] = nullptr;
}

// Retourne l'identifiant
string Arc::getIdentifiant() const
{
	return identifiant_;
}

// Retourne la distance, soit la longueur d'arc
int Arc::getDistance() const
{
	return distance_;
}

// Établit l'identifiant
void Arc::setIdentifiant(string identifiant)
{
	identifiant_ = identifiant;
}

// Établit la distance
void Arc::setDistance(int distance)
{
	distance_ = distance;
}

// Dit si un des sommets liés à l'arc contient le bon identifiant
bool Arc::contains(Sommet* sommet)
{
	if ((sommets_[0]->getNumero() == sommet->getNumero()) || (sommets_[1]->getNumero() == sommet->getNumero()))
	{
		return true;
	}
	else
		return false;

}


Sommet ** Arc::getSommets() const
{
	return (Sommet**)sommets_;
}



// Constructeur par paramètres
Arc::Arc(Sommet * sommets[2], int distance)
{
	identifiant_ = "";
	distance_ = distance;
	sommets_[0] = sommets[0];
	sommets_[1] = sommets[1];
	
}

void Arc::setIdentifiant(string identifiant)
{
	identifiant_ = identifiant;
}
