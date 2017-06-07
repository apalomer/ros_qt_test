#include "displayTextWidgetROS.h"

rosspinThread::rosspinThread(QObject* parent): QObject(parent)
{
    name_ = ros::this_node::getName();
}

rosspinThread::rosspinThread(ros::NodeHandle nh, QObject* parent):
    nh_(nh), QObject(parent)
{
    name_ = ros::this_node::getName();
    sub_ = nh_.subscribe("chatter",1,&rosspinThread::callback,this);
}

void rosspinThread::setNodeHandle(ros::NodeHandle nh){
    nh_ = nh;
    sub_ = nh_.subscribe("chatter",1,&rosspinThread::callback,this);
}

void rosspinThread::start(){
    run();
}
void rosspinThread::run(){
    ros::spin();
}
void rosspinThread::callback(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("%s: got a message: %s",name_.c_str(),msg->data.c_str());
    emit newMessage(msg->data.c_str());
}

displayTextWidgetROS::displayTextWidgetROS(ros::NodeHandle nh):
    nh_(nh)
{
    init();
    ROS_INFO("%s: initialized!",name_.c_str());
}

displayTextWidgetROS::displayTextWidgetROS()
{
    nh_ = ros::NodeHandle();
    init();
    ROS_INFO("%s: initialized!",name_.c_str());
}

void displayTextWidgetROS::init(){
    name_ = ros::this_node::getName();
    QThread* th = new QThread;
    rosSpin_ = new rosspinThread(nh_,this);
    rosSpin_->moveToThread(th);
    connect(th, SIGNAL(started()), rosSpin_, SLOT(start()));
    connect(rosSpin_, SIGNAL(newMessage(std::string)),this,SLOT(setText(std::string)));
    th->start();
}
