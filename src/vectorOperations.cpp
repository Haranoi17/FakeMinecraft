#include <vectorOperations.hpp>
#include <math.h>

void normalize(sf::Vector3f& vec)
{
	float len = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	
	if (len) 
	{
		vec.x /= len;
		vec.y /= len;
		vec.z /= len;
	}
}

float vec3Length(float x, float y, float z)
{
	return sqrt(x*x + y*y + z*z);
}