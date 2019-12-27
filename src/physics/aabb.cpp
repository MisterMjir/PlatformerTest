#include "aabb.h"

AABB::AABB(int x, int y, int w, int h, AABB_Type type, bool linked)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  this->type = type;
  this->linked = linked;
}


int AABB::xOverlap(AABB* box)
{
  return ((box->getX() > this->x && box->getX() < this->x + this->w) ||
          (box->getX() + box->getW() > this->x && box->getX() + box->getW() < this->x + this->w)) &&
          ((box->getY() > this->y && box->getY() < this->y + this->h) ||
          (box->getY() + box->getH() > this->y && box->getY() + box->getH() < this->y + this->h));
}

int AABB::xDiff(AABB* box)
{
    if (box->getX() > this->x && box->getX() < this->x + this->w)
      return box->getX() - (this->x + this->w);
    else
      return this->x - (box->getX() + box->getW());
}

int AABB::yOverlap(AABB* box)
{
  return ((box->getX() > this->x && box->getX() < this->x + this->w) ||
          (box->getX() + box->getW() >= this->x && box->getX() + box->getW() <= this->x + this->w)) &&
          ((box->getY() > this->y && box->getY() < this->y + this->h) ||
          (box->getY() + box->getH() > this->y && box->getY() + box->getH() < this->y + this->h));
}

int AABB::yDiff(AABB* box)
{
    if (box->getY() >= this->y && box->getY() <= this->y + this->h)
      return box->getY() - this->y;
    else
      return this->y - (box->getY() + box->getH());
}
