#pragma once
#include "raylib.h"
#include <vector>

class Object
{
public:

	Object() {}
	virtual ~Object() {}

	//Draw the object
	virtual void draw();

	//Position functions
	void setPosition(Vector2 position) { m_position = position; }
	Vector2 getPosition() { return m_position; }

	//Color functions
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

protected:

	//Position Vector variable
	Vector2 m_position = { 0.0f, 0.0f };

	Color m_color = BLUE;
};