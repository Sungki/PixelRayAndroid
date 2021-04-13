//
// Created by youby on 4/13/2021.
//

#ifndef TESTNDK_TEXTURELOADER_H
#define TESTNDK_TEXTURELOADER_H
#include <SDL.h>
#include <string>

class TextureLoader {
private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;

public:
    TextureLoader();
    bool LoadFromFile(std::string path, SDL_Renderer* renderer);
    void Render(int x, int y, double angle, SDL_Renderer* renderer);
    int GetWidth();
    int GetHeight();
    SDL_Texture* GetTexture();
};


#endif //TESTNDK_TEXTURELOADER_H
