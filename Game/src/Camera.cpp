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

void Camera::updateCameraPosition()
{
	const float alpha = m_rotation.x / twoPi;
	const float beta = -m_rotation.y / twoPi;

	m_position = m_pointToLookAt;

	m_position.x += m_radius * cos(alpha) * cos(beta);
	m_position.y += m_radius * sin(beta);
	m_position.z += m_radius * cos(beta) * sin(alpha);

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateCameraRotation(const InputController &input, float mouseSpeed)
{
	static bool canLookUp = 1;
	static bool canLookDown = 1;

	float radY = m_rotation.y / (2 * pi);

	m_rotation.x += (float)input.getMouseDeltaX() * mouseSpeed;

	if (radY > pi / 2 - 0.1) // less than pi/2
	{
		canLookUp = 0;
	}
	else
	{
		canLookUp = 1;
	}
	if (radY < -pi / 2 + 0.1) // less than pi/2
	{
		canLookDown = 0;
	}
	else
	{
		canLookDown = 1;
	}

	if (canLookUp && input.getMouseDeltaY() > 0)
	{
		m_rotation.y += (float)input.getMouseDeltaY() * mouseSpeed;
	}
	if (canLookDown && input.getMouseDeltaY() < 0)
	{
		m_rotation.y += (float)input.getMouseDeltaY() * mouseSpeed;
	}

	updateLookDirectionCallback();
	updateSideDirectionCallback();
}

void Camera::updateLookDirectionCallback()
{
	m_lookDirection = m_pointToLookAt - m_position;
	m_lookDirection.normalize();
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
	Vector3f newWalkDir;

	if (input.getKeyW())
	{
		newWalkDir += m_lookDirectionFlat * input.getKeyW();
	}

	if (input.getKeyS())
	{
		newWalkDir -= m_lookDirectionFlat * input.getKeyS();
	}

	if (input.getKeyA())
	{
		newWalkDir -= m_right * input.getKeyA();
	}

	if (input.getKeyD())
	{
		newWalkDir += m_right * input.getKeyD();
	}
	if (newWalkDir.length() > 1)
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