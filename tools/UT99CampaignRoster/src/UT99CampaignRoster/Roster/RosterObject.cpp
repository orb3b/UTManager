#include "RosterObject.h"

RosterObject::RosterObject(QObject *parent) :
    QObject(parent),
    RosterComponent()
{
}

void RosterObject::notifyError(const QString & text) const
{
    emit error(text);
}

void RosterObject::notifyWarning(const QString &text) const
{
    emit warning(text);
}

void RosterObject::notifyMessage(const QString & text) const
{
    emit message(text);
}

void RosterObject::notifySuccess(const QString & text) const
{
    emit success(text);
}
