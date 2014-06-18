#include <QCoreApplication>
#include <QSettings>
#include <QTextCodec>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int startId = 0;
    int endId = 3;

    QSettings config("User.ini", QSettings::IniFormat);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    config.setIniCodec(codec);

    config.beginGroup("Botpack.ChallengeBotInfo");

    for(int i = startId; i < endId; i++){
//        config.setValue("BotFaces[" + QString::number(i) + "]", "");
//        config.setValue("BotNames[" + QString::number(i) + "]", QString("WarCow") + ((i - startId) != 0 ? " " + QString::number(i) : "" ));
//        config.setValue("BotTeams[" + QString::number(i) + "]", 0);
//        config.setValue("BotClasses[" + QString::number(i) + "]", "MultiMesh.TCowBot");
//        config.setValue("BotSkins[" + QString::number(i) + "]", "TCowMeshSkins.AtomicCow");
//        config.setValue("VoiceType[" + QString::number(i) + "]", "MultiMesh.CowVoice");
//        config.setValue("BotSkills[" + QString::number(i) + "]", "2.000000");
//        config.setValue("BotAccuracy[" + QString::number(i) + "]", "-0.500000");
//        config.setValue("CombatStyle[" + QString::number(i) + "]", "1.000000");
//        config.setValue("Alertness[" + QString::number(i) + "]", "1.000000");
//        config.setValue("Camping[" + QString::number(i) + "]", "0.250000");
//        config.setValue("StrafingAbility[" + QString::number(i) + "]", "0.000000");
//        config.setValue("FavoriteWeapon[" + QString::number(i) + "]", "BotPack.UT_FlakCannon");
//        config.setValue("BotJumpy[" + QString::number(i) + "]", 0);

        config.setValue("BotFaces[" + QString::number(i) + "]", "");
        config.setValue("BotNames[" + QString::number(i) + "]", QString("Devastator") + ((i - startId) != 0 ? " " + QString::number(i) : "" ));
        config.setValue("BotTeams[" + QString::number(i) + "]", 0);
        config.setValue("BotClasses[" + QString::number(i) + "]", "MultiMesh.TSkaarjBot");
        config.setValue("BotSkins[" + QString::number(i) + "]", "tskmskins.Warr");
        config.setValue("VoiceType[" + QString::number(i) + "]", "MultiMesh.SkaarjVoice");
        config.setValue("BotSkills[" + QString::number(i) + "]", "3.000000");
        config.setValue("BotAccuracy[" + QString::number(i) + "]", "-0.250000");
        config.setValue("CombatStyle[" + QString::number(i) + "]", "0.500000");
        config.setValue("Alertness[" + QString::number(i) + "]", "0.500000");
        config.setValue("Camping[" + QString::number(i) + "]", "0.500000");
        config.setValue("StrafingAbility[" + QString::number(i) + "]", "0.250000");
        config.setValue("FavoriteWeapon[" + QString::number(i) + "]", "");
        config.setValue("BotJumpy[" + QString::number(i) + "]", 0);

    }

    config.endGroup();

    config.sync();

    QFile file("User.ini");

    file.open(QIODevice::ReadWrite | QIODevice::Text);

    QString data = file.readAll();

    data.replace("%5B","[");
    data.replace("%5D","]");

    file.resize(0);
    file.write(data.toLocal8Bit().data(), data.toLocal8Bit().length());

    file.close();
    
    return a.exec();
}
