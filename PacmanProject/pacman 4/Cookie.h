#include "Icons.h"
#pragma once



class Cookie : public Icons
{
public:
	Cookie(const sf::Vector2f& location, char symbol, sf::RectangleShape image, int color)
		:Icons{ location, symbol , image, color } {
		
		switch (color)
		{
		case BLUE:
			m_type = 'K';
			break;
		case GREEN:
			m_type = 'I';
			break;
		case RED:
			m_type = '*';
			break;

		}
	}

};

