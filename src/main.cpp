#include <Simulator.h>
#include <iostream>

const int WIDTH = 720, HEIGHT = 720;
const int FPS = 24;

int main(int argc, char *argv[]) {
    Simulator *simulator = new Simulator;
    simulator->init("simulation", WIDTH, HEIGHT);
    while (simulator->isRunning) {
        simulator->render();
        simulator->update();
    }
    simulator->destroy();
    return EXIT_SUCCESS;
}