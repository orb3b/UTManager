#include <QString>
#include <QtTest>

#include "Pawn.h"
#include "PawnClass.h"
#include "PawnSkin.h"
#include "PawnFace.h"
#include "PawnVoice.h"
#include "Weapon.h"

class tst_Pawn : public QObject
{
    Q_OBJECT

public:
    tst_Pawn();

private Q_SLOTS:
    void setName_data();
    void setName();

    void setTeam_data();
    void setTeam();

    void setLives_data();
    void setLives();

    void setPawnClass_NormalAndRemoteDeletion();
    void setPawnClass_Same();

    void setSkin_NormalAndRemoteDeletion();
    void setSkin_Same();

    void setFace_NormalAndRemoteDeletion();
    void setFace_Same();

    void setVoice_NormalAndRemoteDeletion();
    void setVoice_Same();

    void setSkillAdjust_data();
    void setSkillAdjust();

    void setFavouriteWeapon_NormalAndRemoteDeletion();
    void setFavouriteWeapon_Same();

    void setAccuracy_data();
    void setAccuracy();

    void setAlertness_data();
    void setAlertness();

    void setCamping_data();
    void setCamping();

    void setStrafingAbility_data();
    void setStrafingAbility();

    void setCombatStyle_data();
    void setCombatStyle();

    void setJumpy_data();
    void setJumpy();
};

tst_Pawn::tst_Pawn()
{
}

void tst_Pawn::setName_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("result");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal") << "MyName" << "MyName" << true;
    QTest::newRow("empty") << "" << QString() << true;
    QTest::newRow("same") << Pawn().name() << Pawn().name() << false;
}

void tst_Pawn::setName()
{
    QFETCH(QString, input);
    QFETCH(QString, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setName(input);

    QCOMPARE(p.name(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setTeam_data()
{
    QTest::addColumn<Pawn::Team>("input");
    QTest::addColumn<Pawn::Team>("result");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal") << Pawn::Gold << Pawn::Gold << true;
    QTest::newRow("same") << Pawn().team() << Pawn().team() << false;
}

void tst_Pawn::setTeam()
{
    QFETCH(Pawn::Team, input);
    QFETCH(Pawn::Team, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setTeam(input);

    QCOMPARE(p.team(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setLives_data()
{
    QTest::addColumn<uint>("input");
    QTest::addColumn<uint>("result");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal") << 25u << 25u << true;
    QTest::newRow("same") << Pawn().lives() << Pawn().lives() << false;
}

void tst_Pawn::setLives()
{
    QFETCH(uint, input);
    QFETCH(uint, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setLives(input);

    QCOMPARE(p.lives(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setPawnClass_NormalAndRemoteDeletion()
{
    Pawn p;
    PawnClass *input = new PawnClass();

    p.setPawnClass(input);

    QCOMPARE(p.pawnClass(), input);
    QVERIFY(p.changed());

    delete input;
    input = nullptr;

    QCOMPARE(p.pawnClass(), input);
}

void tst_Pawn::setPawnClass_Same()
{
    Pawn p;

    PawnClass *input = p.pawnClass();

    p.setPawnClass(p.pawnClass());

    QCOMPARE(p.pawnClass(), input);
    QVERIFY(!p.changed());
}

void tst_Pawn::setSkin_NormalAndRemoteDeletion()
{
    Pawn p;
    PawnSkin *input = new PawnSkin();

    p.setSkin(input);

    QCOMPARE(p.skin(), input);
    QVERIFY(p.changed());

    delete input;
    input = nullptr;

    QCOMPARE(p.skin(), input);
}

void tst_Pawn::setSkin_Same()
{
    Pawn p;

    PawnSkin *input = p.skin();

    p.setSkin(p.skin());

    QCOMPARE(p.skin(), input);
    QVERIFY(!p.changed());
}

void tst_Pawn::setFace_NormalAndRemoteDeletion()
{
    Pawn p;
    PawnFace *input = new PawnFace();

    p.setFace(input);

    QCOMPARE(p.face(), input);
    QVERIFY(p.changed());

    delete input;
    input = nullptr;

    QCOMPARE(p.face(), input);
}

void tst_Pawn::setFace_Same()
{
    Pawn p;

    PawnFace *input = p.face();

    p.setFace(p.face());

    QCOMPARE(p.face(), input);
    QVERIFY(!p.changed());
}

void tst_Pawn::setVoice_NormalAndRemoteDeletion()
{
    Pawn p;
    PawnVoice *input = new PawnVoice();

    p.setVoice(input);

    QCOMPARE(p.voice(), input);
    QVERIFY(p.changed());

    delete input;
    input = nullptr;

    QCOMPARE(p.voice(), input);
}

void tst_Pawn::setVoice_Same()
{
    Pawn p;

    PawnVoice *input = p.voice();

    p.setVoice(p.voice());

    QCOMPARE(p.voice(), input);
    QVERIFY(!p.changed());
}

void tst_Pawn::setSkillAdjust_data()
{
    QTest::addColumn<int>("input");
    QTest::addColumn<int>("result");
    QTest::addColumn<bool>("result_changed");

    int normal = 1,
        min = Pawn::MIN_SKILL_ADJUST,
        lessMin = min - 2,
        max = Pawn::MAX_SKILL_ADJUST,
        moreMax = max + 1;

    QTest::newRow(QString("normal (%1)").arg(normal).toLatin1()) << normal << normal << true;
    QTest::newRow(QString("normal min (%1)").arg(min).toLatin1()) << min << min << true;
    QTest::newRow(QString("normal max (%1)").arg(max).toLatin1()) << max << max << true;
    QTest::newRow(QString("normal >max (%1)").arg(lessMin).toLatin1()) << lessMin << Pawn().skillAdjust() << false;
    QTest::newRow(QString("normal min< (%1)").arg(moreMax).toLatin1()) << moreMax << Pawn().skillAdjust() << false;
    QTest::newRow("same") << Pawn().skillAdjust() << Pawn().skillAdjust() << false;
}

void tst_Pawn::setSkillAdjust()
{
    QFETCH(int, input);
    QFETCH(int, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setSkillAdjust(input);

    QCOMPARE(p.skillAdjust(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setFavouriteWeapon_NormalAndRemoteDeletion()
{
    Pawn p;
    Weapon *input = new Weapon();

    p.setFavouriteWeapon(input);

    QCOMPARE(p.favouriteWeapon(), input);
    QVERIFY(p.changed());

    delete input;
    input = nullptr;

    QCOMPARE(p.favouriteWeapon(), input);
}

void tst_Pawn::setFavouriteWeapon_Same()
{
    Pawn p;

    Weapon *input = p.favouriteWeapon();

    p.setFavouriteWeapon(p.favouriteWeapon());

    QCOMPARE(p.favouriteWeapon(), input);
    QVERIFY(!p.changed());
}

void tst_Pawn::setAccuracy_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("result");
    QTest::addColumn<bool>("result_changed");

    double normal = 0.25,
           min = Pawn::MIN_ACCURACY,
           lessMin = min - 0.1,
           max = Pawn::MAX_ACCURACY,
           moreMax = max + 1.222;

    QTest::newRow(QString("normal (%1)").arg(normal).toLatin1()) << normal << normal << true;
    QTest::newRow(QString("normal min (%1)").arg(min).toLatin1()) << min << min << true;
    QTest::newRow(QString("normal max (%1)").arg(max).toLatin1()) << max << max << true;
    QTest::newRow(QString("normal <min (%1)").arg(lessMin).toLatin1()) << lessMin << Pawn().accuracy() << false;
    QTest::newRow(QString("normal >max (%1)").arg(moreMax).toLatin1()) << moreMax << Pawn().accuracy() << false;
    QTest::newRow("same") << Pawn().accuracy() << Pawn().accuracy() << false;
}

void tst_Pawn::setAccuracy()
{
    QFETCH(double, input);
    QFETCH(double, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setAccuracy(input);

    QCOMPARE(p.accuracy(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setAlertness_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("result");
    QTest::addColumn<bool>("result_changed");

    double normal = 0.25,
           min = Pawn::MIN_ALERTNESS,
           lessMin = min - 0.1,
           max = Pawn::MAX_ALERTNESS,
           moreMax = max + 0.003;

    QTest::newRow(QString("normal (%1)").arg(normal).toLatin1()) << normal << normal << true;
    QTest::newRow(QString("normal min (%1)").arg(min).toLatin1()) << min << min << true;
    QTest::newRow(QString("normal max (%1)").arg(max).toLatin1()) << max << max << true;
    QTest::newRow(QString("normal <min (%1)").arg(lessMin).toLatin1()) << lessMin << Pawn().alertness() << false;
    QTest::newRow(QString("normal >max (%1)").arg(moreMax).toLatin1()) << moreMax << Pawn().alertness() << false;
    QTest::newRow("same") << Pawn().alertness() << Pawn().alertness() << false;
}

void tst_Pawn::setAlertness()
{
    QFETCH(double, input);
    QFETCH(double, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setAlertness(input);

    QCOMPARE(p.alertness(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setCamping_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("result");
    QTest::addColumn<bool>("result_changed");

    double normal = 0.25,
           min = Pawn::MIN_CAMPING,
           lessMin = min - 0.0001,
           max = Pawn::MAX_CAMPING,
           moreMax = max + 0.99;

    QTest::newRow(QString("normal (%1)").arg(normal).toLatin1()) << normal << normal << true;
    QTest::newRow(QString("normal min (%1)").arg(min).toLatin1()) << min << min << true;
    QTest::newRow(QString("normal max (%1)").arg(max).toLatin1()) << max << max << true;
    QTest::newRow(QString("normal <min (%1)").arg(lessMin).toLatin1()) << lessMin << Pawn().camping() << false;
    QTest::newRow(QString("normal >max (%1)").arg(moreMax).toLatin1()) << moreMax << Pawn().camping() << false;
    QTest::newRow("same") << Pawn().camping() << Pawn().camping() << false;
}

void tst_Pawn::setCamping()
{
    QFETCH(double, input);
    QFETCH(double, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setCamping(input);

    QCOMPARE(p.camping(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setStrafingAbility_data()
{
    QTest::addColumn<double>("input");
    QTest::addColumn<double>("result");
    QTest::addColumn<bool>("result_changed");

    double normal = 0.25,
           min = Pawn::MIN_STRAFING_AGILITY,
           lessMin = min - 0.00001,
           max = Pawn::MAX_STRAFING_AGILITY,
           moreMax = max + 0.00001;

    QTest::newRow(QString("normal (%1)").arg(normal).toLatin1()) << normal << normal << true;
    QTest::newRow(QString("normal min (%1)").arg(min).toLatin1()) << min << min << true;
    QTest::newRow(QString("normal max (%1)").arg(max).toLatin1()) << max << max << true;
    QTest::newRow(QString("normal <min (%1)").arg(lessMin).toLatin1()) << lessMin << Pawn().strafingAgility() << false;
    QTest::newRow(QString("normal >max (%1)").arg(moreMax).toLatin1()) << moreMax << Pawn().strafingAgility() << false;
    QTest::newRow("same") << Pawn().strafingAgility() << Pawn().strafingAgility() << false;
}

void tst_Pawn::setStrafingAbility()
{
    QFETCH(double, input);
    QFETCH(double, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setStrafingAgility(input);

    QCOMPARE(p.strafingAgility(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setCombatStyle_data()
{
    QTest::addColumn<Pawn::CombatStyle>("input");
    QTest::addColumn<Pawn::CombatStyle>("result");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal") << Pawn::Berserk << Pawn::Berserk << true;
    QTest::newRow("same") << Pawn().combatStyle() << Pawn().combatStyle() << false;
}

void tst_Pawn::setCombatStyle()
{
    QFETCH(Pawn::CombatStyle, input);
    QFETCH(Pawn::CombatStyle, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setCombatStyle(input);

    QCOMPARE(p.combatStyle(), result);
    QVERIFY(p.changed() == result_changed);
}

void tst_Pawn::setJumpy_data()
{
    QTest::addColumn<bool>("input");
    QTest::addColumn<bool>("result");
    QTest::addColumn<bool>("result_changed");

    QTest::newRow("normal") << true << true << true;
    QTest::newRow("same") << Pawn().jumpy() << Pawn().jumpy() << false;
}

void tst_Pawn::setJumpy()
{
    QFETCH(bool, input);
    QFETCH(bool, result);
    QFETCH(bool, result_changed);

    Pawn p;

    p.setJumpy(input);

    QCOMPARE(p.jumpy(), result);
    QVERIFY(p.changed() == result_changed);
}

QTEST_APPLESS_MAIN(tst_Pawn)

#include "tst_pawn.moc"
