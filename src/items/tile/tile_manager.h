#ifndef TILE_MANAGER
#define TILE_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "tile.h"
#include <vector>

class TileManager : public ItemManager
{
public:
  TileManager(Renderer*, std::vector<ItemManager*>);
  ~TileManager();
  void update();
private:
  std::vector<ItemManager*> aabbObjects;
};

#endif
