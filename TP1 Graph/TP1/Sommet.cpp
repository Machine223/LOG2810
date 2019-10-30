#include "Sommet.h"




Sommet::Sommet(int numero, int nbObjetA, int nbObjetB, int nbObjetC)
{
	this->numero_ = numero;
	this->nbObjetA_ = nbObjetA;
	this->nbObjetB_ = nbObjetB;
	this->nbObjetC_ = nbObjetC;

}

int Sommet::getNumero()
{
	return numero_;
}

int Sommet::getNbObjetA()
{
	return nbObjetA_;
}

int Sommet::getNbObjetB()
{
	return nbObjetB_;
}

int Sommet::getNbObjetC()
{
	return nbObjetC_;
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
