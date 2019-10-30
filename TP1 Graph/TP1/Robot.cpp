#include "Robot.h"


//
//Robot::Robot()
//{
//}
//
//
//Robot::~Robot()
//{
//}

Robot::Robot()
{
	massTotal_ = 0.0;
	masseMax_ = 25.0;
	constante_ = 2.5;
	force_ = 0.2;
	type_ = 'C';
}

Robot::Robot(string type)
{
	// Cas si lettre miniscule
	if (islower(type[0]))
	{
		type[0] = toupper(type[0]);
	}

	switch (type[0]) {
		case 'A': {
			massTotal_ = 0.0;
			masseMax_ = 5.0;
			constante_ = 1.0;
			force_ = 1.0;
			type_ = 'A';
			break;      // and exits the switch
		}
		case 'B': {
			massTotal_ = 0.0;
			masseMax_ = 10.0;
			constante_ = 1.5;
			force_ = 0.6;
			type_ = 'B';
			break;		// and exits the switch
		}
		case 'C': {
			massTotal_ = 0.0;
			masseMax_ = 25.0;
			constante_ = 2.5;
			force_ = 0.2;
			type_ = 'C';
			break;		// and exits the switch
		}
		default: {
			cout << "Entrée non valide veuillez réessayer !" << endl;
			break;
		}
	}
}

Robot::~Robot()
{
}

double Robot::getConstante() const
{
	return constante_;
}

double Robot::getMassTotal() const
{
	return massTotal_;
}

double Robot::getMassMax() const
{
	return masseMax_;
}
