#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator {
    private:
    public:
        Simulator();
        void init(const char *title, int width, int height, int fps);
        void update();
        void destroy();
        ~Simulator();
};

#endif