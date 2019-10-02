#include "Icons.h"
#pragma once



class Deamon : public Icons
{
public:
	Deamon(const sf::Vector2f& location, char symbol, sf::RectangleShape image, int color)
		:Icons{ location, symbol , image, color } {
		switch (color)
		{
		case BLUE:
			m_type = 'G';
			break;
		case GREEN:
			m_type = 'T';
			break;
		case RED:
			m_type = '%';
			break;

		}
		
	}

};
