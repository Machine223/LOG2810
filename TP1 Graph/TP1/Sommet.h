
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Sommet
{
	public:
		int id;
		vector<int> arcs_;
		vector<int> objects_;
		Sommet();
		Sommet(int i, vector<int> arcList, vector<int> o);
		void printMe();
};

