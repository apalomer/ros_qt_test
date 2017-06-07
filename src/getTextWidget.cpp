#include "getTextWidget.h"
#include "ui_getTextWidget.h"

getTextWidget::getTextWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::getTextWidget)
{
    ui->setupUi(this);
    connect(this,SIGNAL(newString(std::string)),this,SLOT(displayString(std::string)));
}

getTextWidget::~getTextWidget()
{
    delete ui;
}

void getTextWidget::on_pushButton_clicked()
{
    emit newString(ui->lineEdit->text().toUtf8().constData());
}

void getTextWidget::displayString(std::string s){
    std::cout<<s<<std::endl;
}
