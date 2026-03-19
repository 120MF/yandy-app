#pragma once
#include "OneChassisNode.hpp"

// 在这里配置 Nodes
void config_nodes()
{
    OneChassisNode::bind<OneChassisNode::Config>({DEVICE_DT_GET(DT_NODELABEL(can1))});
}
