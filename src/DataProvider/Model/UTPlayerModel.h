#ifndef UTPLAYERMODEL_H
#define UTPLAYERMODEL_H

#include "UTEntityModel.h"

class UTPlayerModel : public UTEntityModel
{
    Q_OBJECT
public:
    explicit UTPlayerModel(QObject *parent = 0);
    ~UTPlayerModel();

    int loadEntities();
    int saveEntities();

signals:

protected:

public slots:

};

#endif // UTPLAYERMODEL_H
