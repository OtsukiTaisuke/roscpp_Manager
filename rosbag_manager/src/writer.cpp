
#include "writer.h"
Writer::Writer(){

    bag.open("test.bag", rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("foo");

    std_msgs::Int32 i;
    i.data = 42;

    bag.write("chatter", ros::Time::now(), str);
    bag.write("numbers", ros::Time::now(), i);

}
Writer::~Writer(){

    bag.close();
}

