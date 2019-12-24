#ifndef AABB_GAME_ITEM
#define AABB_GAME_ITEM

#include "game_item.h"
#include "aabb.h"
#include <vector>

class AABBGameItem : public GameItem
{
public:
  AABBGameItem(const char* texturesheet, Renderer*, std::vector<AABB*>);
  ~AABBGameItem();
  void addBox(int x, int y, int w, int h, bool collision, bool hit, bool hurt);
  std::vector<AABB*> boxes;
};

#endif
