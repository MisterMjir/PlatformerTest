#include "tile.h"
#include "constants.h"
#include "player.h"

Tile::Tile(Renderer* ren, std::vector<AABB*> &boxes, int id, bool dynamic, std::vector<ItemManager*> lists) : AABBGameItem(ren, boxes)
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
  aabbObjects = lists;
}

void Tile::update()
{
  if (dynamic)
  {
    for (auto list : aabbObjects)
    {
      for (int i = 0; i < list->objectsSize(); i++)
      {
        AABBGameItem* boxObj = (AABBGameItem*) list->getObject(i);
        if (boxes.at(0)->yOverlap(boxObj->boxes.at(0)))
        {
          int change = boxes[0]->yDiff(boxObj->boxes.at(0));
          boxObj->changeY(change);
          if (change < 0)
            dynamic_cast<Player*>(boxObj)->resetYVel(change);
        }
        if (boxes.at(0)->xOverlap(boxObj->boxes.at(1)))
        {
          int change = boxes.at(0)->xDiff(boxObj->boxes.at(1));
          boxObj->changeX(change);
          dynamic_cast<Player*>(boxObj)->resetXVel();
        }
      }
    }
  }
}

void Tile::setNeighbors(std::vector<Tile*> &neighbors)
{
  neighbors.swap(this->neighbors);
}
