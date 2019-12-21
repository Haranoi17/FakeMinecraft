#include <externs.hpp>
#include <functions.hpp> //update.hpp is already here
#include <math.h>

void update()
{
	input.updateMouseAndKeyValues();
	player.cam.updateCameraRotation(input, mouseSpeed);
	
	player.cam.updateWalkDirection(input);
	player.walk(input);
	
	player.cam.updatePointToLookAtPosition(player.pos);
	player.cam.updateCameraPosition();
	player.updateGunPos();
}

