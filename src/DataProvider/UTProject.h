#ifndef UTPROJECT_H
#define UTPROJECT_H

#include <QObject>

class UTProjectSettings
{
public:
};

class UTProject : public QObject
{
    Q_OBJECT
public:
    explicit UTProject(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // UTPROJECT_H
