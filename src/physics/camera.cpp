#include "camera.h"

Camera::Camera()
{

}

CAMERA_DIRECTION Camera::getDirection()
{
  if (oldX != this->x || oldY != this->y)
    if (oldX != this->x && oldY != this->y)
      if (this->x > oldX)
        if (this->y < oldY)
          direction = NORTH_EAST;
        else
          direction = SOUTH_EAST;
      else
        if (this->y < oldY)
          direction = NORTH_WEST;
        else
          direction = SOUTH_WEST;
    else if (oldX != this->x)
      if (this->x > oldX)
        direction = EAST;
      else
        direction = WEST;
    else
    if (this->y < oldY)
      direction = NORTH;
    else
      direction = SOUTH;
  else
    direction = NONE;
  oldX = this->x;
  oldY = this->y;

  return direction;
}

void Camera::move(int x, int y)
{
  this->x += x;
  this->y += y;
}

void Camera::set(int x, int y)
{
  this->x = x;
  this->y = y;
}

void Camera::setX(int x)
{
  this->x = x;
}

void Camera::setY(int y)
{
  this->y = y;
}
