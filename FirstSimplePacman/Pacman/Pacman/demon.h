#pragma once
#include "vertex.h"
class demon
{
public:
	demon(vertex);
	void set_vertex(vertex);
	vertex get_vertex();
	char getChar();
	void set_defult_demons(int i);
private:
	vertex m_demon;
	char m_d = '%';
};

