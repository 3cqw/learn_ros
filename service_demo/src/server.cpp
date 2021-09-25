#include "ros/ros.h"
#include "service_demo/AddInts.h"

bool add(service_demo::AddInts::Request &req, service_demo::AddInts::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_server");
  ros::NodeHandle nh;
  //接收由add_ints服务传来的请求srv.requeset，并调用回调函数处理请求，将结果传给srv.response
  ros::ServiceServer service = nh.advertiseService("add_ints", add);
  ROS_INFO("Ready to add two ints.");
  //调用回调函数
  ros::spin();
  return 0;
}