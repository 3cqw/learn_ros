cmake_minimum_required(VERSION 3.0.2)
project(topic_demo)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(FILES gps.msg)
generate_messages(DEPENDENCIES std_msgs)
#catkin_package()

include_directories(
# include
${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
add_dependencies(talker topic_demo_generate_messages_cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
add_dependencies(listener topic_demo_generate_messages_cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
