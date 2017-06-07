#ifndef CUSTOMWIDGETROS_H
#define CUSTOMWIDGETROS_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/publisher.h>

#include "getTextWidget.h"

class getTextWidgetROS : public getTextWidget
{
    Q_OBJECT
public:
    getTextWidgetROS(ros::NodeHandle nh);
    getTextWidgetROS();

    void initPublisher();

public slots:

    void publishString(std::string s);

private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    std::string name_;
};

#endif // CUSTOMWIDGETROS_H
