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
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num0))
				{
					glMatrixMode(GL_PROJECTION);
					glLoadIdentity();
					glOrtho(-500, -500, 500, 500, 0.2, 1000);
					glMatrixMode(GL_MODELVIEW);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
				{
					fov += 0.5;
					reshapeScreen();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
				{
					fov -= 0.5;
					reshapeScreen();
				}
			}
		}
	}
}
