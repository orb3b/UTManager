#ifndef MATERIAL_H
#define MATERIAL_H

#include "RosterObject.h"

class Material : public RosterObject
{
    Q_OBJECT
public:
    explicit Material(QObject *parent = 0);

    QString name() const;
    void setName(const QString &newName);

signals:

public slots:

protected:
    QString m_name;

};

#endif // MATERIAL_H
