#include "tile.h"
#include "constants.h"
#include <iostream>

Tile::Tile(Renderer* ren, std::vector<AABB*> &boxes, int id, bool dynamic) : AABBGameItem(ren, boxes)
{
  this->id = id;
  this->dynamic = dynamic;
  switch (id)
  {
    case 0:
      srcRect = {0, 0, 0, 0};
      break;
    case 1:
      srcRect = {16, 16, 16, 16};
      break;
    case 2:
      srcRect = {16, 0, 16, 16};
  }
  destRect = {this->boxes.at(0)->getX(), this->boxes.at(0)->getY(), this->boxes.at(0)->getW(), this->boxes.at(0)->getH()};
}

void Tile::update()
{
  std::cout << "I am tile at " << destRect.x / TILE_WIDTH << ", " << destRect.y / TILE_HEIGHT << "\n";
}

void Tile::setNeighbors(std::vector<Tile*> &neighbors)
{
  neighbors.swap(this->neighbors);
}
