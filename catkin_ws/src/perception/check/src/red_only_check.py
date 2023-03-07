#!/usr/bin/env python
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
    self.image_pub = rospy.Publisher("image_topic_2",Image,queue_size=1)

    self.bridge = CvBridge()
    
    self.box_sub= rospy.Subscriber('/darknet_ros/bounding_boxes', BoundingBoxes , self.callback2)
    self.image_sub = rospy.Subscriber("/darknet_ros/detection_image",Image,self.callback1)

  def callback2(self,data):
    #print('bblength:')
    #print(len(data.bounding_boxes))
    pub = rospy.Publisher('red_only_check', Bool,queue_size=1)
    
    
    for boxindex,box in enumerate(data.bounding_boxes):
      if len(data.bounding_boxes)>4:#for small errors
        
        ymean=(box.ymin+box.ymax)/2
        xmean=(box.xmin+box.xmax)/2
        cropim=tempimg[ymean:box.ymax,(xmean-box.xmin)/2+box.xmin:(box.xmax-xmean)/2+xmean] #need adjust to follow circumstances and bbox y min
        colr = cv2.mean(cropim)
        #cv2.imshow("Image window", cropim)
        #cv2.waitKey(3)
        #for debug: check bbox containing main color only
        b=colr[0]/np.sum(colr)
        g=colr[1]/np.sum(colr)
        r=colr[2]/np.sum(colr)
        th=0.8 #th val for calibration
        if b>0.4*th:
            label='blue'
            color=(255,0,0)
        elif g > 0.5*th:
            label = 'green'
            color = (0, 255, 0)
        elif r > 0.35*th:
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
          #pub.publish(False)
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
          pub.publish(True)
        
          
      


        
        
      
      
    
      



        
        
      
  def callback1(self,data):
    try:
      
      cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
      global tempimg
      tempimg = cv_image
      
    except CvBridgeError as e:
      print(e)
  
    

    
      
    

    
    
    
  


def main(args):
    while not rospy.is_shutdown():
        rospy.init_node('red_only_check')
        ic= image_checker()
        rospy.spin()
  
  

if __name__ == '__main__':
    try :
        main(sys.argv)
    except rospy.ROSInterruptException:
        print("Shutting down")
    cv2.destroyAllWindows()
        



