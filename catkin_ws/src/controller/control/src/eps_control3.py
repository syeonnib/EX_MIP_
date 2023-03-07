#!/usr/bin/env python
import rospy,sys
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Header
from std_msgs.msg import String
from std_msgs.msg import Bool
from can_msgs.msg import Frame
from ackermann_msgs.msg import AckermannDriveStamped
from ackermann_msgs.msg import AckermannDrive

print('start')
def convert_to_shaft_angle(steering_angle):
  print(steering_angle)
  k=0.8
  shaft_angle=k*steering_angle
  print(shaft_angle)
  return shaft_angle


pub= rospy.Publisher('/sent_messages',Frame,queue_size=1)

pcid=0x469

class eps_roller:
  
  
  def __init__(self):
    self.cmd_vel_sub= rospy.Subscriber('ackermann_cmd', AckermannDriveStamped , self.callback)
    
    
  def callback(self,data):
    
    shaft=int(convert_to_shaft_angle(data.drive.steering_angle)*57.2958)
    rot_speed=100 #speed data range 20-250, in real term 120-1500rpm
    cmd_data=[0]*8

    cmd_data[0]=0x20#means angle control mode
    cmd_data[1]=0
    cmd_data[2]=0
    
    if shaft==0:
      cmd_data[3]=4
      cmd_data[4]=0
    
    if shaft>0:
      cmd_data[3]=4
      cmd_data[4]=shaft
    
    if shaft<0:
      cmd_data[3]=3
      cmd_data[4]=256+shaft#this only works for certain ranges
    
    cmd_data[5]=0x00#0x00 is for no angle allignment 0x55 for angle allignment
    cmd_data[6]=rot_speed
    cmd_data[7]=cmd_data[0]^cmd_data[1]^cmd_data[2]^cmd_data[3]^cmd_data[4]^cmd_data[5]^cmd_data[6]
    can_msgs_to_send=Frame(header=data.header,id=pcid, dlc=8, data=cmd_data)
    pub.publish(can_msgs_to_send)
    print(can_msgs_to_send)
    
    
    

    
    
    
  


def main(args):
    while not rospy.is_shutdown():
        rospy.init_node('acc_cmd_to_can_cmd')
        rate=rospy.Rate(20)

        er = eps_roller()
        rate.sleep()
        rospy.spin()
  
  

if __name__ == '__main__':
    try :
        main(sys.argv)
    except rospy.ROSInterruptException:
        print("Shutting down")
    
        




