#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main()
{
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "pacman window");
	Window.setKeyRepeatEnabled(false);
	sf::Texture pTextureB, pTextureG, pTextureR, pTextureP, pTextureW, pTextureE, pTextureC,pTextureS, pTextureY,pTextureD;
	sf::Sprite blue,green,red,pacman,wall,eraser,clear,save,yellowCookie,demon;
	sf::RectangleShape 
		rectB(sf::Vector2f(50, 50)),
		rectG(sf::Vector2f(50, 50)),
		rectR(sf::Vector2f(50, 50)),
		rectP(sf::Vector2f(50, 50)),
		rectW(sf::Vector2f(50, 50)),
		rectE(sf::Vector2f(50, 50)),
		rectC(sf::Vector2f(50, 50)),
		rectS(sf::Vector2f(50, 50)),
		rectY(sf::Vector2f(50, 50)),
		rectD{ sf::Vector2f(50, 50) };

	//פתיחה של כל התמונות-אייקונים
	if (!pTextureB.loadFromFile("blue.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureG.loadFromFile("green.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureR.loadFromFile("red.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureP.loadFromFile("pacman.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureW.loadFromFile("wall.jpg"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureE.loadFromFile("eraser.jpg"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureC.loadFromFile("clear.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureS.loadFromFile("save.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureY.loadFromFile("yellowCookie.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	if (!pTextureD.loadFromFile("demon.jpg"))
	{
		std::cout << "not found!" << std::endl;
	}
	sf::RectangleShape m_Line;
	sf::RectangleShape m_Row;

	//הכנסה לתפריט
	rectB.setTexture(&pTextureB);
	rectB.setPosition(10, 10);
	rectB.setOutlineColor(sf::Color::White);
	rectB.setOutlineThickness(1);
	rectG.setTexture(&pTextureG);
	rectG.setPosition(10, 70);
	rectG.setOutlineColor(sf::Color::White);
	rectG.setOutlineThickness(1);
	rectR.setTexture(&pTextureR);
	rectR.setPosition(10, 130);
	rectR.setOutlineColor(sf::Color::White);
	rectR.setOutlineThickness(1);
	rectP.setTexture(&pTextureP);
	rectP.setPosition(10, 190);
	rectP.setOutlineColor(sf::Color::White);
	rectP.setOutlineThickness(1);
	rectW.setTexture(&pTextureW);
	rectW.setPosition(10, 250);
	rectW.setOutlineColor(sf::Color::White);
	rectW.setOutlineThickness(1);
	rectE.setTexture(&pTextureE);
	rectE.setPosition(10, 310);
	rectE.setOutlineColor(sf::Color::White);
	rectE.setOutlineThickness(1);
	rectC.setTexture(&pTextureC);
	rectC.setPosition(10, 370);
	rectC.setOutlineColor(sf::Color::White);
	rectC.setOutlineThickness(1);
	rectS.setTexture(&pTextureS);
	rectS.setPosition(10, 430);
	rectS.setOutlineColor(sf::Color::White);
	rectS.setOutlineThickness(1);
	rectY.setTexture(&pTextureY);
	rectY.setPosition(10, 490);
	rectY.setOutlineColor(sf::Color::White);
	rectY.setOutlineThickness(1);
	rectD.setTexture(&pTextureD);
	rectD.setPosition(10, 550);
	rectD.setOutlineColor(sf::Color::White);
	rectD.setOutlineThickness(1);


	//sf::RectangleShape rect(sf::Vector2f(200, 100));
	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Escape)
					Window.close();
				break;


			}

		}
		//הדפסה
		Window.draw(rectB);
		Window.draw(rectG);
		Window.draw(rectR);
		Window.draw(rectW);
		Window.draw(rectP);
		Window.draw(rectE);
		Window.draw(rectC);
		Window.draw(rectS);
		Window.draw(rectY);
		Window.draw(rectD);
		Window.display();
		Window.clear();

	}
	return EXIT_SUCCESS;
}