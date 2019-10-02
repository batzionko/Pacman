#
#include "board.h"
#include "pacman.h"
#include "level.h"

vector<level> read_the_boards();

int main()
{

	vector<level> levels = read_the_boards();

	//cout << p.get_vertex()._m_x<<endl;
	//cout << p.get_vertex()._m_y<<endl;
	//find_the_empty(p)
	levels[0].get_board().print_the_board();
	getchar();

	return EXIT_SUCCESS;
}


vector<level> read_the_boards()
{
	vector<level> levels;
	ifstream inp;

	inp.open("pacman.txt");
	if (!inp.is_open())
	{
		cerr << "can't open file" << endl;
		exit(EXIT_FAILURE);
	}
	string line;
	int level_counter = 0;
	while (getline(inp, line))
	{
		level_counter++;
		board b;
		
		int size = atoi(line.c_str());//the size of matrix
			
		for (int i = 0; i < size; i++) {
			getline(inp, line);//get the line from text doc
			b.add_line(line);//put in all the lines to build the matrix
		}
		levels.push_back(level(b, level_counter));//put in our level the board that we built

	}

	return levels;//return the vector of levels
}
/*
#include "Utilities.h"
#include <cmath>

bool doubleEqual(double a, double b)
{
	return std::abs(a - b) <= 1;
}

// Some helper functions for addLine()
double distance(const Vertex& v1, const Vertex& v2)
{
	return std::sqrt(std::pow((v1.m_x - v2.m_x), 2)
		+ std::pow((v1.m_y - v2.m_y), 2));
}

bool sameX(const Vertex& v1, const Vertex& v2)
{
	return doubleEqual(v1.m_x, v2.m_x);
}

bool sameY(const Vertex& v1, const Vertex& v2)
{
	return doubleEqual(v1.m_y, v2.m_y);
}

bool operator<(const Vertex& lhs, const Vertex& rhs)
{
	Vertex origin = { 0, 0 };
	return distance(lhs, origin) < distance(rhs, origin);
}
*/