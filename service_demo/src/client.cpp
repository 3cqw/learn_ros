#include "ros/ros.h"
#include "service_demo/AddInts.h"  //添加srv文件，编译后自动生成
#include <cstdlib>

int main(int argc, char **argv)
{
  //初始化服务的节点
  ros::init(argc, argv, "add_client");
  //检查参数个数
  if (argc != 3)
  {
    ROS_INFO("give me two ints");
    return 1;
  }

  ros::NodeHandle nh;
  //创建一个client对象，用于请求服务,client与server在add_ints上进行通信
  //原型：ros::ServiceClient serviceClient<class service>(const string &name, bool persistent=false)
  //name:客户端节点名，用于请求服务
  //persistent: 用于与远程主机的保持连接，不推荐使用(不稳定)
  ros::ServiceClient client = nh.serviceClient<service_demo::AddInts>("add_ints");
  service_demo::AddInts srv;
  srv.request.a = atol(argv[1]);
  srv.request.b = atol(argv[2]);
  //请求服务，将srv结构体传入；在服务端响应前，请求将被阻塞，
  //服务端做出相应，返回true，并接受响应值，并传给srv.response；
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_ints");
    return 1;
  }

  return 0;
}