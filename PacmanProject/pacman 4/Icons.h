#pragma once
#include "ToolBar.h"
class Icons
{

protected:
	sf::Vector2f m_location = { 0,0 };        //location of the char and image
	sf::Texture m_loadImage;        //for loading image from 'Texture'
	sf::RectangleShape m_image{};				//the final image
	char m_type = ' ';
public:
	Icons(const sf::Vector2f& ve, char symbol, sf::RectangleShape image, int color);
		const sf::Vector2f& getLocation() const { return m_location; }
	char getType()const { return m_type; }
	const sf::RectangleShape& getImage()const { return m_image; }
	int m_color;
	~Icons();
	Icons() {};
};

