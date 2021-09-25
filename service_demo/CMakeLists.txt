cmake_minimum_required(VERSION 3.0.2)
project(service_demo)

#查找依赖包
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)
## 添加srv文件夹中的srv文件，用于下一步生成消息头文件
add_service_files(FILES AddInts.srv)
## 用于生成消息头文件
generate_messages(DEPENDENCIES std_msgs)

catkin_package()
#添加头文件
include_directories(${catkin_INCLUDE_DIRS})

add_executable(add_client_node src/client.cpp)
target_link_libraries(add_client_node ${catkin_LIBRARIES})
add_dependencies(add_client_node service_demo_gencpp)


