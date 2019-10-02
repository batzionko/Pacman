#include "Controller.h"

Controller::Controller()
{
	sf::RenderWindow Window;//the window
	m_board.get_toolbar().drawToolBar(Window);//get the tool bar
	setM_size(m_board.userInput());//set the board and size
	setVector(m_size);//set the vector
	Window.create(sf::VideoMode(800, 600), "pacman window", sf::Style::Titlebar | sf::Style::Close);//creat our window
	setRecSize(m_size);//set the size we got from the user
	sf::RectangleShape r;
	sf::RectangleShape t;
	if (m_board.get_isLevel())//if we opened used file
	{
		set_Players(m_board.getPlayers());//copy to the vector
		m_pac = m_board.isPac();//dont put twise the pacman
	}
	while (Window.isOpen())//go in the while till the window closes
	{
		Window.clear();//clear the window
		m_board.drawMatrix(Window, m_size);//draw our matrix
		m_board.get_toolbar().printToolBar(Window);//draw the toolbar
		for (int i = 0; i < m_size.x; i++)
			for (int j = 0; j < m_size.y; j++)
				if (m_players[i][j] != NULL)//draw if thier is an icon
					Window.draw(m_players[i][j]->getImage());
		sf::Event Event;
		while (Window.pollEvent(Event))//every event do somthing
		{
			switch (Event.type)//types of events
			{
			case sf::Event::Closed://if close the window
				Window.close();//close
				break;
			case sf::Event::KeyPressed://if press escape
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();//close
				break;
			case sf::Event::MouseButtonReleased://if the mouse butten released

				if (Event.mouseButton.button == sf::Mouse::Left)//if the left button
				{
					move(Event, Window, r);//move the icon
				}
				break;
			case sf::Event::MouseMoved://if the mouse moves
				isUsed(Event, Window, t);//check if the place is used or not

				break;
			}

		}

		Window.draw(t);//draw
		Window.display();//display to the window
	}
}
//--------------
//this function moves and put a icon where the user tills it to go or can also delet clear and save it and choose the color
void Controller::move(sf::Event mouse, sf::RenderWindow &Window, sf::RectangleShape& r)
{
	int x = mouse.mouseButton.x;//the location of x
	int y = mouse.mouseButton.y;//the location of y
	if (x < IMAGE_SIZE)//from toolbar
	{
		switch (y / IMAGE_SIZE)//swich to see what the user chose
		{
		case BLUE:
			on_c(BLUE);//outline
			setColor(BLUE);
			break;
		case GREEN:
			on_c(GREEN);//outline
			setColor(GREEN);
			break;
		case RED:
			on_c(RED);//outline
			setColor(RED);
			break;
		case PACMAN:
			on_i(PACMAN);//outline
			setIcon(PACMAN);
			break;
		case WALL:
			on_i(WALL);//outline
			setIcon(WALL);
			break;
		case DEAMON:
			on_i(DEAMON);//outline
			setIcon(DEAMON);
			break;
		case COOKIE:
			on_i(COOKIE);//outline
			setIcon(COOKIE);
			break;
		case SAVE:
			saveGame();
			break;
		case ERASER:
			on_i(ERASER);//outline
			setIcon(ERASER);
			break;
		case CLEAR:
			deleteBoard();//delete the board
			m_board.hasCle();//change the boll to cleared
			setM_size(m_board.userInput());//set the size of new matrix
			setVector(m_size);//set the vector
			setRecSize(m_size);//set the new size
			break;

		}

	}
	else
	{
		setIndex(x, y);//set the index to left top point
		if (find_if_exist(((x - 70)) / (int)m_recNewSize.x, y / (int)m_recNewSize.y) && m_icon != SAVE && m_icon != ERASER)//if somthing is in the spot and we are not using eraser or save or cleare
		{
			return;//go back
		}
		switch (m_icon)//if we are puting in an icon
		{
		case PACMAN://if pacman
		{
			if (!m_pac)//put only one time
			{
				theClickedIcone(PACMAN, r, x, y);//resize and fix the icon
				new_pac(sf::Vector2f(x, y), r);//put the new icon in to the vector
				m_pac = true;
			}
		}
		break;
		case WALL://if wall
		{


			theClickedIcone(WALL, r, x, y);//resize and fix the icon
			new_wall(sf::Vector2f(x, y), r);//put the new icon in to the vector

		}
		break;
		case DEAMON://if deamon
		{

			theClickedIcone(DEAMON, r, x, y);//resize and fix the icon
			new_deamon(sf::Vector2f(x, y), r);//put the new icon in to the vector
		}
		break;
		case COOKIE://if coockie
		{
			theClickedIcone(COOKIE, r, x, y);//resize and fix the icon
			new_cookie(sf::Vector2f(x, y), r);//put the new icon in to the vector
		}
		break;
		case ERASER://if eraser
		{
			if (find_if_exist((x - 70) / (int)m_recNewSize.x, y / (int)m_recNewSize.y))//find if thier is what to erase
			{
				delete_icon((x - 70) / (int)m_recNewSize.x, y / (int)m_recNewSize.y);//delete the icon from window and vector
			}
			break;
		}

		}
	}


}
//-----------------------------------------------
//this function marks in red if a spot is used and in green if it is not used,but if we use the eraser it is th opiset
void Controller::isUsed(sf::Event mouse, sf::RenderWindow &Window, sf::RectangleShape &r)
{
	int x = mouse.mouseMove.x;//catch the place we moov
	int y = mouse.mouseMove.y;//catch the place we moov
	if (x > 70 && x < 800 && y>0 && y < 600)//if in the window
	{
		int i = (x - 70) / m_recNewSize.x;//the x left top point
		int j = y / m_recNewSize.y;//the y left top point
		setIndex(x, y);//sets the indexes
		r.setSize(sf::Vector2f(m_recNewSize.x, m_recNewSize.y));//resize
		r.setPosition(x, y);//sets the position
		r.setOutlineThickness(3);//sets the outline
		r.setFillColor(sf::Color::Transparent);//sets the color to Transparent
		if (m_players[i][j] == NULL && m_icon == 7)//if nothing is thier and we are using the eraser
			r.setOutlineColor(sf::Color::Red);//draw the outline in red
		else if (m_players[i][j] != NULL && m_icon == 7)//if somthing is in that spot and we are using the eraser
			r.setOutlineColor(sf::Color::Green);//draw the outline in green

		else if (m_players[i][j] != NULL && m_icon >= 3 && m_icon <= 6)//if somthing is in that spot and we are not using the eraser
			r.setOutlineColor(sf::Color::Red);//draw the outline in red
		else if (m_players[i][j] == NULL && m_icon >= 3 && m_icon <= 6)//if nothing is thier and we are not using the eraser
			r.setOutlineColor(sf::Color::Green);//draw the outline in green

	}
}
//----------------------------------------------------------
//this function outlines what color we are using
void Controller::on_c(int type)
{
	for (int i = 0; i < 3; i++)
	{
		if (i == type)
		{
			m_board.get_toolbar().getIconImage(type).setOutlineColor(sf::Color::Green);
			m_board.get_toolbar().getIconImage(type).setOutlineThickness(3);

		}
		else
		{
			m_board.get_toolbar().getIconImage(i).setOutlineThickness(1);
			m_board.get_toolbar().getIconImage(i).setOutlineColor(sf::Color::White);
		}
	}
}
//-----------------------------------------------------
//this function outlines what icon we are using
void Controller::on_i(int type)
{
	for (int i = 3; i < 8; i++)
	{
		if (i == type)
		{
			m_board.get_toolbar().getIconImage(type).setOutlineColor(sf::Color::Green);
			m_board.get_toolbar().getIconImage(type).setOutlineThickness(3);

		}
		else
		{
			m_board.get_toolbar().getIconImage(i).setOutlineThickness(1);
			m_board.get_toolbar().getIconImage(i).setOutlineColor(sf::Color::White);
		}
	}
}

//--------------------------------------------------------
//this function sets the size of squires
void Controller::setRecSize(sf::Vector2i size)
{
	m_recNewSize.x = 730.0 / size.x;
	m_recNewSize.y = 600.0 / size.y;
}
//-----------------------------------
//thise function tills us the color we are using
void Controller::setColor(int i)
{
	m_color = i;
}
//------------------------------
//thise function tills us the icon we are using
void Controller::setIcon(int i)
{
	m_icon = i;
}
//------------------------------------------------------------------------------
//this function resize and fix the icon
void Controller::theClickedIcone(int type, sf::RectangleShape &r, int  x, int y)
{
	r = (m_board.get_toolbar().getIconImage(type));
	r.setSize(sf::Vector2f(m_recNewSize.x - 1, m_recNewSize.y - 1));
	r.setPosition(x, y);
	setColor(r);
}
//-----------------------------------------------
//this function colors the icon as the user wants
void Controller::setColor(sf::RectangleShape &r)
{
	if (m_color == 0)
		r.setFillColor(sf::Color::Blue);
	else if (m_color == 1)
		r.setFillColor(sf::Color::Green);
	else
		r.setFillColor(sf::Color::Red);

}
//-----------------------------------------
//this function sets the index as the size that the user input and puts it in the top left point
void Controller::setIndex(int &x, int &y)
{
	int i = ((x - (70)) / m_recNewSize.x);
	int j = (y / m_recNewSize.y);
	i *= m_recNewSize.x;
	i += 70;
	j *= m_recNewSize.y;
	x = i;
	y = j;
}
//---------------------------------------------
//this function checks if thier is a diffrent icon in this spot
bool Controller::find_if_exist(int i, int j)
{
	if (m_players[i][j] != NULL)
		return true;

	return false;
}
//---------------------------------------------
//this function deletes the icon
void Controller::delete_icon(int i, int j)
{
	if (m_players[i][j]->getType() == '@' || m_players[i][j]->getType() == 'W' || m_players[i][j]->getType() == 'S')
		m_pac = false;
	m_players[i][j] = NULL;
}
//-------------------------------------------
//this function updates the vector with a new pacman
void Controller::new_pac(sf::Vector2f location, sf::RectangleShape r)
{
	int i = m_recNewSize.x;
	int j = m_recNewSize.y;
	int t = ((int)location.x - 70) / i;
	int w = ((int)location.y) / j;
	outLine(r);
	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
		{
			if (t == i && w == j)
			{
				m_players[i][j] = new Pacman(sf::Vector2f(location.x, location.y), '@', r, m_color);
			}

		}

}
//------------------------------------------------------------------
//this function updates the vector with a new deamon
void Controller::new_deamon(sf::Vector2f location, sf::RectangleShape r)
{
	int i = m_recNewSize.x;
	int j = m_recNewSize.y;
	int t = ((int)location.x - 70) / i;
	int w = ((int)location.y) / j;
	outLine(r);

	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
		{
			if (t == i && w == j)
			{
				m_players[i][j] = new Deamon(sf::Vector2f(location.x, location.y), '%', r, m_color);
			}

		}
}
//------------------------------------------------------------------
//this function updates the vector with a new coockie
void Controller::new_cookie(sf::Vector2f location, sf::RectangleShape r)
{
	int i = m_recNewSize.x;
	int j = m_recNewSize.y;
	int t = ((int)location.x - 70) / i;
	int w = ((int)location.y) / j;
	outLine(r);

	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
		{
			if (t == i && w == j)
			{
				m_players[i][j] = new Cookie(sf::Vector2f(location.x, location.y), '*', r, m_color);
			}

		}
}
//------------------------------------------------------------------
//this function updates the vector with a new wall
void Controller::new_wall(sf::Vector2f location, sf::RectangleShape r)
{
	int i = m_recNewSize.x;
	int j = m_recNewSize.y;
	int t = ((int)location.x - 70) / i;
	int w = ((int)location.y) / j;
	outLine(r);

	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
		{
			if (t == i && w == j)
			{
				m_players[i][j] = new Wall(sf::Vector2f(location.x, location.y), '#', r, m_color);
			}

		}
}
//------------------------------------------------------------------
//this function draws an outline
void Controller::outLine(sf::RectangleShape &r)
{
	r.setOutlineThickness(1);
	r.setOutlineColor(sf::Color::White);
}
//-------------------------------------------------------
//this function deletes the boared
void Controller::deleteBoard()
{
	for (int i = 0; i < m_size.x; i++)
	{

		for (int j = 0; j < m_size.y; j++)
		{
			m_players[i][j] = NULL;
		}
		std::cout << "\n";
	}
	m_pac = false;
}
//------------------------------------------------------
//this function saves the game
void Controller::saveGame()
{
	std::ofstream out;
	out.open("game.txt");
	if (!out.is_open())
	{
		std::cerr << "file not open\n";
		exit(EXIT_FAILURE);
	}
	out << m_size.x << "\n";
	out << m_size.y << "\n";
	for (int j = 0; j < m_size.x; j++)
	{
		for (int i = 0; i < m_size.y; i++)

		{
			if (m_players[i][j] == NULL)
				out << " ";
			else
				out << m_players[i][j]->getType();
		}
		out << "\n";
	}
}
//-------------------------------------------------------
//this function sets the vector
void Controller::setVector(sf::Vector2i size)
{
	m_players.assign(size.x, std::vector <Icons *>(size.y));
}
//------------------------------------------------------
//this function sets the size
void Controller::setM_size(sf::Vector2i size)
{
	m_size = size;
}
//-------------------------------------------------------
//this function sets the vector of players
void Controller::set_Players(std::vector <std::vector<Icons*>>& boardPlayrs)
{
	for (int i = 0; i < m_size.x; i++)
		for (int j = 0; j < m_size.y; j++)
			m_players[i][j] = boardPlayrs[i][j];
}
//------------------------------------------------------
Controller::~Controller()
{
}