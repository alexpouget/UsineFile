#pragma once
#include <iostream>
class Piece
{
public:
	Piece();
	Piece(int);
	~Piece();
	int getId();
	void setId(const int);
	friend std::ostream& operator << (std::ostream& f, const Piece& p);

private:
	int id;

};

