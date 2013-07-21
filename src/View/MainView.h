#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QtWidgets>
#include "LogView.h"
#include "DataProvider/UTDataProvider.h"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

protected:
    void closeEvent(QCloseEvent *event);
// Menu bar logic fields
private slots:
    void onActionOpenProject(bool);
    void onActionShowSettings();
    void onActionShowLog();

private:
    //QAction m_actionShowProjectSettings;

// Common variables
private:
    Ui::MainView *ui;
    LogView m_logView;

    UTDataProvider m_provider;
};

#endif // MAINVIEW_H
