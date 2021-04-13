//
// Created by youby on 4/13/2021.
//

#ifndef TESTNDK_FLOCK_H
#define TESTNDK_FLOCK_H
#include <vector>
#include <random>
#include <SDL.h>
#include "Boid.h"

class Flock {
private:
    SDL_Renderer* renderer;
    std::vector<Boid> boids;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;

public:
    Flock();
    Flock(SDL_Renderer* renderer);
    void Run();
    void AddBoid(double x, double y);
    void Render();
};


#endif //TESTNDK_FLOCK_H
