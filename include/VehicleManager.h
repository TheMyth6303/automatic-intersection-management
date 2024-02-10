#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include <Vehicle.h>
#include <vector>

class VehicleManager {
    private:
        VehicleManager();
        VehicleManager(const VehicleManager &) = delete;
        VehicleManager &operator=(const VehicleManager &) = delete;

    public:
        static std::vector<Vehicle *> vehicles;
        static VehicleManager *getInstance();
        void update();
        template <typename T> T *addVehicle(int d, int v) {
            T *vehicle = new T(d, v);
            vehicles.push_back(vehicle);
            return vehicle;
        };
        void generateRandom(int n);
};

#endif