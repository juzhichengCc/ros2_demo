cmake_minimum_required(VERSION 3.5)

project(ros2_demo)

find_package(rclcpp)
find_package(std_msgs)

add_executable(talker talker.cc)
ament_target_dependencies(talker
  rclcpp
  std_msgs
)
add_executable(listener listener.cc)
ament_target_dependencies(listener
  rclcpp
  std_msgs
)