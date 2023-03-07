#!/usr/bin/env python

from turtle import speed
import rospy
import sys
import numpy as np



from ackermann_msgs.msg import AckermannDriveStamped
from std_msgs.msg import Bool
from geometry_msgs.msg import TwistWithCovarianceStamped


global redcheck









def callback4(data):
    global vel
    if np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))>0.3 :
        vel=np.sqrt(np.square(data.twist.twist.linear.x)+np.square(data.twist.twist.linear.y))
    else:
        vel=0.0


    


        


def callback5(data):
    global speed
    speed= data.drive.speed

    

def callback3(data):
    global brakestatus
    brakestatus = data.data


def callback2(data):
    global redcheck
    redcheck = data.data
    
    
    
def callback1(data):
    global echeck
    echeck = data.data
    

    
      
    

    
    
    
  
rate=rospy.Rate(100)


while not rospy.is_shutdown():
    rospy.init_node('brake_and_pot_cmd')
    rospy.Subscriber("/red_only_check",Bool,callback1)
    rospy.Subscriber("/e_stop_range",Bool,callback2)
    rospy.Subscriber("/brake_status",Bool,callback3)
    rospy.Subscriber("/ublox_gps/fix_velocity",TwistWithCovarianceStamped,callback4)
    rospy.Subscriber('/ackermann_cmd', AckermannDriveStamped ,callback5)
    brakepub = rospy.Publisher('brake_cmd', Bool,queue_size=1)
    potpub = rospy.Publisher('pot_cmd',Bool,queue_size=1)
    rospy.sleep()
    if (redcheck or echeck):
        potpub.publish(False)
        brakepub.publish(True)
        print("check")
    elif(speed == 0):
        potpub.publish(False)
        if (brakestatus):
            brakepub.publish(False)
        else:
            brakepub.publish(True)
        print(brakestatus)       
    elif (speed<0):
        potpub.publish(False)
        brakepub.publish(True)
        
    elif (speed>0.2 and speed>vel):
        potpub.publish(True)
        brakepub.publish(False)
    else:
        potpub.publish(False)
        brakepub.publish(False)
    rate.sleep()

    
    
  
  

    
        



