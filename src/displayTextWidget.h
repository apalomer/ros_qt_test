#ifndef DISPLAYTEXTWIDGET_H
#define DISPLAYTEXTWIDGET_H

#include <QMainWindow>

namespace Ui {
class displayTextWidget;
}

class displayTextWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayTextWidget(QWidget *parent = 0);
    ~displayTextWidget();

public slots:
    void setText(std::string s);

private:
    Ui::displayTextWidget *ui;
};

#endif // DISPLAYTEXTWIDGET_H
