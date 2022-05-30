#ifndef TILE_GAME_ITEM
#define TILE_GAME_ITEM

#include "aabb_game_item.h"

// Must have at least two boxes, the first one for y collisions and the second one for x collisions

class TileGameItem : public AABBGameItem
{
public:
  TileGameItem(Renderer*, std::vector<AABB*> &);
  virtual void resetXVel(int change) {xVel = 0;}
  virtual void resetYVel(int change) {yVel = 0;}
protected:
  double xVel;
  double yVel;
};

#endif
