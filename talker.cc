#include <iostream>
#include <string>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("talker");
  std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>> publisher = 
          node->create_publisher<std_msgs::msg::String>("topic", 10);
  
  rclcpp::WallRate loop_rate(10);
  auto msg = std_msgs::msg::String();
  int count = 0;
  
  while(rclcpp::ok()) {
    msg.data = "hello world: " + std::to_string(count++);
    publisher->publish(msg);
    std::cout << "talker send msg: " << msg.data << "\n";
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}