#include <mouseHandling.hpp>

sf::Vector2i mouseHandling()
{
	static	sf::Vector2i 	prev = sf::Mouse::getPosition();
	sf::Vector2i 			mousePos = sf::Mouse::getPosition();
	sf::Vector2i 			d = mousePos - prev;

	if(mousePos.x == 0)
	{
		mousePos.x = 1918;
		prev.x = 1919;
		sf::Mouse::setPosition(mousePos);
	}
	if(mousePos.x == 1919)
	{
		mousePos.x = 1;
		prev.x = 0;
		sf::Mouse::setPosition(mousePos);
	}
	if(mousePos.y == 0)
	{
		mousePos.y = 1078;
		prev.y = 1079;
		sf::Mouse::setPosition(mousePos);
	}
	if(mousePos.y == 1079)
	{
		mousePos.y = 1;
		prev.y = 0;
		sf::Mouse::setPosition(mousePos);
	}
	else
	{
		prev = mousePos;
	}
	
	d.y = -d.y;
	return d;
}
