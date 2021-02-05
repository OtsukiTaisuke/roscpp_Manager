#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>

#include <boost/foreach.hpp>

#include "rosbag/player.h"
#include "rosbag/message_instance.h"
#include "rosbag/view.h"
#define foreach BOOST_FOREACH
class BagReader{
    public:
        BagReader();
        ~BagReader();
    private:
        rosbag::Bag bag;

};
