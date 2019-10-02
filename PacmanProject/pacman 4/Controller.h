#pragma once
#include "Board.h"
#include "Icons.h"
#include "pacman.h"
#include "Deamon.h"
#include "Wall.h"
#include "Cookie.h"
#include "MouseControll.h"
#include <iostream>




//#include "ToolBar.h"\

const int IMAGE_SIZE = 60;
class Controller
{
public:
	Controller();
	~Controller();
	void setRecSize(sf::Vector2i);
	void setColor(int);
	void setIcon(int);
	void theClickedIcone(int type, sf::RectangleShape &r, int x, int y);
	void setColor(sf::RectangleShape &r);
	void move(sf::Event mouse, sf::RenderWindow &Window, sf::RectangleShape& r);
	void Controller::set_Players(std::vector <std::vector<Icons*>>& boardPlayrs);
	
	void setIndex(int &x, int &y);
	bool find_if_exist(int x, int y);
	void Controller::deleteBoard();
	void Controller::delete_icon(int x, int y);
	void saveGame();
	void setVector(sf::Vector2i size);
	void new_pac(sf::Vector2f location,sf::RectangleShape r);
	void new_deamon(sf::Vector2f location, sf::RectangleShape r);
	void new_cookie(sf::Vector2f location, sf::RectangleShape r);
	void new_wall(sf::Vector2f location, sf::RectangleShape r);
	void setM_size(sf::Vector2i size);
	void on_c(int type);
	void on_i(int type);
	void outLine(sf::RectangleShape &r);
	void isUsed(sf::Event mouse, sf::RenderWindow &Window, sf::RectangleShape &r);

private:
	Board m_board;
	bool m_pac = false;
	sf::Vector2f m_recNewSize;
	sf::Vector2i m_size;
	int m_color=2;
	int m_icon;
	bool m_isFile=false;
	std::vector <std::vector<Icons*>> m_players;
	
		
	


	
};

