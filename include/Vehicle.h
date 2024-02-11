#ifndef VEHICLE_H
#define VEHICLE_H

const int L = 20;
const int B = 10;

class Vehicle {
    protected:
        int d;
        int v;

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

class D3_Vehicle : public Vehicle {
    private:
    public:
        D3_Vehicle(int d, int v);
        int getX(int wsize, int roadwidth) override;
        int getY(int wsize, int roadwidth) override;
        int getTheta() override;
};

class D4_Vehicle : public Vehicle {
    private:
    public:
        D4_Vehicle(int d, int v);
        int getX(int wsize, int roadwidth) override;
        int getY(int wsize, int roadwidth) override;
        int getTheta() override;
};

#endif