/**
  * Read data from the point serial commmunicate port
  * @file UAV core logic node
  * @author DreamTale
  * @date Jul 30, 2016
  */

#include "commCtrl.h"
#include "../include/stdHeaders.h"
#include "ros/ros.h"

//==============================================

// the content of the data packet

// +------------+----------+----------------+------------+
// | packetHead | itemName | objectCategory | packetTail |
// +------------+----------+----------------+------------+

char dev[13] = "/dev/ttyUSB0";
std_msgs::String pubData;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "serialRead");
    ros::NodeHandle nh;

    ros::Publisher publisher;
    publisher = nh.advertise<std_msgs::String>("uavGroundCar", 1000);

    string data;

    ros::Rate loopRate(100);

    while(nh.ok())
    {
        ros::spinOnce();
        loopRate.sleep();

        int ret = commRead(data, dev);
        if(ret == -1)
        {
            cout << "Assert the serial port failed!" << endl;
            break;
        }
        pubData.data = data;
        ROS_INFO("I've read the data: [%s]\n", data.c_str());
        publisher.publish(pubData);
    }

    return 0;
}
