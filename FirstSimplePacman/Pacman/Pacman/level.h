#pragma once
#include "board.h"
#include "pacman.h"
#include "demon.h"
class level
{

public:
	void set_defult_demons(vertex demons[]);
	level(board& b, int level_number);
	board get_board();
	int get_matrix_size() const;

private:
	board m_b;
	int m_level_number;
	pacman m_pac;
	vector<demon> m_demons;


};

