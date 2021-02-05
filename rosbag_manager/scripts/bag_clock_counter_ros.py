import rospy
from rosgraph_msgs.msg import Clock
from bag_clock_counter import BagClockCounter
class BagClockCounter_ros(BagClockCounter,object):                                                  
    def __init__(self):
        super(BagClockCounter_ros, self).__init__()
        self.sub =rospy.Subscriber('/clock',Clock,self.counterCallback)

