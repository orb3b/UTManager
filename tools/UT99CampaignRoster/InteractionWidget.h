#ifndef INTERACTIONWIDGET_H
#define INTERACTIONWIDGET_H

#include <QWidget>

namespace Ui {
class InteractionWidget;
}

class InteractionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InteractionWidget(QWidget *parent = 0);
    ~InteractionWidget();

signals:
    void addPawnToTeam();
    void removePawnFromTeam();

private:
    Ui::InteractionWidget *ui;
};

#endif // INTERACTIONWIDGET_H
