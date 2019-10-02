#include "pacman.h"


pacman::pacman()
{
	//_m_p._m_x = 0;
	//_m_p._m_y = 0;
	//board.find_the_empty(p._m_p, size);

}
//---------------------------------------
void pacman::set_vertex( vertex new_v)
{
	_m_p=new_v;
}
//------------------------------
vertex pacman::get_vertex()
{
	return _m_p;
}
//---------------------------
char  pacman::getChar()
{
	return _m_pac;
}


