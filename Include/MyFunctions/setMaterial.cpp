#include <SFML/OpenGL.hpp>
#include <materials.h>

void setMaterial(int x)
{
	switch(x)
	{
		case 1: 
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, EmeraldAmbient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, EmeraldDiffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, EmeraldSpecular);
			glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, EmeraldShininess);
		}
			case 2: 
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, BronzeAmbient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, BronzeDiffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, BronzeSpecular);
			glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, BronzeShininess);
		}
			case 3: 
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, PolishedGoldAmbient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, PolishedGoldDiffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, PolishedGoldSpecular);
			glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, PolishedGoldShininess);
		}
		default:
		{
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, DefaultAmbient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DefaultDiffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, DefaultSpecular);
			glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, DefaultShininess);
		}
	}

}