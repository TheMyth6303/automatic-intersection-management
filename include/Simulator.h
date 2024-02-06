#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator {
    private:
        int width, height;

    public:
        bool isRunning;
        Simulator();
        void init(const char *title, int width, int height);
        void render();
        void update();
        void destroy();
        ~Simulator();
};

#endif