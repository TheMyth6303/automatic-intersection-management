#include <SDL.h>
#include <Simulator.h>

const int W_SIZE = 800;
const int FPS = 24;

int main(int argc, char *argv[]) {
    uint32_t frameStart;
    int frameTime;

    Simulator *simulator = new Simulator;
    simulator->init("simulation", W_SIZE);
    while (simulator->isRunning) {
        frameStart = SDL_GetTicks();
        simulator->render();
        simulator->handleEvents();
        simulator->update();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 1000 / FPS) {
            SDL_Delay(1000 / FPS - frameTime);
        }
    }
    simulator->destroy();
    return EXIT_SUCCESS;
}