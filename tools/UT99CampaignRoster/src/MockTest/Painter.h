#ifndef PAINTER_H
#define PAINTER_H

class Turtle;

class Painter
{
public:
    Painter(Turtle *turtle);

    virtual bool DrawCircle(int x, int y, int radius);

private:
    Turtle *m_turtle;
};

#endif // PAINTER_H
