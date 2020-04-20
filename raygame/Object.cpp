#include "Object.h"

void Object::draw()
{
	DrawRectangle((int)m_position.x, (int)m_position.y, 50, 50, m_color);
}
