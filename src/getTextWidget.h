#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <iostream>

#include <QMainWindow>

namespace Ui {
class getTextWidget;
}

class getTextWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit getTextWidget(QWidget *parent = 0);
    ~getTextWidget();

public slots:
    void displayString(std::string s);

signals:
    void newString(std::string s);

private slots:
    void on_pushButton_clicked();

private:
    Ui::getTextWidget *ui;
};

#endif // CUSTOMWIDGET_H
