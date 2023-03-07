#!/usr/bin/env python
import rospy
from std_msgs.msg import Header
from std_msgs.msg import String
from std_msgs.msg import Bool





    
      
    

    
    
    
  


def main():
    pub1 = rospy.Publisher('e_stop_range', Bool,queue_size=1)
    pub2 = rospy.Publisher('red_only_check', Bool,queue_size=1)
    rospy.init_node('fake_check')
    rate=rospy.Rate(10)
    while not rospy.is_shutdown():
        
        pub1.publish(Bool(False))
        pub2.publish(Bool(False))
        
        rate.sleep()
  
  

if __name__ == '__main__':
    try :
        main()
    except rospy.ROSInterruptException:
        print("Shutting down")
    
        




