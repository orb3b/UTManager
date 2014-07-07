#ifndef ROSTERCOLLECTION_H
#define ROSTERCOLLECTION_H

#include "RosterObject.h"

#include <QList>

class RosterCollection : public RosterObject
{
    Q_OBJECT
public:
    explicit RosterCollection(QObject *parent = 0);
    ~RosterCollection();

    void clear();
    int size() const;

public slots:

signals:

protected:
    bool addObjectPrivate(OWNERSHIP RosterObject *object);

protected slots:
    void onObjectDestroyed(QObject *obj);

protected:
    QList<RosterObject *> m_objectList;

private:

};

#endif // ROSTERCOLLECTION_H
