#include <externs.hpp>
#include <functions.hpp> // eventHandling.hpp is already here

void eventHandling()
{
	while (window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed: window.close();
			case sf::Event::Resized: reshapeScreen();
			case sf::Event::KeyPressed:
			{
				if(input.getKeyEMERGENCY_EXIT())
				{
					window.close();
				}
			}
		}
	}
}
