#include "Roster.h"

#include <QMetaType>

#include "PawnCollection.h"
#include "TeamCollection.h"

Roster::Roster(QObject *parent) :
    RosterObject(parent),
    m_pawnCollection(nullptr),
    m_teamCollection(nullptr)
{
    registerMetatypes();
}

Roster::~Roster()
{
    if (m_pawnCollection) {
        disconnect(m_pawnCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));
        delete m_pawnCollection;
        m_pawnCollection = nullptr;
    }

    if (m_teamCollection) {
        disconnect(m_teamCollection, SIGNAL(destroyed(QObject*)), this, SLOT(onMemberDestroyed(QObject*)));
        delete m_teamCollection;
        m_teamCollection = nullptr;
    }
}

bool Roster::openProject(const QString &path)
{
    if (!pawnCollection()->open(path))
        return postError(QString("Can't open pawn collection: %1").arg(pawnCollection()->lastError()));

    return postSuccess(QString("Roster project %1 have been opened successfully").arg(path));
}

PawnCollection *Roster::pawnCollection()
{
    if (!m_pawnCollection)
        m_pawnCollection = new PawnCollection();

    return m_pawnCollection;
}

TeamCollection *Roster::teamCollection()
{
    if (!m_teamCollection)
        m_teamCollection = new TeamCollection();

    return m_teamCollection;
}

void Roster::registerMetatypes()
{
    static bool registered = false;
    if (!registered) {
        qRegisterMetaType<Pawn>();
    }
}

void Roster::onMemberDestroyed(QObject *obj)
{
    if (obj == m_pawnCollection)
        m_pawnCollection = nullptr;

    if (obj == m_teamCollection)
        m_teamCollection = nullptr;
}
