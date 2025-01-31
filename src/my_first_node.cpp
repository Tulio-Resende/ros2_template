#include "my_cpp_pkg/my_first_node.hpp"

// Construtor
MyNode::MyNode() : Node("my_node")
{
    RCLCPP_INFO(this->get_logger(), "Constructor called.");

    // Cria um timer para publicar mensagens periodicamente
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500), std::bind(&MyNode::timer_callback, this));
}

MyNode::~MyNode()
{
}

void MyNode::configNode()
{
    configPublishers();
    configSubscribers();
}

void MyNode::configPublishers()
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("output_topic", 10);
}

void MyNode::configSubscribers()
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "input_topic", 10, std::bind(&MyNode::topic_callback, this, std::placeholders::_1));
}

void MyNode::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Olá, ROS 2!";
    publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "Publicando: '%s'", message.data.c_str());
}

// Callback do subscriber
void MyNode::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Recebido: '%s'", msg->data.c_str());
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MyNode>();
    node->configNode();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
