#ifndef AABB_GAME_ITEM
#define AABB_GAME_ITEM

#include "game_item.h"
#include "aabb.h"
#include <vector>

class AABBGameItem : public GameItem
{
public:
  AABBGameItem(Renderer*, std::vector<AABB*> &);
  ~AABBGameItem();
  void changeX(int);
  void changeY(int);
  void addBox(int x, int y, int w, int h, AABB_Type, bool linked);
  std::vector<AABB*> boxes;
};

#endif
