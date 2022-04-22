#pragma once

#include <SFML/Graphics.hpp>
#include <glm/matrix.hpp>
#include <iostream>
#include <InputController.hpp>
#include <Vector3f.hpp>

class Camera
{
private:
	static inline const Vector3f startPosition{0.0f, 3.0f, -5.0f};
	static inline constexpr float pi{M_PI};
	static inline constexpr float twoPi{M_PI * 2.0f};
	static inline constexpr float halfPi{M_PI / 2.0f};
	static inline constexpr float defaultRadius{1.0f};
	static inline constexpr glm::vec3 up{0.0f, 1.0f, 0.0f};

public:
	Camera();

	void update(const Vector3f& target, const sf::Vector2i& deltaMouse, const InputController& InputController, float mouseSpeed);

	glm::mat4 moveCamera();

private:
	float m_radius;
	Vector3f m_position;
	Vector3f m_rotation;
	Vector3f m_rotationAngles;
	Vector3f m_pointToLookAt;
	Vector3f m_lookDirection;
	Vector3f m_lookDirectionFlat;
	Vector3f m_front;
	Vector3f m_right;
	
	bool m_canLookUp = true;
	bool m_canLookDown = true;

public:
	Vector3f calculateCameraOffset();
	void updateRotationAngles();

	void updateLookDirectionCallback();
	void updateSideDirectionCallback();
	
	void updateCameraPosition();
	void updateCameraRotation(const sf::Vector2i& deltaMouse, float mouseSpeed);

	void updateWalkDirection(const InputController &inputController);

	void updatePointToLookAtPosition(const Vector3f &newPosition);

	Vector3f getPosition(){return m_position;}
	Vector3f getFront(){return m_front;}
};
