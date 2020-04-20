#include "Object.h"

void Object::draw()
{
	DrawRectangle((int)m_position.x, (int)m_position.y, 100, 100, m_color);
}
