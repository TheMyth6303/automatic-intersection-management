#include <Vehicle.h>

Vehicle::Vehicle(int d, int v) {
    this->d = d;
    this->v = v;
}

Vehicle::~Vehicle() {}

void Vehicle::update(int a) {
    d = d - v;
    v = v + a;
};

D1_Vehicle::D1_Vehicle(int d, int v) : Vehicle(d, v) {}

int D1_Vehicle::getX(int wsize, int roadwidth) { return wsize / 2 + roadwidth / 2 - d; }

int D1_Vehicle::getY(int wsize, int roadwidth) { return wsize / 2 - roadwidth / 4; }

int D1_Vehicle::getTheta() { return 0; }

D2_Vehicle::D2_Vehicle(int d, int v) : Vehicle(d, v) {}

int D2_Vehicle::getX(int wsize, int roadwidth) { return wsize / 2 - roadwidth / 4; }

int D2_Vehicle::getY(int wsize, int roadwidth) { return wsize / 2 - roadwidth / 2 + d; }

int D2_Vehicle::getTheta() { return 90; }

D3_Vehicle::D3_Vehicle(int d, int v) : Vehicle(d, v) {}

int D3_Vehicle::getX(int wsize, int roadwidth) { return wsize / 2 - roadwidth / 2 + d; }

int D3_Vehicle::getY(int wsize, int roadwidth) { return wsize / 2 + roadwidth / 4; }

int D3_Vehicle::getTheta() { return 180; }

D4_Vehicle::D4_Vehicle(int d, int v) : Vehicle(d, v) {}

int D4_Vehicle::getX(int wsize, int roadwidth) { return wsize / 2 + roadwidth / 4; }

int D4_Vehicle::getY(int wsize, int roadwidth) { return wsize / 2 + roadwidth / 2 - d; }

int D4_Vehicle::getTheta() { return 270; }
