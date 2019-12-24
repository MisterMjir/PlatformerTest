#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include <SDL2/SDL.h>
#include "renderer.h"

class TextureManager
{
public:
  static SDL_Texture* loadTexture(const char*, Renderer*);
};

#endif
