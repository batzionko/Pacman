#include "Icons.h"
#pragma once



class Pacman : public Icons
{
public:
	Pacman(const sf::Vector2f& location, char symbol, sf::RectangleShape image, int color)
		:Icons{ location, symbol , image, color } {
		
		switch (color)
		{
		case BLUE:
			m_type = 'S';
			break;
		case GREEN:
			m_type = 'W';
			break;
		case RED:
			m_type = '@';
			break;

		}


				m_type = '@';
	}

};

