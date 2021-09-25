#include <ros/ros.h>
#include <topic_demo/gps.h>    //添加msg文件，编译自动生成

int main(int argc, char **argv)
{
  //原型：ros::init(argc,argv,const string &name, uint32_t options = 0);
  //argc,argv:重映射参数，用于解析命令行中的节点名称，覆盖节点名，如__name:=talk_2;
  //name: 初始节点名;
  //options: 枚举，三个参量{NoSigintHandler=1,AnonymousName=2,NoRosout=4};
  //AnonymousName:在节点名后添加一个随机数，匿名话节点，以使节点名唯一;
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;
  topic_demo::gps msg;
  msg.x = 0;
  msg.y = 0;
  msg.state = "working";

  //原型：ros::Publisher advertise(const string &topic,uint32_t queue_size,latch=false)
  //topic::要发布的话题名
  //queue_size:消息最大储存数量，超过该数量，旧消息出队丢弃
  //latch:锁存，锁住消息，不进行发布;
  ros::Publisher pub = nh.advertise<topic_demo::gps>("gps_info",1);
  //设置消息发布频率，单位 HZ
  ros::Rate loop_rate(1.0);
  while(ros::ok())
  {
    ROS_INFO("sending gps info: location: x:%.2f, y:%.2f, state: %s",msg.x,msg.y,msg.state.c_str());
    pub.publish(msg);
    msg.x += 5;
    msg.y = 5*msg.x + 5;
    //使程序休眠，以保证按设置的频率进行消息发布
    loop_rate.sleep();
  }
  return 0;

}