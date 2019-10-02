#include "board.h"




board::board()//the bords size
{
	
	
}

//--------------------------------
void board ::read_the_board()
{
	
	ifstream inp;
	 
	inp.open("pacman.txt");
	if (!inp.is_open())
	{
		cerr << "can't open file" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(inp, line))
	{
		_m_matrix.push_back(line);
		
	}
	getchar();
}
//------------------------------------
void board::add_line(string line) {
	_m_matrix.push_back(line);
}

//------------------------------
void board::print_the_board()
{
	for (int i = 0; i < _m_matrix.size(); i++)
		cout << _m_matrix[i]<<endl;

}
//--------------------------------------------
vertex board:: find_the_empty(vertex diff_p, vertex dis_p )
{
	
	
	vertex savePlace= diff_p;
	int min_dis = distance(dis_p, diff_p);
		//cout << min_dis<< endl;
	
	for (int i=0 ; i<_m_matrix.size(); i++)
		for (int j = 0; j < _m_matrix.size(); j++)
		{
			if (_m_matrix[i][j] == '*')
			{
				vertex new_place;
				new_place._m_x = i;
				new_place._m_y = j;
				int new_dis = distance(dis_p, new_place);
				if (new_dis < min_dis)
				{
					min_dis = new_dis;
					savePlace = new_place;
				}
			}
		}
		return savePlace;

}
//----------------------------------
double board::distance(const vertex& v1, const vertex& v2)
{
	return std::sqrt(std::pow((v1._m_x - v2._m_x), 2)
		+ std::pow((v1._m_y - v2._m_y), 2));
}
//-------------------------------------------
void board::set_vertex(char new_c, int i, int j)
{
	_m_matrix[i][j] = new_c;

}
//----------------------------------
int board::get_size()
{
	return _m_matrix.size();
}