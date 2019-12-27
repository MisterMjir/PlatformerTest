#include "aabb_game_item.h"

AABBGameItem::AABBGameItem(Renderer* ren, std::vector<AABB*> &boxes) : GameItem(ren)
{
  boxes.swap(this->boxes);
}

AABBGameItem::~AABBGameItem()
{
  for (auto box : boxes)
    delete box;
  std::vector<AABB*>().swap(boxes);
}

void AABBGameItem::changeX(int change)
{
  for (auto box : boxes)
    if (box->isLinked())
      box->changeX(change);
}

void AABBGameItem::changeY(int change)
{
  for (auto box : boxes)
    if (box->isLinked())
      box->changeY(change);
}

void AABBGameItem::addBox(int x, int y, int w, int h, AABB_Type type, bool linked)
{
  AABB* box = new AABB(x, y, w, h, type, linked);
  boxes.push_back(box);
}
