#ifndef UTENTITY_H
#define UTENTITY_H

#include <QObject>

#include "Enumerations.h"

class UTProjectSettings;

class UTEntity : public QObject
{
    Q_OBJECT
public:
    explicit UTEntity(QObject *parent = 0);
    UTEntity(const UTEntity& entity);
    explicit UTEntity(const UTProjectSettings *settings,
                      EntityID id,
                      const QString& name,
                      const QString& pathToImage = QString(),
                      QObject *parent = 0);
    
    EntityID id() const { return m_id; }

    QString name() const { return m_name; }

    QImage getImage() const;

    QString pathToImage() const { return m_pathToImage; }

    const UTProjectSettings *settings() const { return m_settings; }

signals:
    
public slots:

protected:
    const UTProjectSettings *m_settings;

private:
    EntityID m_id;
    QString  m_name;
    QString  m_pathToImage;
};

Q_DECLARE_METATYPE(UTEntity)

#endif // UTENTITY_H
