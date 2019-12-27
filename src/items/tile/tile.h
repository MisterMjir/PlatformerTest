#ifndef TILE
#define TILE

#include "aabb_game_item.h"
#include <vector>

class Tile : public AABBGameItem
{
public:
  Tile(Renderer*, std::vector<AABB*> &, int id, bool dynamic);
  bool isDynamic() {return dynamic;}
  void update();
  void setNeighbors(std::vector<Tile*> &);
  int getX() {return destRect.x;}
  int getY() {return destRect.y;}
  std::vector<Tile*> getNeighbors() {return neighbors;}
private:
  int id;
  bool dynamic;
  std::vector<Tile*> neighbors; // n, w, e, s
};

#endif
