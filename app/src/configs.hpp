#pragma once
#include <OF/lib/ControllerHub/ControllerHub.hpp>
#include <OF/lib/ImuHub/ImuHub.hpp>
#include <OF/lib/NotifyHub/NotifyHub.hpp>
#include "OneChassisNode.hpp"

// 在这里添加各个Hub的编译期Config
// 你可以在 one-framework 文档中查找到各个Hub所需的配置
constexpr ControllerHubConfig controller_hub_config{
    .input_device = DEVICE_DT_GET(DT_NODELABEL(usart3))
};

constexpr ImuHubConfig imu_hub_config{
    .accel_dev = DEVICE_DT_GET(DT_NODELABEL(bmi088_accel)),
    .gyro_dev = DEVICE_DT_GET(DT_NODELABEL(bmi088_gyro))
};

constexpr NotifyHubConfig notify_hub_config{
    .led_pixel_dev = DEVICE_DT_GET(DT_NODELABEL(pixel_led)),
    .pwm_buzzer_dev = DEVICE_DT_GET(DT_NODELABEL(pwm_buzzer))
};

// 在这里配置 Nodes
void config_nodes()
{
    OneChassisNode::bind<OneChassisNode::Config>({DEVICE_DT_GET(DT_NODELABEL(can1))});
}
