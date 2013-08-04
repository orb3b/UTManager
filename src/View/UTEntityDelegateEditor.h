#ifndef UTENTITYDELEGATEEDITOR_H
#define UTENTITYDELEGATEEDITOR_H

#include <QWidget>

class UTEntityDelegateEditor : public QWidget
{
    Q_OBJECT
public:
    explicit UTEntityDelegateEditor(QWidget *parent = 0);
    
signals:
    void commitEntity();
    
public slots:
    
};

#endif // UTENTITYDELEGATEEDITOR_H
