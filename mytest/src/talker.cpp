#include "ros/ros.h"
#include "mytest/Num.h"
#include "mytest/Num_2.h"
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::NodeHandle n2;
  ros::Publisher pub = n.advertise<mytest::Num>("message", 1000);
  ros::Publisher pub2 = n2.advertise<mytest::Num_2>("message2", 1000);
  ros::Rate loop_rate(10);
  double param_test = 0.0;


  while (ros::ok())
  {
    mytest::Num msg;
    mytest::Num_2 msg_2;
    msg.A = 66;
    msg.B = 666;
    msg_2.C = 1;
    msg_2.D = 0;
    ros::param::get("~param_test",param_test);
    //cout<<param_test<<endl;
    ROS_INFO("param_test:%.3f",param_test);
    //pub.publish(msg);
    //pub2.publish(msg_2);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
