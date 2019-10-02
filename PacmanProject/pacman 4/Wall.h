#include "Icons.h"
#pragma once



class Wall : public Icons
{
public:
	Wall(const sf::Vector2f& location, char symbol, sf::RectangleShape image, int color)
		:Icons{ location, symbol , image,color } {
		switch (color)
		{
		case BLUE:
			m_type = 'D';
			break;
		case GREEN:
			m_type = 'E';
			break;
		case RED:
			m_type = '#';
			break;

		}
	}
	
};

