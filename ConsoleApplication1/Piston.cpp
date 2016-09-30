#include "Piston.h"



Piston::Piston()
{
}

Piston::Piston(int _id, Axe _axe, Jupe _jupe, Tete _tete)
{
	setId(_id);
	axe = _axe;
	jupe = _jupe;
	tete = _tete;
}


Piston::~Piston()
{
}
