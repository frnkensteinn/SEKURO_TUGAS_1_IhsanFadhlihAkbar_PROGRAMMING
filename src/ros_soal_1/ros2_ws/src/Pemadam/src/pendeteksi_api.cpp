#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class FireDetector : public rclcpp::Node {
public:
    FireDetector() : Node("fire_detector_node") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("fire_alert", 10);
        timer_ = this->create_wall_timer(2s, std::bind(&FireDetector::detect_fire, this));
    }

private:
    void detect_fire() {
        auto msg = std_msgs::msg::String();
        msg.data = "Kebakaran terdeteksi di dapur";

        RCLCPP_INFO(this->get_logger(), "ALERT: %s", msg.data.c_str());
        publisher_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FireDetector>());
    rclcpp::shutdown();
    return 0;
}
