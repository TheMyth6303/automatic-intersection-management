#include <Vehicle.h>
#include <VehicleManager.h>
#include <chrono>
#include <iostream>
#include <random>

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

void VehicleManager::generateRandom(int n) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> directionDistribution(1, 4);
    std::uniform_int_distribution<int> distDistribution(100, 450);
    std::uniform_int_distribution<int> velDistribution(1, 5);

    for (int i = 0; i < n; i++) {
        int directionVar = directionDistribution(generator);
        int d = distDistribution(generator);
        int v = velDistribution(generator);

        Vehicle *vehicle;
        switch (directionVar) {
        case 1:
            vehicle = new D1_Vehicle(d, v);
            break;
        case 2:
            vehicle = new D2_Vehicle(d, v);
            break;
        case 3:
            vehicle = new D3_Vehicle(d, v);
            break;
        case 4:
            vehicle = new D4_Vehicle(d, v);
            break;
        default:
            break;
        }

        vehicles.push_back(vehicle);
    }
}
