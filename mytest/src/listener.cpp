
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "mytest/Num.h"
#include "mytest/Num_2.h"

void chatterCallback(const mytest::Num::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->A);
  //ROS_INFO("I heard: [%d]", msg_2->d);
}

void chatterCallback2(const mytest::Num_2::ConstPtr& msg2)
{
  ROS_INFO("I heard: [%d]", msg2->C);
  //ROS_INFO("I heard: [%d]", msg_2->d);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("message", 1000, chatterCallback);
  ros::Subscriber sub2 = n.subscribe("message2", 1000, chatterCallback2);

  ros::spin();

  return 0;
}
