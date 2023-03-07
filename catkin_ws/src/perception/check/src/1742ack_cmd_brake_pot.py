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
    self.red_sub = rospy.Subscriber("/red_only_check",Bool,self.callback1)
    self.estop_sub = rospy.Subscriber("/e_stop_range",Bool,self.callback2)
    self.brake_sub = rospy.Subscriber("/brake_status",Bool,self.callback3)
    self.gps_sub = rospy.Subscriber("/ublox_gps/fix_velocity",TwistWithCovarianceStamped,self.callback4)
    self.ackermann_sub= rospy.Subscriber('/ackermann_cmd', AckermannDriveStamped , self.callback5)
    self.bool1=Bool()
    self.bool2=Bool()
    self.bool3=Bool()
    self.vel=Float32()
    self.bool4=Bool()
    self.bool5=Bool()
    self.damn()
    
  def callback4(self,data):
    if np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))>0.3 :
        self.vel=np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))
    else:
        self.vel=0.0
    
    
        


            
    

  def callback5(self,data):

    
    if (self.bool1 or self.bool2):
        self.bool4=False
        self.bool5=True
        print("check")
    elif(data.drive.speed == 0):
        self.bool4=False
        self.bool5=True
               
    elif (data.drive.speed<0):
        self.bool4=False
        self.bool5=True
        
    elif (data.drive.speed>0.2 and data.drive.speed>self.vel):
        self.bool4=True
        self.bool5=False
    else:
        self.bool4=False
        self.bool5=False
    
  def callback3(self,data):
    
    self.bool3 = data.data
    

  def callback2(self,data):
    
    self.bool2 = data.data
       
        
      
  def callback1(self,data):
    
    self.bool1=data.data
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
    
        



