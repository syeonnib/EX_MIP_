#!/usr/bin/env python
import rospy,sys,numpy
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Header
from std_msgs.msg import String
from std_msgs.msg import Bool


pub = rospy.Publisher('e_stop_range', Bool,queue_size=1)

class e_stop_checker:
  def __init__(self):
    self.laser_sub= rospy.Subscriber('/scan4distance', LaserScan , self.callback)
    
  def callback(self,data):
    
    
    if any(3>num for num in data.ranges):
      pub.publish(Bool(True))
      
      
    else:
      pub.publish(Bool(False))

    
      
    

    
    
    
  


def main(args):
    while not rospy.is_shutdown():
        rospy.init_node('e_stop_range_check')
        ic= e_stop_checker()
        
        rospy.spin()
  
  

if __name__ == '__main__':
    try :
        main(sys.argv)
    except rospy.ROSInterruptException:
        print("Shutting down")
    
        




