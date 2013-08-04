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

    Qt::ItemFlags flags(const QModelIndex &index) const;

    virtual int loadEntities() = 0;
    virtual int saveEntities() = 0;

//    virtual int add(const UTEntity& entity) = 0;
//    virtual int remove(const UTEntity& entity) = 0;

    UTEntity *getEntityById(EntityID id);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

protected:
    void clearEntityList();

    QHash<EntityID, UTEntity *> m_entityMap;
    
public slots:

private:
    
};

#endif // UTENTITYMODEL_H
