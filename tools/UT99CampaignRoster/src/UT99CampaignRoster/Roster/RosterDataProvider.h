#ifndef ROSTERDATAPROVIDER_H
#define ROSTERDATAPROVIDER_H

#include "RosterObject.h"

class MaterialCollection;

class ROSTER_EXPORT RosterDataProvider : public RosterObject
{
    Q_OBJECT
public:
    explicit RosterDataProvider(QObject *parent = 0);

    virtual bool isConsistent() const OVERWRITE;

    QString path() const;
    void setPath(const QString &newPath);

    // Binds material collection to this data provider
    void setMaterialCollection(MaterialCollection *collection);

    virtual bool load();

signals:

public slots:

private:
    QString m_path;

    QPointer<MaterialCollection> m_materialCollection;

};

#endif // ROSTERDATAPROVIDER_H
