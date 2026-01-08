#include <OF/lib/HubManager/HubRegistry.hpp>
#include <OF/lib/Node/NodeManager.hpp>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "configs.hpp"

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

using namespace OF;

int main() {
  LOG_INF("main");
  HubRegistry::startAll();
  config_nodes();
  start_all_nodes();
  while (true) {
    k_sleep(K_MSEC(1000));
  }
}
