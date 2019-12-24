#include "aabb_game_item.h"

AABBGameItem::AABBGameItem(const char* texturesheet, Renderer* ren, std::vector<AABB*> boxes) : GameItem(texturesheet, ren)
{
  for (auto box : boxes)
    this->boxes.push_back(box);
}

AABBGameItem::~AABBGameItem()
{
  for (auto box : boxes)
    delete box;
  boxes.clear();
}

void AABBGameItem::addBox(int x, int y, int w, int h, bool collision, bool hit, bool hurt)
{
  AABB* box = new AABB(x, y, w, h, collision, hit, hurt);
  boxes.push_back(box);
}
