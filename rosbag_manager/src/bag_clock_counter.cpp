#include "bag_clock_counter.h"

BagClockCounter::BagClockCounter(int hz_):hz(hz_){

    t = ros::Time::now();
    count = 0;
    fase = 0;
    duration = 0.0;
}
BagClockCounter::~BagClockCounter(){


}
void BagClockCounter::counterCallback(const rosgraph_msgs::Clock& msg){
    count++;
    std::cout << "*****time*****: " <<  msg.clock << std::endl;
}
bool BagClockCounter::need_switch_fase(){
    if(fase == count ){
        return false;
    }
    else{
        fase = count;
        std::cout <<"fase: "<< fase << std::endl;
        return true;
    }
}
