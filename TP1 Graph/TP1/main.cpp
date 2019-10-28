//********************************************************************************
// Nom         : main.cpp
// Auteurs     : Abderrahim Ammour
// Date        : 27 octobre 2018
// Description : Main du programme
//********************************************************************************

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

#include "Arc.h"
#include "Graph.h"
#include "Sommet.h"
#include "Objet.h"
#include "Robot.h"

using namespace std;

void afficherMenu();

int main()
{
	// Permet l'affichage des accents
	setlocale(LC_ALL, "");

	// Initialisation des variables
	bool exit = false;
	bool option1 = false;

	// Initialisation des objets
	//Graphe graphe;
	//Robot* robot = new Robot();
	string nomFichier;
	ifstream fichier;
	

	/*int autonomieMax;
	int autonomieRestante;*/

	//TEST
	
	afficherMenu();
	//do
	//{
	//	// Affichage du menu
	//	afficherMenu();

	//	// Prise de la réponse
	//	string reponse = "";
	//	cout << "Saisissez une option : ";
	//	cin >> reponse;
	//	cout << endl;

	//	// Le case dépend de l'entrée de l'utilisateur
	//	switch (atoi(reponse.c_str()))
	//	{

	//	case 1:
	//		

	//	case 2:

	//		
	//		break;

	//	case 3:

	//		
	//		break;

	//	case 4:

	//		

	return 0;
}

// Menu principal
void afficherMenu()
{
	cout << "================================================" << endl << endl;
	cout << "1. Créer le graphe." << endl;
	cout << "2. Afficher le graphe." << endl;
	cout << "3. Prendre une commande." << endl;
	cout << "4. Afficher la commande." << endl;
	cout << "5. Trouver le plus court chemin." << endl;
	cout << "4. Quitter." << endl << endl;
}

