#include "Sommet.h"



//Sommet::Sommet()
//{
//}
//
//
//Sommet::~Sommet()
//{
//}

Sommet::Sommet(int numero, int nbObjetA, int nbObjetB, int nbObjetC)
{
	numero_= numero;
	nbObjetA_ = nbObjetA;
	nbObjetB_ = nbObjetB;
	nbObjetC_ = nbObjetC;
}

int Sommet::getNumero()
{
	return numero_;
}
