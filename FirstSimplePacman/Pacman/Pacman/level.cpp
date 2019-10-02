#include "level.h"



level::level(board& b, int level_number) :
	m_b(b), m_level_number(level_number)
{
	vertex demons[4];
	//set_defult_demons(demons);
	//Set Demonds

	//Set Deamons and player position
	vertex center = { (m_b.get_size() - 1) / 2,(m_b.get_size() - 1) / 2 };
	vertex bottom_left = { 0,0 };

	m_pac.set_vertex(m_b.find_the_empty(bottom_left, center));
	m_b.set_vertex(m_pac.getChar(), m_pac.get_vertex()._m_x, m_pac.get_vertex()._m_y);//מכניס את הצורה		
		for (int i = 0; i < m_level_number - 1; i++)
	{
		m_demons[i].set_defult_demons(i);
		m_demons[i].set_vertex(m_b.find_the_empty(m_demons[i].get_vertex(), center));
		m_b.set_vertex(m_demons[i].getChar(), m_demons[i].get_vertex()._m_x, m_demons[i].get_vertex()._m_y);
		
		m_demons.push_back(demon(demons[i]));
	}
	
		
}
//----------------------------------
board level::get_board() {
	return m_b;
}
//-----------------------------




