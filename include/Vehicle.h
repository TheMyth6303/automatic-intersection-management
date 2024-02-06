#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
    private:
        float x, y;
        float vx, vy;
        int direction;

    public:
        Vehicle();
        ~Vehicle();
        void create();
        void update();
};

#endif