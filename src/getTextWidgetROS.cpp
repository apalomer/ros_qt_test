#include "getTextWidgetROS.h"

getTextWidgetROS::getTextWidgetROS(ros::NodeHandle nh):
    nh_(nh)
{
    initPublisher();
}

getTextWidgetROS::getTextWidgetROS()
{
    nh_ = ros::NodeHandle();
    initPublisher();
}

void getTextWidgetROS::initPublisher(){
    name_ = ros::this_node::getName();
    pub_ = nh_.advertise<std_msgs::String>("chatter",1000);
    connect(this,SIGNAL(newString(std::string)),this,SLOT(publishString(std::string)));
}

void getTextWidgetROS::publishString(std::string s){
    ROS_INFO("%s: publishin message: %s",name_.c_str(),s.c_str());
    std_msgs::String msg;
    msg.data = s;
    pub_.publish(msg);
}
