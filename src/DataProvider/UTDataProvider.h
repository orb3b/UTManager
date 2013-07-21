#ifndef UTDATAPROVIDER_H
#define UTDATAPROVIDER_H

#include <QObject>

#include "Enumerations.h"

class UTPlayerModel;

class UTDataProvider : public QObject
{
    Q_OBJECT
public:
    explicit UTDataProvider(QObject *parent = 0);
    ~UTDataProvider();

    int openProject(const QString& path);

    UTPlayerModel *playerModel() const { return m_playerModel; }
    
signals:
    
public slots:

private:
    UTPlayerModel *m_playerModel;
    
};

#endif // UTDATAPROVIDER_H
