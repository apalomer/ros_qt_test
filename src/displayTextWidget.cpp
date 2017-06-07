#include "displayTextWidget.h"
#include "ui_displayTextWidget.h"

displayTextWidget::displayTextWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::displayTextWidget)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

displayTextWidget::~displayTextWidget()
{
    delete ui;
}

void displayTextWidget::setText(std::string s){
    ui->textEdit->setText(QString::fromUtf8(s.c_str()));
}
