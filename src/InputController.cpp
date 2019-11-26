#include <InputController.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

InputController::InputController()
{
    timer = sf::Clock();

    mouseDeltaX = 0;
    mouseDeltaY = 0;
    
    W = 0;
    S = 0;
    A = 0;
    D = 0;

    E = false;
    Q = false;

    Shift = false;
    Space = false;
    ESC = false;
    EMERGENCY_EXIT = false;
}

InputController::~InputController()
{

}

void InputController::updateMouseAndKeyValues()
{
    updateKeysValues();
    updateMouseValues();
}

void InputController::updateMouseValues()
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

    mouseDeltaX = d.x;
    mouseDeltaY = d.y;
}

void InputController::updateKeysValues()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ W = normalizedInput(W, true);} else{ W = normalizedInput(W, false);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ S = normalizedInput(S, true);} else{ S = normalizedInput(S, false);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ A = normalizedInput(A, true);} else{ A = normalizedInput(A, false);}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ D = normalizedInput(D, true);} else{ D = normalizedInput(D, false);}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)){ E = true;} else{ E = false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){ Q = true;} else{ Q = false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)){ Shift = true;} else{ Shift = false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){ Space = true;} else{ Space = false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){ ESC = true;} else{ ESC = false;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt)&&
      (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl))&&
      (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Delete))){ EMERGENCY_EXIT = true;} else{ EMERGENCY_EXIT = false;}
    
}

float InputController::normalizedInput(float previousVal, bool pressed)
{
    if(pressed)
    {
        previousVal += timer.getElapsedTime().asSeconds();
        if(previousVal >= 1)
        {
            previousVal = 1;
        }
    }
    else
    {
        previousVal -= timer.getElapsedTime().asSeconds();
        if(previousVal <= 0)
        {
           previousVal = 0; 
        }
    }

    return previousVal;
}

int InputController::getMouseDeltaX() const { return mouseDeltaX;}
int InputController::getMouseDeltaY() const { return mouseDeltaY;}
float InputController::getKeyW() const      { return W;}
float InputController::getKeyS() const      { return S;}
float InputController::getKeyA() const      { return A;}
float InputController::getKeyD() const      { return D;}
bool InputController::getKeyE() const       { return E;}
bool InputController::getKeyQ() const       { return Q;}
bool InputController::getKeyShift() const   { return Shift;}
bool InputController::getKeySpace() const   { return Space;}
bool InputController::getKeyESC() const     { return ESC;}
bool InputController::getKeyEMERGENCY_EXIT() const { return EMERGENCY_EXIT;}