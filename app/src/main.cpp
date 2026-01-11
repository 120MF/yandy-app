#include <OF/lib/HubManager/HubRegistry.hpp>
#include <OF/lib/Node/NodeManager.hpp>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "configs.hpp"
#include "OneChassisData.hpp"

extern Topic<OneChassisData>& topic_one_chassis;
LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);


using namespace OF;

int main()
{
    LOG_INF("main");
    HubRegistry::startAll();
    config_nodes();
    start_all_nodes();
    while (true)
    {
        const auto data = topic_one_chassis.read();
        LOG_INF("%s", data.format().c_str());
        auto [quat, euler_angle, gyro, accel] = getImuData();
        auto& [p, r, y] = euler_angle;
        LOG_INF("euler: %f, %f, %f;", p, r, y);
        k_sleep(K_MSEC(300));
    }
}

//TODO:
// 1. 目前add-node添加的路径还是不对，create-node功能没改 (solved)
// 2. 使用Github模板会把module.yml里的self path带过来，导致所有的目录名都叫one-starter，要不改叫one-app？
