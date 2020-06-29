
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <prius_msgs/Control.h>
#include <std_msgs/Float64.h>

//initialisation of global variable variables
int prev_input(1),gear(0);
ros::Publisher *pubPtr;

// Calculation for prius movement
void assignvelocity( const geometry_msgs::Twist& msginput_teleop)
{

prius_msgs::Control priuscontrolmsg;

ros::param::get("/simple_control_node/throttle_param",priuscontrolmsg.throttle);
ros::param::get("/simple_control_node/steer_param",priuscontrolmsg.steer);

//forward movement
if(msginput_teleop.linear.x>0 && prev_input == 2) // identify the tranformation of input from reverse to forward
{
priuscontrolmsg.throttle = 0;
priuscontrolmsg.brake = 1;
priuscontrolmsg.shift_gears = 1;
prev_input = 1;
}
else if (msginput_teleop.linear.x>0 && prev_input == 1) // when current input and previous input is forward
{
priuscontrolmsg.brake = 0;
priuscontrolmsg.shift_gears = 2; //shifting gears for forward movement
gear = 1;
	if(priuscontrolmsg.throttle< 1)
	{
	priuscontrolmsg.throttle = priuscontrolmsg.throttle + 0.5; //linear increment of acceleration forward
	}
	else
	{
	priuscontrolmsg.throttle = 1; //max throttle reached
	}

}

//reverse movement
if(msginput_teleop.linear.x<0 && prev_input == 1) // identify the tranformation of input from forward to reverse
{
priuscontrolmsg.throttle = 0;
priuscontrolmsg.brake = 1;
priuscontrolmsg.shift_gears = 1;
prev_input = 2;
}
else if (msginput_teleop.linear.x<0&& prev_input == 2)  // when current input and previous input is reverse
{
priuscontrolmsg.brake = 0;
priuscontrolmsg.shift_gears = 3; //shifting gears for reverse movement
gear = -1;
	if(priuscontrolmsg.throttle < 1 )
	{
	priuscontrolmsg.throttle = priuscontrolmsg.throttle + 0.5; //linear increment of acceleration reverse
	}
	else
	{
	priuscontrolmsg.throttle = 1; //max throttle reached
	}
}

//Turning left 
if(msginput_teleop.angular.z>0)
{
	if(priuscontrolmsg.steer< 1)
	{
	priuscontrolmsg.steer = priuscontrolmsg.steer + 0.5; //linear progression of steering wheel towards left
	}
	else
	{
	priuscontrolmsg.steer = 1; //max steering angle reached
	}
}

//Turning right 
if(msginput_teleop.angular.z<0)
{
	if(priuscontrolmsg.steer> -1)
	{
	priuscontrolmsg.steer = priuscontrolmsg.steer - 0.5; //linear progression of steering wheel towards right
	}
	else
	{
	priuscontrolmsg.steer = -1; //max steering angle reached
	}
}


//Printing the information to the console
ROS_INFO_STREAM("Current control of prius- throttle:" << priuscontrolmsg.throttle <<" steer:"<< priuscontrolmsg.steer <<" Gear:" <<priuscontrolmsg.shift_gears <<" Brake:" <<priuscontrolmsg.brake);


pubPtr->publish(priuscontrolmsg); //publishing the /prius message 

//setting the global parameters throttle param and steer param
ros::param::set("/simple_control_node/throttle_param",priuscontrolmsg.throttle);
ros::param::set("/simple_control_node/steer_param",priuscontrolmsg.steer);

}


int main ( int argc, char**argv) 
{
ros::init (argc,argv,"simple_control_node"); //initialising the node as somple control node
ros::NodeHandle nh ; //Creating new node handle


pubPtr = new ros::Publisher(nh.advertise<prius_msgs::Control>("prius",1000)); // creating the variable to publishi the prius message

ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel",1000,&assignvelocity); // subscribing the /turtle1/cmd_vel topic for controlling prius movement

ros::spin();

delete pubPtr;
}
