#ifndef PAWN_H
#define PAWN_H

#include <QString>
#include <QMetaType>
#include <QPointer>

#include "PawnClass.h"
#include "PawnSkin.h"
#include "PawnFace.h"
#include "PawnVoice.h"
#include "Weapon.h"

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

    static const int MIN_SKILL_ADJUST; // -4
    static const int MAX_SKILL_ADJUST; //  4

    static const double MIN_ACCURACY; // -1.0
    static const double MAX_ACCURACY; //  1.0

    static const double MIN_ALERTNESS; // -1.0
    static const double MAX_ALERTNESS; //  1.0

    static const double MIN_CAMPING; // 0.0
    static const double MAX_CAMPING; // 1.0

    static const double MIN_STRAFING_AGILITY; // -1.0
    static const double MAX_STRAFING_AGILITY; //  1.0

    enum CombatStyle {
        Normal,
        Aggressive,
        Berserk,
        Cautious,
        Avoidant
    };

public:
    Pawn(const QString &name = QString("Bot"),
         Team pawnTeam = Red,
         uint pawnLives = 10);

    Pawn(const Pawn &other);

    // Validity
    bool isNull() const;
    static Pawn Null();

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

    // Class, returns nullptr if no class
    PawnClass *pawnClass() const;
    void setPawnClass(PawnClass *newClass);

    // Skin, returns nullptr if no skin
    PawnSkin *skin() const;
    void setSkin(PawnSkin *newSkin);

    // Face, returns nullptr if no face
    PawnFace *face() const;
    void setFace(PawnFace *newFace);

    // Voice, returns nullptr if no voice
    PawnVoice *voice() const;
    void setVoice(PawnVoice *newVoice);

    // Skill Adjust, between -4 and 4
    int skillAdjust() const;
    bool setSkillAdjust(int newSkillAdjust);

    // Pawn's favourite weapon
    Weapon *favouriteWeapon() const;
    void setFavouriteWeapon(Weapon* weapon);

    // Accuracy, between MIN and MAX (see below)
    double accuracy() const;
    bool setAccuracy(double newAccuracy);

    // Alertness, between MIN and MAX (see below)
    double alertness() const;
    bool setAlertness(double newAlertness);

    // Camping, between MIN and MAX (see below)
    double camping() const;
    bool setCamping(double newCamping);

    // Strafing ability, between MIN and MAX (see below)
    double strafingAgility() const;
    bool setStrafingAgility(double newStrafingAbility);

    // Combat style
    CombatStyle combatStyle() const;
    void setCombatStyle(CombatStyle style);

    // Jumpy behaviour
    bool jumpy() const;
    void setJumpy(bool isJumpy);

    // Stuff
    bool operator == (const Pawn &other);
    bool operator != (const Pawn &other);

    Pawn operator = (const Pawn &other);

private:
    void copy(const Pawn &other);

    static void registerPawnMetatype();

private:
    bool m_null;
    bool m_changed;

    QString m_name;
    Team m_team;
    uint m_lives;

    QPointer<PawnClass> m_pawnClass;
    QPointer<PawnSkin> m_skin;
    QPointer<PawnFace> m_face;
    QPointer<PawnVoice> m_voice;

    uint m_skillAdjust;

    QPointer<Weapon> m_favouriteWeapon;

    double m_accuracy;
    double m_alertness;
    double m_strafingAgility;
    double m_camping;

    CombatStyle m_combatStyle;

    bool m_jumpy;
};
Q_DECLARE_METATYPE(Pawn)
Q_DECLARE_METATYPE(Pawn::Team)
Q_DECLARE_METATYPE(Pawn::CombatStyle)

#endif // PAWN_H
