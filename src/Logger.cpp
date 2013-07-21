#include "Logger.h"
#include <stdio.h>

Logger::Logger(QObject *parent) :
    QObject(parent)
{
}

Logger *Logger::instance()
{
    static Logger inst;
    return &inst;
}

void Logger::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Logger *logger = Logger::instance();

    switch (type) {
    case QtDebugMsg:
        emit logger->message(QString("Debug: %1").arg(msg));
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", msg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        emit logger->message(QString("Warning: %1").arg(msg));
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", msg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        emit logger->message(QString("Critical: %1").arg(msg));
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", msg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        emit logger->message(QString("Fatal: %1").arg(msg));
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", msg.constData(), context.file, context.line, context.function);
        abort();
    }
}
