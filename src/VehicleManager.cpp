#include <VehicleManager.h>

std::vector<Vehicle *> VehicleManager::vehicles;

VehicleManager::VehicleManager() {}

VehicleManager *VehicleManager::getInstance() {
    static VehicleManager instance;
    return &instance;
}

void VehicleManager::update() {
    for (Vehicle *v : vehicles) {
        v->update(0);
    }
}
