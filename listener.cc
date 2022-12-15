#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void callback(std::shared_ptr<std_msgs::msg::String> msg) {
  std::cout << "receive: " << msg->data << "\n";
}

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("listener");
  auto subscriber = node->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(callback, std::placeholders::_1));
  
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}