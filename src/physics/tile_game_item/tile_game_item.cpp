#include "tile_game_item.h"

TileGameItem::TileGameItem(Renderer* ren, std::vector<AABB*> &boxes) : AABBGameItem(ren, boxes)
{
  xVel = 0;
  yVel = 0;
}
