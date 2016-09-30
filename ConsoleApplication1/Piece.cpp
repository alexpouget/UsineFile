#include "Piece.h"



Piece::Piece()
{
	id = 0;
}

Piece::Piece(int _id)
{
	id = _id;
}

Piece::~Piece()
{
}

int Piece::getId()
{
	return id;
}

void Piece::setId(const int _id)
{
	id = _id;
}

std::ostream & operator<<(std::ostream & f, const Piece & p)
{
	f << p.id << std::endl;
	return f;
}
