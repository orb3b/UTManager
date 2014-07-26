#ifndef PAWNSKIN_H
#define PAWNSKIN_H

#include "Material.h"

class FaceCollection;

class PawnSkin : public Material
{
    Q_OBJECT
public:
    explicit PawnSkin(QObject *parent = 0);
    ~PawnSkin();

    FaceCollection *faceCollection();

signals:

public slots:

private:
    void createFaceCollection();
    void deleteFaceCollection();

private slots:
    void onMemberDestroyed(QObject *obj);

private:
    FaceCollection *m_faceCollection;

};

#endif // PAWNSKIN_H
