#include "player.h"
#include "game.h"
#include "constants.h"
#include <cmath>

int Player::maxXVel = TILE_WIDTH / 4;
int Player::maxYVel = TILE_HEIGHT / 4;


Player::Player(Renderer* ren, std::vector<AABB*> &boxes) : TileGameItem(ren, boxes)
{
  srcRect = {64, 0, 16, 16};
  destRect = {this->boxes.at(1)->getX(), this->boxes.at(0)->getY(), this->boxes.at(1)->getW(), this->boxes.at(0)->getH()};
  jumping = false;
  jumpAllowed = true;
}

Player::~Player()
{

}

void Player::update()
{
  if (Game::inputs.left)
  {
    if (xVel > -maxXVel)
    {
      xVel -= 1;
    }
    changeX((int) xVel);
  }
  else if (Game::inputs.right)
  {
    if (xVel < maxXVel)
    {
      xVel += 1;
    }
    changeX((int) xVel);
  }
  else
  {
    xVel /= 2;
    changeX((int) xVel);
  }

  if (Game::inputs.up)
  {
    if (!jumping && jumpAllowed)
    {
      jumping = true;
      jumpAllowed = false;
    }
  }
  else
    if (jumping)
      jumping = false;

  if (jumping)
  {
    if (std::abs(yVel) < maxYVel / 2)
      yVel -= 1;
    else
      jumping = false;
    changeY((int) yVel);
  }
  else
  {
    if (yVel < maxYVel)
    {
      yVel += 1;
    }
    changeY((int) yVel);
  }
}

void Player::draw()
{
  renderer->setDrawColor(255, 0, 0, 128);
  SDL_Rect dRect = {boxes[1]->getX() - Game::camera.getX(), boxes[1]->getY() - Game::camera.getY(), boxes[1]->getW(), boxes[1]->getH()};
  renderer->fillRect(&dRect);
  renderer->setDrawColor(0, 0, 255, 128);
  dRect = {boxes[0]->getX() - Game::camera.getX(), boxes[0]->getY() - Game::camera.getY(), boxes[0]->getW(), boxes[0]->getH()};
  renderer->fillRect(&dRect);

  destRect.x = boxes[1]->getX();
  destRect.y = boxes[0]->getY();
  // GameItem::draw();
}

void Player::changeX(int change)
{
  AABBGameItem::changeX(change);
  if (change > 0)
  {
    if (destRect.x + destRect.w / 2 >= Game::camera.getX() + WINDOW_WIDTH - WINDOW_WIDTH / 4)
      Game::camera.move(change, 0);
  }
  else
  {
    if (destRect.x + destRect.w / 2 <= Game::camera.getX() + WINDOW_WIDTH / 4)
      Game::camera.move(change, 0);
  }
}

void Player::changeY(int change)
{
  AABBGameItem::changeY(change);
  if (change > 0)
  {
    if (destRect.y + destRect.h / 2 >= Game::camera.getY() + WINDOW_HEIGHT - WINDOW_HEIGHT / 4)
      Game::camera.move(0, change);
  }
  else
  {
    if (destRect.y + destRect.h / 2 <= Game::camera.getY() + WINDOW_HEIGHT / 4)
      Game::camera.move(0, change);
  }
}
