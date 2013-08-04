#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QWidget>
#include <View/Players/PlayerDelegate.h>

namespace Ui {
class ProjectView;
}

class PlayerDelegate;
class UTDataProvider;

class ProjectView : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProjectView(UTDataProvider* provider, QWidget *parent = 0);
    ~ProjectView();
    
private:
    Ui::ProjectView *ui;

    UTDataProvider* m_provider;

    PlayerDelegate  m_playerDelegate;
};

#endif // PROJECTVIEW_H
