#include "reader.h"

#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"


BagReader::BagReader(){



    

bag.open("/home/taisuke/catkin_ws/cam_bag/1m/2020-09-28-13-32-02.bag", rosbag::bagmode::Read);

std::vector<std::string> topics;
topics.push_back(std::string("/usb_cam/image_raw"));
topics.push_back(std::string("/usb_cam/camera_info"));

rosbag::View view(bag, rosbag::TopicQuery(topics));

foreach(rosbag::MessageInstance const m, view)
{

    boost::posix_time::ptime my_posix_time = m.getTime().toBoost();
    boost::date_time::c_local_adjustor<boost::posix_time::ptime> adj1;
    boost::posix_time::ptime my_local_posix_time = adj1.utc_to_local(my_posix_time);
    std::string iso_time_str = boost::posix_time::to_iso_extended_string(my_local_posix_time);

    /*
    std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
    if (s != NULL)
        std::cout << s->data << std::endl;
    */
    sensor_msgs::CameraInfo::ConstPtr s = m.instantiate<sensor_msgs::CameraInfo>();
    if (s != NULL)
        std::cout << *s << std::endl;

    sensor_msgs::Image::ConstPtr i = m.instantiate<sensor_msgs::Image>();
    if (i != NULL)
        std::cout << i << std::endl;
}
}
BagReader::~BagReader(){
    bag.close();
}


