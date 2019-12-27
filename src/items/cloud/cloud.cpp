#include "cloud.h"
#include <cstdlib>
#include <ctime>
#include "constants.h"

Cloud::Cloud(Renderer* ren) : GameItem(ren)
{
  std::srand(std::time(0));
  int type = 1 + std::rand() % 3;
  if (type == 1)
  {
    destRect = {WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT, 128, 64};
    speed = 18;
  } else if (type == 2) {
    destRect = {WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT, 160, 96};
    speed = 12;
  } else {
    destRect = {WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT, 192, 128};
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
