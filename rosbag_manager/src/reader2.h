#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>

class BagReader2{
    public:
        BagReader2();
        ~BagReader2();

    private:
        rosbag::Bag bag;
};
