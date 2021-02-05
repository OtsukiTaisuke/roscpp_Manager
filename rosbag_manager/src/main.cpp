#include "ros/ros.h"
#include "std_msgs/String.h"


#include <iostream>

#include "reader.h"
#include "reader2.h"
#include "writer.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "rosbag_manager");
    ros::NodeHandle n;


    BagReader br;

    int ft = 1;
    while(ros::ok()){



        ros::spin();
    }
    return 0;
}
