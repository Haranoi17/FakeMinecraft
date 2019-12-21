#pragma once
#include <SFML/Graphics.hpp>

class InputController 
{
public:

    InputController();
    ~InputController();

    void updateKeysValues();
    void updateMouseValues();
    void updateMouseAndKeyValues();

    int getMouseDeltaX() const;
    int getMouseDeltaY() const;
    bool getMouseLeft() const;
    bool getMouseRight() const;
    float getKeyW() const;
    float getKeyS() const;
    float getKeyA() const;
    float getKeyD() const;
    bool getKeyE() const;
    bool getKeyQ() const;
    bool getKeyShift() const;
    bool getKeySpace() const;
    bool getKeyESC() const;
    bool getKeyEMERGENCY_EXIT() const;

private:

    sf::Clock timer;

    float normalizedInput(float, bool, float);

    int mouseDeltaX;
    int mouseDeltaY;
    
    bool mouseLeft;
    bool mouseRight;

    float W;
    float S;
    float A;
    float D;
    
    bool E;
    bool Q;

    bool Shift;
    bool Space;
    bool ESC;
    bool EMERGENCY_EXIT;
};