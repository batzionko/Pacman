#include "ToolBar.h"

const int iconSize = 50;//the size of icon

ToolBar::ToolBar()//constractor
{
	inputIcons();
	m_color[0] = true;
}

//-------------------------------------------------
ToolBar::~ToolBar()
{
}

//-------------------------------------------------
void ToolBar::inputIcons()//puts in array the name of picturs
{
	m_all_pics[0] = "blue.png";
	m_all_pics[1] = "green.png";
	m_all_pics[2] = "red.png";
	m_all_pics[3] = "pacman.png";
	m_all_pics[4] = "wall.png";
	m_all_pics[5] = "demon.png"; 
	m_all_pics[6] =  "yellowCookie.png";
	m_all_pics[7] = "eraser.png";
	m_all_pics[8] = "clear.png";
	m_all_pics[9] = "save.png";

}
//-------------------------------------------------
void ToolBar::drawToolBar(sf::RenderWindow &window)//get all from file and put in arrray of the shapes
{
	for (int i = 0; i < SIZE; i++)
	{
		sf::RectangleShape m_button(sf::Vector2f(50, 50));
		m_pTexture[i].loadFromFile(m_all_pics[i]);
		m_button.setTexture(&m_pTexture[i]);
		m_button.setPosition(sf::Vector2f{ 10,5+(float(i * 60)) });
		m_button.setOutlineColor(sf::Color::White);
		m_button.setOutlineThickness(1);
		m_icon[i] = m_button;
	}

}
//-------------------------------------------------
//print the toolbar
void ToolBar::printToolBar(sf::RenderWindow &window)
{
	for (int i = 0; i < SIZE; i++)
		window.draw(m_icon[i]);
}
//-------------------------------------------------
//get the icon
sf::RectangleShape & ToolBar:: getIconImage(int i)
{
	
	return m_icon[i];
	
}
void ToolBar::drawIcon(sf::RenderWindow &window, sf::Vector2f position) {}//draw the icon

//-----------------------------






