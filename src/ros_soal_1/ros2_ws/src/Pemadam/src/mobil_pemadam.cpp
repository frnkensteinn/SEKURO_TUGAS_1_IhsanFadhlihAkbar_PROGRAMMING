#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class FireTruck : public rclcpp::Node {
public:
    FireTruck() : Node("fire_truck_node") {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "fire_alert", 10,
            std::bind(&FireTruck::response, this, std::placeholders::_1)
        );
    }

private:
    void response(const std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Menerima: %s", msg->data.c_str());
        RCLCPP_INFO(this->get_logger(), "Unit pemadam menuju lokasi");
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FireTruck>());
    rclcpp::shutdown();
    return 0;
}
