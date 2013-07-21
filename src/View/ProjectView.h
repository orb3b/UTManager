#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QWidget>

namespace Ui {
class ProjectView;
}

class ProjectView : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProjectView(QWidget *parent = 0);
    ~ProjectView();
    
private:
    Ui::ProjectView *ui;
};

#endif // PROJECTVIEW_H
