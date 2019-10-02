#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

const int  BLUE = 0;
const int  GREEN = 1;
const int  RED = 2;
const int  PACMAN = 3;
const int  WALL = 4;
const int  DEAMON = 5;
const int  COOKIE = 6;
const int  ERASER = 7;
const int  CLEAR = 8;
const int  SAVE = 9;

const int SIZE = 10;
class ToolBar
{
public:
	ToolBar();
	~ToolBar();

	void ToolBar::inputIcons();
	void ToolBar::drawToolBar(sf::RenderWindow &window);
	virtual void drawIcon(sf::RenderWindow &window, sf::Vector2f position);
	sf::RectangleShape & getIconImage(int i);
	void printToolBar(sf::RenderWindow &window);

private:
	sf::Texture m_pTexture[SIZE];
	sf::RectangleShape m_icon[SIZE];
	int arrY[SIZE];
	std::string m_all_pics[SIZE];
	bool m_color[3] = { false };

};

