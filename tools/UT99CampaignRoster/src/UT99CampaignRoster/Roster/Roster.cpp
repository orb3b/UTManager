#include "Roster.h"

#include <QMetaType>

Roster::Roster(QObject *parent) :
    RosterObject(parent),
    m_pawnCollection(new PawnCollection()),
    m_teamCollection(new TeamCollection()),
    m_materialCollection(new MaterialCollection()),
    m_provider(nullptr)
{
    registerMetatypes();
}

Roster::~Roster()
{
    if (!m_pawnCollection.isNull())
        delete m_pawnCollection;

    if (!m_teamCollection.isNull())
        delete m_teamCollection;

    if (!m_materialCollection.isNull())
        delete m_materialCollection;
}

bool Roster::openProject(const QString &path)
{
    // TODO: Remove me!
    if (!pawnCollection()->open(path))
        return postError(QString("Can't open pawn collection: %1").arg(pawnCollection()->lastError()));

    return postSuccess(QString("Roster project %1 have been opened successfully").arg(path));
}

PawnCollection *Roster::pawnCollection() const
{
    return m_pawnCollection.data();
}

TeamCollection *Roster::teamCollection() const
{
    return m_teamCollection.data();
}

MaterialCollection *Roster::materialCollection() const
{
    return m_materialCollection.data();
}

void Roster::registerMetatypes()
{
    static bool registered = false;
    if (!registered) {
        qRegisterMetaType<Pawn>();
    }
}
