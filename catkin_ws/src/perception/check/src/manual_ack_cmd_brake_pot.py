#!/usr/bin/env python

import rospy
import sys
import numpy as np



from ackermann_msgs.msg import AckermannDriveStamped
from std_msgs.msg import Bool
from geometry_msgs.msg import TwistWithCovarianceStamped
echeck = []
redcheck=[]
brakestatus=[]
vel=0.0





class cmd_for_brake_n_pot:
  def __init__(self):
      
    
    self.red_sub = rospy.Subscriber("/red_only_check",Bool,self.callback1)
    self.estop_sub = rospy.Subscriber("/e_stop_range",Bool,self.callback2)
    self.brake_sub = rospy.Subscriber("/brake_status",Bool,self.callback3)
    self.gps_sub = rospy.Subscriber("/ublox_gps/fix_velocity",TwistWithCovarianceStamped,self.callback4)
    self.ackermann_sub= rospy.Subscriber('/ackermann_cmd', AckermannDriveStamped , self.callback5)

  def callback4(self,data):
    if np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))>0.3 :
        vel=np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))
    else:
        vel=0.0
    
    
        


            
    

  def callback5(self,data):

    brakepub = rospy.Publisher('brake_cmd', Bool,queue_size=1)
    potpub = rospy.Publisher('pot_cmd',Bool,queue_size=1)
    if (redcheck or echeck):
        potpub.publish(False)
        brakepub.publish(True)
        print("check")
    elif(data.drive.speed == 0):
        potpub.publish(False)
        if (brakestatus):
            brakepub.publish(False)
        else:
            brakepub.publish(True)       
    elif (data.drive.speed<0):
        potpub.publish(False)
        brakepub.publish(True)
        
    elif (data.drive.speed>0.2 and data.drive.speed>vel):
        potpub.publish(True)
        brakepub.publish(False)
    else:
        potpub.publish(False)
        brakepub.publish(False)
    
  def callback3(self,data):
    brakestatus = data
    

  def callback2(self,data):

    redcheck = data
       
        
      
  def callback1(self,data):
    echeck = data 
    

    
      
    

    
    
    
  


def main(args):
    while not rospy.is_shutdown():
        rospy.init_node('brake_and_pot_cmd')
        ic= cmd_for_brake_n_pot()
        rospy.spin()
  
  

if __name__ == '__main__':
    try :
        main(sys.argv)
    except rospy.ROSInterruptException:
        print("Shutting down")
    
        



