#! /usr/bin/env python
import rospy
from rosgraph_msgs.msg import Clock

class BagClockCounter:
    def __init__(self, hz = 100):
        self.count = 0
        self.fase = 0
        self.switch_flag = False
    def __del__(self):
        print("!!!!!!!!!!!!!!1")
    def counterCallback(self, msg):
        self.count += 1
    def need_switch_fase(self):
        #print("fase:{}".format(self.fase))
        #print("count:{}".format(self.count))
        if(self.fase == self.count):
            self.switch_flag = False
            return False
        else:
            self.fase = self.count
            self.switch_flag = True

            return True







