#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
	: m_position{startPosition},
	  m_pointToLookAt{m_position - Vector3f{0, 0, -1}},
	  m_lookDirection{m_pointToLookAt - m_position},
	  m_lookDirectionFlat{m_lookDirection},
	  m_radius{defaultRadius}
{
}

void Camera::update(const Vector3f& target, const sf::Vector2i& deltaMouse, const InputController& InputController, float mouseSpeed)
{

}

void Camera::updateCameraPosition()
{
	m_position = m_pointToLookAt + calculateCameraOffset();

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

Vector3f Camera::calculateCameraOffset()
{
	auto [alpha, beta, _] = m_rotationAngles;
	return Vector3f{cosf(alpha) * cosf(beta), sinf(beta), cosf(beta) * sinf(alpha)} * m_radius;
}

void Camera::updateRotationAngles()
{
	m_rotationAngles = m_rotation / twoPi;
}

void Camera::updateCameraRotation(const sf::Vector2i& deltaMouse, float mouseSpeed)
{
	auto [_1, beta, _2] = m_rotationAngles;

	Vector3f deltaRotation{static_cast<float>(deltaMouse.x), 0.0f, 0.0f};

	m_canLookUp = beta < halfPi-0.4;
	m_canLookDown = beta > -halfPi+0.4;

	if (m_canLookUp && deltaMouse.y < 0.0f || m_canLookDown && deltaMouse.y > 0.0f)
	{
		deltaRotation += Vector3f{0.0f, -static_cast<float>(deltaMouse.y) , 0.0f};
	}
	
	m_rotation += deltaRotation*mouseSpeed;

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateLookDirectionCallback()
{
	m_lookDirection = Vector3f(m_pointToLookAt - m_position).normal();
	m_lookDirectionFlat = Vector3f{m_lookDirection.x, 0, m_lookDirection.z}.normal();
}

void Camera::updateSideDirectionCallback()
{
	m_right = Vector3f(-m_lookDirection.z, 0, m_lookDirection.x).normal();
}

void Camera::updatePointToLookAtPosition(const Vector3f &newPosition)
{
	m_pointToLookAt = newPosition + Vector3f{0.0f, 0.5f, 0.0f};
}

void Camera::updateWalkDirection(const InputController &input)
{
	Vector3f newWalkDir{};

	newWalkDir += m_lookDirectionFlat * input.getKeyW();
	newWalkDir -= m_lookDirectionFlat * input.getKeyS();
	newWalkDir -= m_right * input.getKeyA();
	newWalkDir += m_right * input.getKeyD();
	
	if (newWalkDir.length() > 1.0f)
	{
		newWalkDir.normalize();
	}

	m_front = newWalkDir;
}

glm::mat4 Camera::moveCamera()
{
	glm::vec3 position{m_position.x, m_position.y, m_position.z};
	glm::vec3 lookAtPoint{m_pointToLookAt.x, m_pointToLookAt.y, m_pointToLookAt.z};

	return glm::lookAt(position, lookAtPoint, up);
}