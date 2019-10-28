#pragma once
class Objet
{
	public:
	// Constructeur par défaut
	Objet();
	// Constructeur par paramètres
	Objet(string type, int poids);
	Objet(Objet* objetCopie);

	// Destructeur
	~Objet();

	// Setters
	void setPoids(int poids);

	// Getters


	private:
	string type_; // si type A = 1 B = 3 C = 6
	int poids_; 

};

