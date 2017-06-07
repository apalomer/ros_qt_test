
#include <QApplication>
#include "getTextWidget.h"
#include "displayTextWidget.h"

int main(int argc, char** argv){

    QApplication app(argc,argv);
    getTextWidget* gt = new getTextWidget();
    gt->show();
    displayTextWidget* dt = new displayTextWidget();
    dt->show();
    QObject::connect(gt,SIGNAL(newString(std::string)),dt,SLOT(setText(std::string)));
    return app.exec();
}
