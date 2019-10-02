#include "Board.h"

Board::Board()
{

}


Board::~Board()
{

}
//----------------------------------------------------
void Board::setSizeBoard(const sf::Vector2i& boardSize)
{
//setting the size of the board
	m_sizeb.x = boardSize.x;
	m_sizeb.y = boardSize.y;

}
//--------------------------------------------------------------------
void Board::drawMatrix(sf::RenderWindow &window, sf::Vector2i size)
{
	//drowing the colums as the size it get
	sf::RectangleShape cols(sf::Vector2f(1, 600));
	cols.setFillColor(sf::Color::White);
	double x = 70;
	double y = 0;
	for (int i = 0; i < size.x; i++)
	{
		cols.setPosition(x, y);
		x += 730.0 / size.x;
		window.draw(cols);

	}
	//drowing the rows as the size it get
	sf::RectangleShape rows(sf::Vector2f(x - (730.0 / size.x), 1));
	x -= (730.0 / size.x);
	rows.setFillColor(sf::Color::White);
	x = 70;
	for (int i = 0; i < size.y; i++)
	{
		rows.setPosition(x, y);
		y += 600.0 / size.y;
		window.draw(rows);
	}

}
//----------------------------------
const sf::Vector2i & Board::userInput()
{

	sf::Vector2f size;
	std::ifstream level("game.txt");
	std::string line;
	char c;
	//check if there is file to read from
	if (level.is_open() && m_firstTime)
		
	{
		m_firstTime = false;
		m_isLevel = true;
		level >> size.x;
		level >> size.y;
		setVector((sf::Vector2i)size);
		//loading  details from the file to the icons vector
		for (int i = 0; i < size.x; i++)
		{
			level.get();
			for (int j = 0; j < size.y; j++)
			{
				c = level.get();
				build_matrix(c, i, j, size);
			}

		}

	}
//there is no file so the program reads from the user.
	while (!m_isLevel||cleared)
	{
		std::cout << "Hi!!\n\nPlease input number of row's and number of column's\nNumber of row's: ";
		std::cin >> size.x;  
		if (size.x > 21 || size.x < 10) {
			std::cout << "\nplease enter number betwean 10 to 20!!!! \n\n";
			continue;
		}
		std::cout << "Number of column's: ";
		std::cin >> size.y;
		if (size.y > 21 || size.y < 10) {
			std::cout << "\nplease enter number betwean 10 to 20:!!!! \n\n";
			continue;
		}
		else
			break;
	}
	return (sf::Vector2i)size;
}
//-----------------------------
void Board::build_matrix(const char c, int i, int j, sf::Vector2f size)
{
	//Updating the vector where each icon called from the file is there
	sf::RectangleShape r;

	switch (c)
	{
	case '#': //red wall
		reset_r(4, r, size,2);
		setRecSize(size);
		m_players[j][i] = new Wall(sf::Vector2f(70 + j * size.x, i * size.y), '#', r, RED);
		break;
	case 'E': //green wall
		reset_r(4, r, size,1);
		setRecSize(size);
		m_players[j][i] = new Wall(sf::Vector2f(70 + j * size.x, i * size.y), 'E', r, GREEN);
		break;
	case 'D': //blue wall
		reset_r(4, r, size,0);
		setRecSize(size);
		m_players[j][i] = new Wall(sf::Vector2f(70 + j * size.x, i * size.y), 'D', r, BLUE);
		break;
	case '*': //red cookie
		reset_r(6, r, size, 2);
		setRecSize(size);
		m_players[j][i] = new Cookie(sf::Vector2f(70 + j * size.x, i * size.y), '*', r, RED);
		break;
	case 'I'://green cookie
		reset_r(6, r, size, 1);
		setRecSize(size);
		m_players[j][i] = new Cookie(sf::Vector2f(70 + j * size.x, i * size.y), 'I', r, GREEN);
		break;
	case 'K'://blue cookie
		reset_r(6, r, size, 0);
		setRecSize(size);
		m_players[j][i] = new Cookie(sf::Vector2f(70 + j * size.x, i * size.y), 'K',r, BLUE);
		break;
	case '%': //red deamon
		reset_r(5, r, size, 2);
		setRecSize(size);
		m_players[j][i] = new Deamon(sf::Vector2f(70 + j * size.x, i * size.y), '%',r, RED);
		break;
	case 'T': //green deamon
		reset_r(5, r, size, 1);
		setRecSize(size);
		m_players[j][i] = new Deamon(sf::Vector2f(70 + j * size.x, i * size.y), 'T', r, GREEN);
		break;
	case 'G': //blue deamon
		reset_r(5, r, size, 0);
		setRecSize(size);
		m_players[j][i] = new Deamon(sf::Vector2f(70 + j * size.x, i * size.y), 'G', r, BLUE);
		break;
	case '@': //red pacman
		m_ispac = true;
		reset_r(3, r, size, 2);
		setRecSize(size);
		m_players[j][i] = new Pacman(sf::Vector2f(70 + j * size.x, i * size.y), '@',r, RED);
		break;
	case 'W': //green pacman
		m_ispac = true;
		reset_r(3, r, size, 1);
		setRecSize(size);
		m_players[j][i] = new Pacman(sf::Vector2f(70 + j * size.x, i * size.y), 'W', r, GREEN);
		break;
	case 'S': //blue pacman
		m_ispac = true;
		reset_r(3, r, size, 0);
		setRecSize(size);
		m_players[j][i] = new Pacman(sf::Vector2f(70 + j * size.x, i * size.y), 'S', r, BLUE);
		break;
	case ' ':
		m_players[j][i] = NULL;
		break;
	}

}
//=----------------------------------------------
void Board::setRecSize(sf::Vector2f & size)
{
	//update the size of the rectangle
	size.x = 730.0 / size.x;
	size.y = 600.0 / size.y;
}
//------------------------------------------------
void Board::setVector(sf::Vector2i size)
{
	//update the size of the vector
	m_players.assign(size.x, std::vector <Icons *>(size.y));

}
//--------------------------------------------------------
void  Board::reset_r(int type, sf::RectangleShape &r, sf::Vector2f size,int color)
{
	//resetting the rectagle accordig to the icon , size and the color it get
	r = (m_toolbar.getIconImage(type));
	setRecSize(size);
	r.setSize(sf::Vector2f(size));
	if (color == 0)
		r.setFillColor(sf::Color::Blue);
	else if (color == 1)
		r.setFillColor(sf::Color::Green);
	else
		r.setFillColor(sf::Color::Red);


}
