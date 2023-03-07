#!/usr/bin/env python
# license removed for brevity

import rospy
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

from geometry_msgs.msg import Point

def callback(data):
    if not data.x==0:
        #print("saving global")
        global x, y 
        x= data.x
        y= data.y
        mv= movebase_client()
        if mv:
            rospy.signal_shutdown("done")
    else:
	#print("else")
        rospy.loginfo("waiting for non zero point")



def movebase_client():
    print("enter mv")
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
    client.wait_for_server()

    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
    goal.target_pose.pose.position.x = x
    goal.target_pose.pose.position.y = y
    goal.target_pose.pose.orientation.w = 1.0

    client.send_goal(goal)
    wait = client.wait_for_result()
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
        
    else:
        return client.get_result()

def mvpub():
    rospy.init_node('mv_pub')
    print("init")
    while not rospy.is_shutdown():
        rospy.Subscriber("/planning/end_point",Point,callback)
        print("rospy sub")
        rate=rospy.Rate(2)
        
        rate.sleep()
        
        

if __name__ == '__main__':
    #print("main")
    try:
        mvpub()
    except rospy.ROSInterruptException:
        pass
