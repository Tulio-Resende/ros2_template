#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode();
    ~MyNode();

    void configNode();

private:

    void configPublishers();
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        
    void configSubscribers();
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void timer_callback();
    void topic_callback(const std_msgs::msg::String::SharedPtr msg);

    rclcpp::TimerBase::SharedPtr timer_;
    
};
