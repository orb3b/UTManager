#include "Painter.h"

#include "Turtle.h"

Painter::Painter(Turtle *turtle) :
    m_turtle(turtle)
{
}


bool Painter::DrawCircle(int /*x*/, int /*y*/, int /*radius*/)
{
    m_turtle->PenDown();
    return true;
}
