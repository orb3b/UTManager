#include "Pawn.h"

Pawn::Pawn(const QString &name, Pawn::Team pawnTeam, uint pawnLives) :
    m_valid(true),
    m_name(name),
    m_team(pawnTeam),
    m_lives(pawnLives),
    m_changed(false)
{

}

Pawn::Pawn(const Pawn &other)
{
    copy(other);
}

bool Pawn::isValid() const
{
    return m_valid;
}

Pawn Pawn::Invalid()
{
    Pawn p;
    p.m_valid = false;
    return p;
}

bool Pawn::changed() const
{
    return m_changed;
}

QString Pawn::name() const
{
    return m_name;
}

void Pawn::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        m_changed = true;
    }
}

Pawn::Team Pawn::team() const
{
    return m_team;
}

void Pawn::setTeam(Pawn::Team pawnTeam)
{
    if (m_team != pawnTeam) {
        m_team = pawnTeam;
        m_changed = true;
    }
}

uint Pawn::lives() const
{
    return m_lives;
}

void Pawn::setLives(uint pawnLives)
{
    if (m_lives != pawnLives) {
        m_lives = pawnLives;
        m_changed = true;
    }
}

bool Pawn::operator ==(const Pawn &other)
{
    return m_name == other.name();
}

Pawn Pawn::operator =(const Pawn &other)
{
    copy(other);
    return *this;
}

void Pawn::copy(const Pawn &other)
{
    m_valid = other.m_valid;
    m_changed = other.m_changed;

    m_name = other.m_name;
    m_team = other.m_team;
    m_lives = other.m_lives;
}
