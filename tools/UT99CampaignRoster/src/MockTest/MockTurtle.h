#ifndef MOCKTURTLE_H
#define MOCKTURTLE_H

#include "Turtle.h"
#include <gmock/gmock.h>

class MockTurtle : public Turtle
{
public:
    MockTurtle();

    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};

#endif // MOCKTURTLE_H
