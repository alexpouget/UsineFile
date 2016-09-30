#pragma once
#include "Piece.h"
#include "Axe.h"
#include "Jupe.h"
#include "Tete.h"

class Piston :
	public Piece
{
public:
	Piston();
	Piston(int _id, Axe _axe,Jupe _jupe,Tete _tete);
	~Piston();
private:
	Axe axe;
	Jupe jupe;
	Tete tete;
};

