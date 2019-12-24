#include "cloud.h"
#include <cstdlib>
#include <ctime>
#include "game.h"

Cloud::Cloud(const char* texturesheet, Renderer* ren) : GameItem(texturesheet, ren)
{
  std::srand(std::time(0));
  int type = 1 + std::rand() % 3;
  if (type == 1)
  {
    destRect = {Game::inputs.winW, std::rand() % Game::inputs.winH, 128, 64};
    speed = 18;
  } else if (type == 2) {
    destRect = {Game::inputs.winW, std::rand() % Game::inputs.winH, 160, 96};
    speed = 12;
  } else {
    destRect = {Game::inputs.winW, std::rand() % Game::inputs.winH, 192, 128};
    speed = 6;
  }
}

void Cloud::update()
{
  destRect.x -= speed;
}

void Cloud::draw()
{
  renderer->setDrawColor(255, 255, 255, 128);
  renderer->fillRect(&destRect);
}

bool Cloud::offScreen()
{
  if (destRect.x < -192)
    return true;
  else
    return false;
}
