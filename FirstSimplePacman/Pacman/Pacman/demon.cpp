#include "demon.h"



	//לבנות לו קונסטרקורררר שמקבל את הערך הדיפןלטיבי ומחפש איפה למקם כמו הפקמן

demon::demon(vertex v) :
	m_demon{v}
{
	
}
//---------------------------------------
void demon::set_vertex(vertex new_v)
{
	m_demon = new_v;
}
//------------------------------
vertex demon::get_vertex()
{
	return m_demon;
}
//---------------------------
char  demon::getChar()
{
	return m_d;
}
//-----------------------------
void demon::set_defult_demons(int i)
{ 
	if (i == 1)
	{
		m_demon._m_x = 0;
		m_demon._m_y = 0;
	}
		

	/*else if (i == 2)
		m_demon = { 0, (8 - 1.0) };
	else if (i == 2)
		m_demon = { (8 - 1.0) , (8 - 1.0) };*/

}
//m_b.get_size()




