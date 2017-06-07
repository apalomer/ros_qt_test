#ifndef CUSTOMWIDGETROS_H
#define CUSTOMWIDGETROS_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/subscriber.h>
#include <QThread>

#include "displayTextWidget.h"

class displayTextWidgetROS;

class rosspinThread : public QObject
{
    Q_OBJECT
public:
    rosspinThread(ros::NodeHandle nh, QObject* parent = 0);
    rosspinThread(QObject* parent = 0);

    void setNodeHandle(ros::NodeHandle nh);

    void callback(const std_msgs::String::ConstPtr& msg);

public slots:
    void start();

signals:
    void newMessage(std::string s);
private:
    void run();
    ros::Subscriber sub_;
    ros::NodeHandle nh_;
    std::string name_;
};

class displayTextWidgetROS : public displayTextWidget
{
    Q_OBJECT
public:
    displayTextWidgetROS(ros::NodeHandle nh);
    displayTextWidgetROS();

    void init();

private:
    ros::NodeHandle nh_;
    std::string name_;
    rosspinThread* rosSpin_;
};

#endif // CUSTOMWIDGETROS_H
