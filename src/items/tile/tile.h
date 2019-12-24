#ifndef TILE
#define TILE

#include <SDL2/SDL.h>
#include "aabb_game_item.h"
#include "renderer.h"
#include <vector>
#include "item_manager.h"

class Tile : public AABBGameItem
{
public:
  Tile(const char* texture, Renderer*, SDL_Rect srcRect, SDL_Rect destRect, std::vector<AABB*>, std::vector<ItemManager*>);
  ~Tile();
  void update();
private:
  std::vector<ItemManager*> aabbObjects;
};

#endif
