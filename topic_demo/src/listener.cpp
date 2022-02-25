#include <ros/ros.h>
#include <topic_demo/gps.h>
//#include <std_msgs/Float32.h>

void gpsCallback(const topic_demo::gps::ConstPtr &msg)
{
  ROS_INFO("received location: (x,y)=(%.2f,%.2f)",msg->x,msg->y);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;
  //原型：ros::Subscriber subscribe(const string &topic,uint32_t queue_size,void(*)(M));
  //topic::要订阅的话题名
  //queue_size:消息最大储存数量，超过该数量，旧消息出队丢弃
  //void(*)(M):回调函数指针，M是函数的参数，是一个模板;
  ros::Subscriber sub = nh.subscribe("gps_info", 1, gpsCallback);

  //进入订阅话题事件循环
  ros::spin();

  return 0;
}