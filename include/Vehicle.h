#ifndef VEHICLE_H
#define VEHICLE_H

const int L = 35;
const int B = 20;

class Vehicle {
    protected:
        double d;
        double v;

    public:
        Vehicle(int d, int v);
        ~Vehicle();
        void update(int a);
        virtual int getX(int wsize, int roadwidth) { return 0; };
        virtual int getY(int wsize, int roadwidth) { return 0; };
        virtual int getTheta() { return 0; };
};

class D1_Vehicle : public Vehicle {
    private:
    public:
        D1_Vehicle(int d, int v);
        int getX(int wsize, int roadwidth) override;
        int getY(int wsize, int roadwidth) override;
        int getTheta() override;
};

class D2_Vehicle : public Vehicle {
    private:
    public:
        D2_Vehicle(int d, int v);
        int getX(int wsize, int roadwidth) override;
        int getY(int wsize, int roadwidth) override;
        int getTheta() override;
};

#endif