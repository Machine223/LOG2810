#include "Sommet.h"
Sommet::Sommet(int i, vector<int> arcList, vector<int> o) {
	id = i;
	arcs_ = arcList;
	objects_ = o;
};
void Sommet::printMe() {
	cout << "\n *********************** myId = " << id << " \n";
	for (int i = 0; i < arcs_.size(); i++) {
		cout << "\n arcs[" << i << "]" << arcs_[i];
		if (i < 3) {
			cout << " \n object[" << i << "]" << objects_[i];
		}
	}
	cout << " \n";
}