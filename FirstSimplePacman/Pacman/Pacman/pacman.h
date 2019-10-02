#pragma once
#include "vertex.h"
#include "board.h"

class pacman
{

public:
	pacman();
	void set_vertex(vertex);
	vertex get_vertex();
	char getChar();

private:
		
		vertex _m_p;
		char _m_pac='@' ;

};

