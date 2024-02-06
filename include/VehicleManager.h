#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include <Vehicle.h>
#include <unordered_set>

class VehicleManager {
    private:
        VehicleManager();
        VehicleManager(VehicleManager const &) = delete;
        VehicleManager &operator=(const VehicleManager &) = delete;
        static std::unordered_set<Vehicle> *vehicles;
        ~VehicleManager();

    public:
        static VehicleManager &getInstance();
        void update();
        void destroy();
};

#endif