#include "q2R_fun/q2R.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char* argv[])
{

    ros::init(argc, argv, "foo_node");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(1);
    int count = 0;
    while (ros::ok()) {

        double q[4];
        q[0] = 1;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        double R[9];
        for (int i = 0; i < 9; i++) {
            R[i] = 0;
        }

		q2R(q,R);

		std::cout<<"R="<<std::endl;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				std::cout<<R[i+3*j]<<" ";
			}
			std::cout<<std::endl;
		}
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}