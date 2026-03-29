#pragma once
#include <OneChassisNode.hpp>
#include <YandyGimbalNode.hpp>
#include <YandyCommunicateNode.hpp>
#include <zephyr/drivers/pwm.h>

// Servo PWM specs - TIM1 CH1 and CH2, 20ms period (50Hz)
// Channel numbering: TIM1_CH1 = 1, TIM1_CH2 = 2
// The PWM device is the pwm child node itself, not its parent (timers)
static constexpr pwm_dt_spec servo1_spec = {
    .dev = DEVICE_DT_GET(DT_NODELABEL(pwm1)),
    .channel = 1,
    .period = PWM_MSEC(20),
    .flags = PWM_POLARITY_NORMAL
};

static constexpr pwm_dt_spec servo2_spec = {
    .dev = DEVICE_DT_GET(DT_NODELABEL(pwm1)),
    .channel = 2,
    .period = PWM_MSEC(20),
    .flags = PWM_POLARITY_NORMAL
};

// 在这里配置 Nodes
void config_nodes()
{
    OneChassisNode::bind<OneChassisNode::Config>({DEVICE_DT_GET(DT_NODELABEL(can2))});

    YandyGimbalNode::bind<YandyGimbalNode::Config>({
        DEVICE_DT_GET(DT_NODELABEL(can1)),
        &servo1_spec,
        &servo2_spec
    });

    YandyCommunicateNode::bind<YandyCommunicateNode::Config>({
        DEVICE_DT_GET(DT_NODELABEL(cdc_acm_uart0))
    });
}

