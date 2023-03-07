#!/usr/bin/env python

import rospy
import sys
import numpy as np



from ackermann_msgs.msg import AckermannDriveStamped
from std_msgs.msg import Bool
from std_msgs.msg import Float32
from geometry_msgs.msg import TwistWithCovarianceStamped







class cmd_for_brake_n_pot:
    
  def __init__(self):
      
    self.brake_pub = rospy.Publisher('brake_cmd', Bool,queue_size=1)
    self.pot_pub = rospy.Publisher('pot_cmd',Bool,queue_size=1)
    
    self.ackermann_sub= rospy.Subscriber('/ackermann_cmd', AckermannDriveStamped , self.callback5)
   
   
    self.bool4=Bool()
    self.bool5=Bool()
    self.damn()
    
  
    
        


            
    

  def callback5(self,data):

    
    
                   
    if (data.drive.speed<-0.05):
        self.bool4=False
        self.bool5=True
        
    elif (data.drive.speed>0.05):
        self.bool4=True
        self.bool5=False
    else:
        self.bool4=False
        self.bool5=False
    
  def damn(self):
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        self.pot_pub.publish(self.bool4)
        self.brake_pub.publish(self.bool5)
        rate.sleep()
    

    
      
    

    
    
    
  


def main():
    
    rospy.init_node('brake_and_pot_cmd')
    try:
        cmd_for=cmd_for_brake_n_pot()
    except rospy.ROSInterruptException:
        pass
  
  

if __name__ == '__main__':
    
    main()
    
        



