#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

class Writer{

    public:
        Writer();
        ~Writer();


    private:
        rosbag::Bag bag;

};
