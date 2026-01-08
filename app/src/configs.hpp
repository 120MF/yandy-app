#pragma once
#include "OneChassisNode.hpp"

// 在这里添加各个Hub的编译期Config
// 你可以在 one-framework 文档中查找到各个Hub所需的配置
constexpr ControllerHubConfig controller_hub_config{
    .input_device = DEVICE_DT_GET_ANY(dji_dbus)
};

// 在这里配置 Nodes
void config_nodes()
{
    OneChassisNode::bind<OneChassisNode::Config>({DEVICE_DT_GET(DT_NODELABEL(can1))});
}
