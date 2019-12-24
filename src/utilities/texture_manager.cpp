#include "texture_manager.h"
#include <SDL2/SDL_image.h>

SDL_Texture* TextureManager::loadTexture(const char* fileName, Renderer* ren)
{
  SDL_Surface* tempSurface = IMG_Load(fileName);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(ren->getRenderer(), tempSurface);
  SDL_FreeSurface(tempSurface);

  return texture;
}
