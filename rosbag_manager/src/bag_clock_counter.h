#include "ros/ros.h"
#include "rosgraph_msgs/Clock.h"
#include <iostream>

class BagClockCounter{
    public:
        BagClockCounter(int hz_ = 100);
        ~BagClockCounter();

        void counterCallback(const rosgraph_msgs::Clock& msg);

        ros::Subscriber sub;
        bool need_switch_fase();
        int fase;


    private:
        int count ;
        double duration; //sec
        double hz;
        ros::Time t;


};
