#include <Colors.h>
#include <SDL.h>
#include <Simulator.h>
#include <Vehicle.h>
#include <vector>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

Simulator::Simulator(){};
Simulator::~Simulator(){};

void Simulator::init(const char *title, int width, int height) {
    this->width = width;
    this->height = height;

    isRunning = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        isRunning = false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        isRunning = false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        isRunning = false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Simulator::render() {
    SDL_RenderClear(renderer);
    SDL_Rect rect;

    SDL_SetRenderDrawColor(renderer, Colors::GROUND.r, Colors::GROUND.g, Colors::GROUND.b, 255);
    rect = {0, 0, width, height};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, Colors::ROAD.r, Colors::ROAD.g, Colors::ROAD.b, 255);
    rect = {2 * width / 5, 0, width / 5, height};
    SDL_RenderFillRect(renderer, &rect);
    rect = {0, 2 * height / 5, width, height / 5};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, Colors::DIVIDER.r, Colors::DIVIDER.g, Colors::DIVIDER.b, 255);
    SDL_RenderDrawLine(renderer, width / 2, 0, width / 2, 2 * height / 5);
    SDL_RenderDrawLine(renderer, 2 * width / 5, 0, 2 * width / 5, 2 * height / 5);
    SDL_RenderDrawLine(renderer, 3 * width / 5, 0, 3 * width / 5, 2 * height / 5);
    SDL_RenderDrawLine(renderer, width / 2, 3 * height / 5, width / 2, height);
    SDL_RenderDrawLine(renderer, 2 * width / 5, 3 * height / 5, 2 * width / 5, height);
    SDL_RenderDrawLine(renderer, 3 * width / 5, 3 * height / 5, 3 * width / 5, height);
    SDL_RenderDrawLine(renderer, 0, height / 2, 2 * width / 5, height / 2);
    SDL_RenderDrawLine(renderer, 0, 2 * height / 5, 2 * width / 5, 2 * height / 5);
    SDL_RenderDrawLine(renderer, 0, 3 * height / 5, 2 * width / 5, 3 * height / 5);
    SDL_RenderDrawLine(renderer, 3 * width / 5, height / 2, width, height / 2);
    SDL_RenderDrawLine(renderer, 3 * width / 5, 2 * height / 5, width, 2 * height / 5);
    SDL_RenderDrawLine(renderer, 3 * width / 5, 3 * height / 5, width, 3 * height / 5);

    SDL_RenderPresent(renderer);
}

void Simulator::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Simulator::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}