#include "LogView.h"
#include "Logger.h"
#include "ui_LogView.h"

LogView::LogView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogView)
{
    ui->setupUi(this);

    connect(Logger::instance(), SIGNAL(message(QString)), ui->teLog, SLOT(append(QString)));
}

LogView::~LogView()
{
    delete ui;
}

void LogView::on_btnClear_clicked()
{
    ui->teLog->clear();
}
