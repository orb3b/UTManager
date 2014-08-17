#ifndef MATERIAL_H
#define MATERIAL_H

#include "RosterObject.h"

class ROSTER_EXPORT Material : public RosterObject
{
    Q_OBJECT
public:
    explicit Material(QObject *parent = 0);

    QString name() const;
    void setName(const QString &newName);

    QString description() const;
    void setDescription(const QString &newDescription);

signals:

public slots:

protected:
    QString m_name;
    QString m_description;

};

#endif // MATERIAL_H
