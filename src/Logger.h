#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QString>
#include <QMessageLogContext>

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger(QObject *parent = 0);

    static Logger *instance();
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

signals:
    void message(const QString& msg);
};

#endif // LOGGER_H
