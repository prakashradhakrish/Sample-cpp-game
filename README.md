**Simple Control Node**  
The simple control node performs the control operation of the vehicle in gazebo simulator. The control is acheived by linking the "teleop key" package and the gazebo package. The topic is subscibed from the "teleop key" package and the 
control is acheived based on the information from this topic. Later, the control is published in the gazebo simulator to acheive the control.  

**Excecute the simple control node:**  
This following code is given assuming that the Car Simulator repository is in catkin_ws/src.  

source /opt/ros/kinetic/setup.bash   
cd catkin_ws/src  
git clone _group 14 repository link_  
cd ..  
catkin_make  
roslaunch simple_control simple_control.launch   

**Record and play simple control node:**  
In order to record the control of the vehicle in the simulator, the initials steps are to be performed as follows :

source /opt/ros/kinetic/setup.bash  
cd catkin_ws/src  
git clone _group 14 repository link_  
cd ..  
catkin_make  
roslaunch simple_control record.launch  

After recording the sequences, it could be played back by using the "play.launch" file. This could be accessed by the following commands :

roslaunch simple_control play.launch

**Note:**  
A successful playback was acheived only for some sequence of the recording. This is because the "RVIZ" simulator takes a longer time to load. Also more importantly, the time stamp information is mostly not recorded in the bag file for geometry_twist. Hence _we get an unsychronised playback_.
