#include "Roster.h"

#include "PawnCollection.h"
#include "TeamCollection.h"

Roster::Roster(QObject *parent) :
    RosterObject(parent),
    m_pawnCollection(nullptr),
    m_teamCollection(nullptr)
{
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

void Roster::onMemberDestroyed(QObject *obj)
{
    if (obj == m_pawnCollection)
        m_pawnCollection = nullptr;

    if (obj == m_teamCollection)
        m_teamCollection = nullptr;
}
