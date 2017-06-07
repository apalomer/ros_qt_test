
#include <ros/ros.h>
#include <QApplication>
#include "displayTextWidgetROS.h"

int main(int argc, char** argv){

    // Initialize QT
    QApplication app (argc, argv);

    // Initialize ROS
    ros::init(argc,argv,"ros_qt_test_display");
    ros::NodeHandle nh;

    displayTextWidgetROS dtwr(nh);
    dtwr.show();
    return app.exec();
}
