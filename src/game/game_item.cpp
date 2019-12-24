#include "game_item.h"
#include "texture_manager.h"
#include "camera.h"
#include <iostream>

GameItem::GameItem(const char* texturesheet, Renderer* ren)
{
  renderer = ren;
  texture = TextureManager::loadTexture(texturesheet, renderer);
  // Initalize rects in case not initialized
  srcRect = {0, 0, 0, 0};
  destRect = {0, 0, 0, 0};
}

GameItem::~GameItem()
{
  SDL_DestroyTexture(texture);
}

void GameItem::changeTexture(const char* texturesheet)
{
  SDL_DestroyTexture(texture);
  texture = TextureManager::loadTexture(texturesheet, renderer);
}

void GameItem::draw()
{
  SDL_Rect renderRect = {destRect.x - Camera::getX(), destRect.y - Camera::getY(), destRect.w, destRect.h};
  renderer->copy(texture, &srcRect, &renderRect);
}
