#include "Pawn.h"
#include "Logs.h"

const int Pawn::MIN_SKILL_ADJUST = -4;
const int Pawn::MAX_SKILL_ADJUST = 4;

const double Pawn::MIN_ACCURACY = -1.0;
const double Pawn::MAX_ACCURACY = 1.0;

const double Pawn::MIN_ALERTNESS = -1.0;
const double Pawn::MAX_ALERTNESS = 1.0;

const double Pawn::MIN_CAMPING = 0.0;
const double Pawn::MAX_CAMPING = 1.0;

const double Pawn::MIN_STRAFING_AGILITY = -1.0;
const double Pawn::MAX_STRAFING_AGILITY = 1.0;

Pawn::Pawn(const QString &name, Pawn::Team pawnTeam, uint pawnLives) :
    m_null(false),
    m_changed(false),
    m_name(name),
    m_team(pawnTeam),
    m_lives(pawnLives),
    m_pawnClass(nullptr),
    m_skin(nullptr),
    m_face(nullptr),
    m_voice(nullptr),
    m_skillAdjust(0),
    m_favouriteWeapon(nullptr),
    m_accuracy(0.0),
    m_alertness(0.0),
    m_strafingAgility(0.0),
    m_camping(0.5),
    m_combatStyle(Normal),
    m_jumpy(false)
{

}

bool Pawn::isNull() const
{
    return m_null;
}

Pawn Pawn::Null()
{
    Pawn p;
    p.m_null = true;
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

PawnClass *Pawn::pawnClass() const
{
    return m_pawnClass.data();
}

void Pawn::setPawnClass(PawnClass *newClass)
{
    if (m_pawnClass != newClass) {
        m_pawnClass = newClass;
        m_changed = true;
    }
}

PawnSkin *Pawn::skin() const
{
    return m_skin.data();
}

void Pawn::setSkin(PawnSkin *newSkin)
{
    if (m_skin != newSkin) {
        m_skin = newSkin;
        m_changed = true;
    }
}

PawnFace *Pawn::face() const
{
    return m_face.data();
}

void Pawn::setFace(PawnFace *newFace)
{
    if (m_face != newFace) {
        m_face = newFace;
        m_changed = true;
    }
}

int Pawn::skillAdjust() const
{
    return m_skillAdjust;
}

bool Pawn::setSkillAdjust(int newSkillAdjust)
{
    if (m_skillAdjust == newSkillAdjust)
        return true;

    if (newSkillAdjust < MIN_SKILL_ADJUST || newSkillAdjust > MAX_SKILL_ADJUST)
        return false;

    m_skillAdjust = newSkillAdjust;
    m_changed = true;

    return true;
}

PawnVoice *Pawn::voice() const
{
    return m_voice.data();
}

void Pawn::setVoice(PawnVoice *newVoice)
{
    if (m_voice != newVoice) {
        m_voice = newVoice;
        m_changed = true;
    }
}

Weapon *Pawn::favouriteWeapon() const
{
    return m_favouriteWeapon.data();
}

void Pawn::setFavouriteWeapon(Weapon *weapon)
{
    if (m_favouriteWeapon != weapon) {
        m_favouriteWeapon = weapon;
        m_changed = true;
    }
}

double Pawn::accuracy() const
{
    return m_accuracy;
}

bool Pawn::setAccuracy(double newAccuracy)
{
    if (m_accuracy == newAccuracy)
        return true;    

    if (newAccuracy < MIN_ACCURACY || newAccuracy > MAX_ACCURACY)
        return false;

    m_accuracy = newAccuracy;
    m_changed = true;

    return true;
}

double Pawn::alertness() const
{
    return m_alertness;
}

bool Pawn::setAlertness(double newAlertness)
{
    if (m_alertness == newAlertness)
        return true;

    if (newAlertness < MIN_ALERTNESS || newAlertness > MAX_ALERTNESS)
        return false;

    m_alertness = newAlertness;
    m_changed = true;

    return true;
}

double Pawn::camping() const
{
    return m_camping;
}

bool Pawn::setCamping(double newCamping)
{
    if (m_camping == newCamping)
        return true;

    if (newCamping < MIN_CAMPING || newCamping > MAX_CAMPING)
        return false;

    m_camping = newCamping;
    m_changed = true;

    return true;
}

double Pawn::strafingAgility() const
{
    return m_strafingAgility;
}

bool Pawn::setStrafingAgility(double newStrafingAbility)
{
    if (m_strafingAgility == newStrafingAbility)
        return true;

    if (newStrafingAbility < MIN_STRAFING_AGILITY || newStrafingAbility > MAX_STRAFING_AGILITY)
        return false;

    m_strafingAgility = newStrafingAbility;
    m_changed = true;

    return true;
}

Pawn::CombatStyle Pawn::combatStyle() const
{
    return m_combatStyle;
}

void Pawn::setCombatStyle(Pawn::CombatStyle style)
{
    if (m_combatStyle != style) {
        m_combatStyle = style;
        m_changed = true;
    }
}

bool Pawn::jumpy() const
{
    return m_jumpy;
}

void Pawn::setJumpy(bool isJumpy)
{
    if (m_jumpy != isJumpy) {
        m_jumpy = isJumpy;
        m_changed = true;
    }
}

bool Pawn::operator ==(const Pawn &other)
{
    return m_name == other.name();
}

bool Pawn::operator !=(const Pawn &other)
{
    return !operator == (other);
}

void Pawn::copy(const Pawn &other)
{
    m_null = other.m_null;
    m_changed = other.m_changed;

    m_name = other.m_name;
    m_team = other.m_team;
    m_lives = other.m_lives;

    m_pawnClass = other.m_pawnClass;
    m_skin = other.m_skin;
    m_face = other.m_face;
    m_voice = other.m_voice;

    m_skillAdjust = other.m_skillAdjust;

    m_favouriteWeapon = other.m_favouriteWeapon;

    m_accuracy = other.m_accuracy;
    m_alertness = other.m_alertness;
    m_strafingAgility = other.m_strafingAgility;
    m_camping = other.m_camping;

    m_combatStyle = other.m_combatStyle;

    m_jumpy = other.m_jumpy;
}
