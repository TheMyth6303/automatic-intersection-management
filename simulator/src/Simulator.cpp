#include <Colors.h>
#include <SDL.h>
#include <Simulator.h>
#include <Vehicle.h>
#include <VehicleManager.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *vehicleTexture;

VehicleManager *vehicleManager = VehicleManager::getInstance();

Simulator::Simulator(){};
Simulator::~Simulator(){};

void Simulator::init(const char *title, int wsize) {
    this->wsize = wsize;
    this->roadWidth = wsize / 8;

    isRunning = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        isRunning = false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wsize, wsize, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        isRunning = false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        isRunning = false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Surface *surface = SDL_CreateRGBSurface(0, L, B, 32, 0, 0, 0, 0);
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, Colors::VEHICLE.r, Colors::VEHICLE.g, Colors::VEHICLE.b, 255));
    vehicleTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    vehicleManager->generateRandom(6);
}

void Simulator::renderBG() {
    SDL_Rect rect;
    SDL_SetRenderDrawColor(renderer, Colors::GROUND.r, Colors::GROUND.g, Colors::GROUND.b, 255);
    rect = {0, 0, wsize, wsize};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, Colors::ROAD.r, Colors::ROAD.g, Colors::ROAD.b, 255);
    rect = {wsize / 2 - roadWidth / 2, 0, roadWidth, wsize};
    SDL_RenderFillRect(renderer, &rect);
    rect = {0, wsize / 2 - roadWidth / 2, wsize, roadWidth};
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, Colors::DIVIDER.r, Colors::DIVIDER.g, Colors::DIVIDER.b, 255);
    SDL_RenderDrawLine(renderer, wsize / 2, 0, wsize / 2, wsize / 2 - roadWidth / 2);
    SDL_RenderDrawLine(renderer, wsize / 2 - roadWidth / 2, 0, wsize / 2 - roadWidth / 2, wsize / 2 - roadWidth / 2);
    SDL_RenderDrawLine(renderer, wsize / 2 + roadWidth / 2, 0, wsize / 2 + roadWidth / 2, wsize / 2 - roadWidth / 2);
    SDL_RenderDrawLine(renderer, wsize / 2, wsize / 2 + roadWidth / 2, wsize / 2, wsize);
    SDL_RenderDrawLine(renderer, wsize / 2 - roadWidth / 2, wsize / 2 + roadWidth / 2, wsize / 2 - roadWidth / 2, wsize);
    SDL_RenderDrawLine(renderer, wsize / 2 + roadWidth / 2, wsize / 2 + roadWidth / 2, wsize / 2 + roadWidth / 2, wsize);
    SDL_RenderDrawLine(renderer, 0, wsize / 2, wsize / 2 - roadWidth / 2, wsize / 2);
    SDL_RenderDrawLine(renderer, 0, wsize / 2 - roadWidth / 2, wsize / 2 - roadWidth / 2, wsize / 2 - roadWidth / 2);
    SDL_RenderDrawLine(renderer, 0, wsize / 2 + roadWidth / 2, wsize / 2 - roadWidth / 2, wsize / 2 + roadWidth / 2);
    SDL_RenderDrawLine(renderer, wsize / 2 + roadWidth / 2, wsize / 2, wsize, wsize / 2);
    SDL_RenderDrawLine(renderer, wsize / 2 + roadWidth / 2, wsize / 2 - roadWidth / 2, wsize, wsize / 2 - roadWidth / 2);
    SDL_RenderDrawLine(renderer, wsize / 2 + roadWidth / 2, wsize / 2 + roadWidth / 2, wsize, wsize / 2 + roadWidth / 2);
}

void Simulator::renderVehicles() {
    SDL_Rect rect;
    SDL_SetRenderDrawColor(renderer, Colors::VEHICLE.r, Colors::VEHICLE.g, Colors::VEHICLE.b, 255);
    for (Vehicle *v : vehicleManager->vehicles) {
        int x = v->getX(wsize, roadWidth);
        int y = v->getY(wsize, roadWidth);
        int theta = v->getTheta();
        rect = {x - L / 2, y - B / 2, L, B};
        SDL_RenderCopyEx(renderer, vehicleTexture, nullptr, &rect, static_cast<double>(theta), nullptr, SDL_FLIP_NONE);
    }
}

void Simulator::render() {
    SDL_RenderClear(renderer);
    renderBG();
    renderVehicles();
    SDL_RenderPresent(renderer);
}

void Simulator::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void Simulator::update() { vehicleManager->update(); }

void Simulator::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(vehicleTexture);
    SDL_Quit();
}