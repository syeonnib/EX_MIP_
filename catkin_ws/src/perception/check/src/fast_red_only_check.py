#!/usr/bin/env python
from email.mime import image
import rospy
import cv2
import sys
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from darknet_ros_msgs.msg import BoundingBoxes
from darknet_ros_msgs.msg import BoundingBox
from std_msgs.msg import Header
from std_msgs.msg import String
from std_msgs.msg import Bool




class image_checker:
  def __init__(self):
    
    self.bridge = CvBridge()
    
    self.box_sub= rospy.Subscriber('/darknet_ros/bounding_boxes', BoundingBoxes , self.callback2)
    self.image_sub = rospy.Subscriber("/darknet_ros/detection_image",Image,self.callback1)
    
    self.red_only_check_pub = rospy.Publisher('red_only_check', Bool,queue_size=1)

    self.im=Image()
    self.bool=Bool()
    self.damn()


  def callback2(self,data):
    
    cv_image = self.bridge.imgmsg_to_cv2(self.im, "bgr8")
    
    
    for boxindex,box in enumerate(data.bounding_boxes):
      if len(data.bounding_boxes)>6:#for small errors
        
        ymean=(box.ymin+box.ymax)/2
        xmean=(box.xmin+box.xmax)/2
        cropim=cv_image[ymean:box.ymax,box.xmin:box.xmax] #need adjust to follow circumstances and bbox y min
        colr = cv2.mean(cropim)
        #cv2.imshow("Image window", cropim)
        #cv2.waitKey(3)
        #for debug: check bbox containing main color only
        b=colr[0]/np.sum(colr)
        g=colr[1]/np.sum(colr)
        r=colr[2]/np.sum(colr)
        th=0.9 #th val for calibration
        if b>0.45*th:
            label='blue'
            color=(255,0,0)
        elif g > 0.5*th:
            label = 'green'
            color = (0, 255, 0)
        elif r > 0.37*th:
            label = 'red'
            color = (0, 0, 255)
        elif g>0.3*th and r>0.3*th:
            label = 'yellow'
            color = (0, 255, 255)
        else:
            label = 'what'
            color = (0,0,0)
        
        if label == 'blue':
          print('blue detected')
          self.bool=False
          break
        elif label == 'green':
          print('green detected')
          #pub.publish(False)
          break
        elif label == 'yellow':
          print('yellow detected')
          #pub.publish(False)
          break
        elif label == 'what':
          print('else detected')
          #pub.publish(False)
          break

        if boxindex == len(data.bounding_boxes)-1:
          print('only red detected')
          self.bool=True
        
          
      


        
        
      
      
    
      



        
        
      
  def callback1(self,data):
    try:
      
      
      self.im=data
      
    except CvBridgeError as e:
      print(e)

  def damn(self):
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        self.red_only_check_pub.publish(self.bool)
        rate.sleep()
  
    

    
      
    

    
    
    
  


def main():
    rospy.init_node('red_only_check')
    try:
        ic=image_checker()
    except rospy.ROSInterruptException:
        pass
  
  

if __name__ == '__main__':
    main()
        



