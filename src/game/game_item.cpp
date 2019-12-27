#include "game_item.h"
#include "texture_manager.h"
#include "game.h"
#include <iostream>
#include <chrono>

GameItem::GameItem(Renderer* ren)
{
  renderer = ren;
  texture = Game::getTexture();
  // Initalize rects in case not initialized
  srcRect = {0, 0, 0, 0};
  destRect = {0, 0, 0, 0};
}

GameItem::~GameItem()
{

}

void GameItem::draw()
{
  SDL_Rect renderRect = {destRect.x - Game::camera.getX(), destRect.y - Game::camera.getY(), destRect.w, destRect.h};
  renderer->copy(texture, &srcRect, &renderRect);
}
