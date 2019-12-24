#include "player.h"
#include "constants.h"
#include "camera.h"
#include "game.h"
#include <iostream>

Player::Player(const char* texture, Renderer* ren, std::vector<AABB*> boxes) : AABBGameItem(texture, ren, boxes)
{
  srcRect = {0, 0, 32, 32};
  destRect = {boxes.at(1)->getX(), boxes.at(0)->getY(), boxes.at(1)->getW(), boxes.at(0)->getH()};
}

Player::~Player()
{

}

void Player::update()
{
  if (Game::inputs.left)
  {
    moveX(-4);
  }
  else if (Game::inputs.right)
  {
    moveX(4);
  }
  moveY(4);
}

void Player::moveX(int change)
{
  boxes.at(0)->changeX(change);
  boxes.at(1)->changeX(change);
  if (destRect.x + destRect.w / 2 <= WINDOW_WIDTH / 4 + Camera::getX() || destRect.x + destRect.w / 2 >= WINDOW_WIDTH - WINDOW_WIDTH / 4 + Camera::getX())
  {
    Camera::changeX(change);
  }
}

void Player::moveY(int change)
{
  boxes.at(0)->changeY(change);
  boxes.at(1)->changeY(change);
  /*if (destRect.x + destRect.w / 2 <= WINDOW_WIDTH / 4 + Camera::getX() || destRect.x + destRect.w / 2 >= WINDOW_WIDTH - WINDOW_WIDTH / 4 + Camera::getX())
  {
    Camera::changeX(change);
  }*/
}

void Player::draw()
{
  std::cout << "My X: " << boxes.at(0)->getX() << " My Y: " << boxes.at(0)->getY() << "\n";
  std::cout << "My X: " << boxes.at(1)->getX() << " My Y: " << boxes.at(1)->getY() << "\n\n";
  destRect.y = boxes.at(0)->getY();
  destRect.x = boxes.at(1)->getX();
  GameItem::draw();
}
