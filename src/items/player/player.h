#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>
#include "aabb_game_item.h"
#include "renderer.h"

class Player : public AABBGameItem
{
public:
  Player(const char* texture, Renderer*, std::vector<AABB*> boxes);
  ~Player();
  void update();
  void draw();
private:
  void moveX(int);
  void moveY(int);
};

#endif
