#include "Icons.h"


Icons::Icons(const sf::Vector2f& location, char symbol, sf::RectangleShape image, int color)
	:m_location(location), m_type(symbol), m_image(image),m_color(color)
{
	m_image.setPosition(sf::Vector2f{ m_location });//sets location on board
}




Icons::~Icons()
{
}


