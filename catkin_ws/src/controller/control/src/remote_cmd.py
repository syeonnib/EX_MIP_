#!/usr/bin/env python



import roslaunch 
import rospy
from std_msgs.msg import Bool




class remote_cmd:
    
  def __init__(self):
    
  
    self.remote_sub = rospy.Subscriber("/remote_status",Bool,self.callback)
    
    self.recent=Bool()
    self.start=Bool()
    
    self.damn()
    
  def callback(self,data):
        
    if data.data == True:
        
        if self.recent.data==False:
            
            self.start.data=True
            
            self.recent.data=True

        

  def damn(self):
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        
        if self.start.data==True:
            
            return

        
        
        
        rate.sleep()
    

    
      
    

    
    
    
  


def main():
    
    rospy.init_node('brake_and_pot_cmd')
    try:
        rc=remote_cmd()
        

        uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(uuid)
        launch = roslaunch.parent.ROSLaunchParent(uuid, ["/home/mipev/mip_ws/src/planning/teb_local_planner_tutorials/launch/mip_lidar_goal.launch"])
        launch.start()
        rospy.sleep(10)
        launch.shutdown()
        
        
        
    except rospy.ROSInterruptException:
        pass
        
        
  
  

if __name__ == '__main__':
    
    main()

