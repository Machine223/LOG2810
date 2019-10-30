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

Robot::Robot(string type)
{
	// Cas si lettre miniscule
	if (islower(type[0]))
	{
		type[0] = toupper(type[0]);
	}

	switch (type[0]) {
		case 'A': {
	
			break;      // and exits the switch
		}
		case 'B': {
					
			break;		// and exits the switch
		}
		case 'C': {
			
			break;		// and exits the switch
		}
		default: {
			
			break;
		}
	}
}
