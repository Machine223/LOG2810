//********************************************************************************
// Nom         : Sommet.h
// Auteurs     : Abderrahim Ammour, Abdelkader Zobiri, Hanane Ikhelef
// Date        : 27 octobre 2018
// Description : implémentation de Sommet.h
//********************************************************************************

#include "Sommet.h"
Sommet::Sommet()
{
	id = 0;
}
Sommet::Sommet(int i, vector<int> arcList, vector<int> o) {
	id = i;
	arcs_ = arcList;
	objects_ = o;
};
