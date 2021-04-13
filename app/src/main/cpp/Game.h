//
// Created by youby on 4/13/2021.
//

#ifndef TESTNDK_GAME_H
#define TESTNDK_GAME_H

#include <SDL.h>
#include "Flock.h"

class Game {
private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Flock flock;

public:
    Game();
    int OnExecute();
    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
};


#endif //TESTNDK_GAME_H
