#include "Game.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

Game::Game() {
    window = NULL;
    renderer = NULL;
    running = true;
}

int Game::OnExecute() {
    if (OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while (running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();

        OnRender();
    }

    OnCleanup();

    return 0;
}

bool Game::OnInit() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        window = SDL_CreateWindow("PixelRay", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else {

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (renderer == NULL) {
                printf("Unable to create! SDL_Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
//                int imgFlags = IMG_INIT_PNG;
//                if (!(IMG_Init(imgFlags) & imgFlags))
//                {
//                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//                    success = false;
//                }
            }
        }
    }

    if (success) {
        flock = Flock(renderer);
    }

    return success;
}

void Game::OnEvent(SDL_Event* Event) {
    if (Event->type == SDL_QUIT) {
        running = false;
    }

    if (Event->type == SDL_MOUSEBUTTONDOWN) {
        if (Event->button.button == SDL_BUTTON_LEFT) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            //spawn a boid
            flock.AddBoid(x, y);

        }
        else if (Event->button.button == SDL_BUTTON_RIGHT) {
            //remove a boid
        }
    }
}

void Game::OnLoop() {
    flock.Run();
}

void Game::OnRender() {
    SDL_RenderClear(renderer);
    flock.Render();
    SDL_RenderPresent(renderer);
}

void Game::OnCleanup() {
    //free renderer
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //free screen
    SDL_DestroyWindow(window);
    window = NULL;

    //quit SDL subsystems
    SDL_Quit();
}