#include "tile.h"
#include "game.h"
#include "player_manager.h"
#include "aabb_game_item.h"
#include <iostream>

Tile::Tile(const char* texture, Renderer* ren, SDL_Rect srcRect, SDL_Rect destRect, std::vector<AABB*> boxes, std::vector<ItemManager*> objLists) : AABBGameItem(texture, ren, boxes)
{
  this->srcRect = srcRect;
  this->destRect = destRect;
  aabbObjects = objLists;
}

Tile::~Tile()
{

}

void Tile::update()
{
  for (auto list : aabbObjects)
  {
    for (int i = 0; i < list->objectsSize(); i++)
    {
      AABBGameItem* boxObj = (AABBGameItem*) list->getObject(i);
      if (boxes.at(0)->yCollision(boxObj->boxes.at(0)))
      {
        int change = boxes.at(0)->yDiff(boxObj->boxes.at(0));
        boxObj->boxes.at(0)->changeY(change);
        boxObj->boxes.at(1)->changeY(change);
      }
      if (boxes.at(0)->xCollision(boxObj->boxes.at(1)))
      {
        int change = boxes.at(0)->xDiff(boxObj->boxes.at(1));
        boxObj->boxes.at(0)->changeX(change);
        boxObj->boxes.at(1)->changeX(change);
      }
    }
  }
}
