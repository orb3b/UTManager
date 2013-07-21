#ifndef UTENTITYMODEL_H
#define UTENTITYMODEL_H

#include <QAbstractListModel>
#include <QHash>

#include "Enumerations.h"
#include "../Entity/UTEntity.h"

class UTEntityModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit UTEntityModel(QObject *parent = 0);
    ~UTEntityModel();

    virtual int loadEntities() = 0;
    virtual int saveEntities() = 0;

//    virtual int add(const UTEntity& entity) = 0;
//    virtual int remove(const UTEntity& entity) = 0;

    UTEntity *getEntityById(EntityID id);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

protected:
    void clearEntityList();

    QHash<EntityID, UTEntity *> m_entityMap;
    
public slots:

private:
    
};

#endif // UTENTITYMODEL_H
