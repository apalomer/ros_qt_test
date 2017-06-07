
#include <ros/ros.h>
#include <QApplication>
#include "getTextWidgetROS.h"

int main(int argc, char** argv){

    // Initialize QT
    QApplication app (argc, argv);

    // Initialize ROS
    ros::init(argc,argv,"qt_test_get");
    ros::NodeHandle nh;

    getTextWidgetROS gtwr(nh);
    gtwr.show();
    return app.exec();
}
