#include "reader2.h"

BagReader2::BagReader2(){

    bag.open("/home/taisuke/catkin_ws/cam_bag/1m/2020-09-28-13-32-02.bag");  // BagMode is Read by default

    for(rosbag::MessageInstance const m: rosbag::View(bag))
    {
      std_msgs::Int32::ConstPtr i = m.instantiate<std_msgs::Int32>();
      if (i != nullptr)
        std::cout << i->data << std::endl;
    }
}
BagReader2::~BagReader2(){
    bag.close();
}

