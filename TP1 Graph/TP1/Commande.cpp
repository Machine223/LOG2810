//********************************************************************************
// Nom         : Commande.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : implémentation de Commande.h
//********************************************************************************

#include "Commande.h"

Commande::~Commande()
{
}

void Commande::reset()
{
	nObjetsA = 0;
	nObjetsB = 0;
	nObjetsC = 0;
}

void Commande::prendreCommande() {
	int A, B, C;
	cout << endl << "Veuillez entrer la commande :" << endl << " nombre d'0bjets de type A: ";
	cin >> A;
	cout << endl << " nombre d'0bjets de type B: ";
	cin >> B;
	cout << endl << " nombre d'0bjets de type C: ";
	cin >> C;
	cout << endl;
	nObjetsA = (A >= 0) ? A : 0;
	nObjetsB = (B >= 0) ? B : 0;
	nObjetsC = (C >= 0) ? C : 0;
}

void Commande::afficherCommande() {
	cout << endl << "la commande est :" << endl << nObjetsA << " 0bjets de type A" << endl << nObjetsB << " 0bjets de type B" << endl
		<< nObjetsC << " 0bjets de type C" << endl;
}
int Commande::getNObjetsA()
{
	return nObjetsA;
}
int Commande::getNObjetsB()
{
	return nObjetsB;
}
int Commande::getNObjetsC()
{
	return nObjetsC;
}
void Commande::setNObjetsA(int a)
{
	nObjetsA = a;
}
void Commande::setNObjetsB(int b)
{
	nObjetsB = b;
}
void Commande::setNObjetsC(int c)
{
	nObjetsC = c;
}
;