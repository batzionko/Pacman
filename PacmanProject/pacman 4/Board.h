#pragma once
#include "ToolBar.h"
#include "Icons.h"
#include "Wall.h"
#include "pacman.h"
#include "Deamon.h"
#include "Cookie.h"

class Board
{
public:
	Board();
	void setSizeBoard(const sf::Vector2i & boardSize); //setting the size of the board
	void drawMatrix(sf::RenderWindow &window, sf::Vector2i size); // drowing the matrix
	const sf::Vector2i& userInput(); //the userm inputs
	void Board::build_matrix(const char c,int i,int j, sf::Vector2f size); // building the matrix according to the size of the board
	ToolBar& get_toolbar()  { return m_toolbar; };
	void setRecSize(sf::Vector2f & size); // setting the rectangle size
	void setVector(sf::Vector2i size);// set vector size
	std::vector <std::vector<Icons*>>& getPlayers() { return m_players; }; 
	bool get_isLevel() { return m_isLevel; };
	void  Board::reset_r(int type, sf::RectangleShape &r, sf::Vector2f size,int); //resetting the rectangle it get
	bool isPac() { return m_ispac; };
		~Board();
		void hasCle() { cleared = true; };
	
private:
	ToolBar m_toolBar;
	sf::Vector2i m_sizeb;
	std::vector <std::vector<Icons*>> m_players;
	std::vector<std::string> m_matrix;
	bool m_isLevel = false;
	ToolBar m_toolbar;
	bool m_ispac = false;
	bool m_firstTime = true;
	bool cleared = false;
	sf::Vector2f m_recNewSize;
	
};

