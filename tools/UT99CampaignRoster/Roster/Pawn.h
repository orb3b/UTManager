#ifndef PAWN_H
#define PAWN_H

#include <QString>
#include <QMetaType>

class Pawn
{
public:
    enum Team {
        None,
        Red,
        Blue,
        Green,
        Gold
    };

public:
    Pawn(const QString &name = QString("Bot"),
         Team pawnTeam = Red,
         uint pawnLives = 10);

    Pawn(const Pawn &other);

    // Validity
    bool isValid() const;
    static Pawn Invalid();

    // Changed property - true if any setter was called
    bool changed() const;

    // Name
    QString name() const;
    void setName(const QString &name);

    // Team
    Team team() const;
    void setTeam(Team pawnTeam);

    // Lives
    uint lives() const;
    void setLives(uint pawnLives);

    // Stuff
    bool operator == (const Pawn &other);
    Pawn operator = (const Pawn &other);

private:
    void copy(const Pawn &other);

    static void registerPawnMetatype();

private:
    bool m_valid;
    bool m_changed;

    QString m_name;
    Team m_team;
    uint m_lives;
};
Q_DECLARE_METATYPE(Pawn)

#endif // PAWN_H
