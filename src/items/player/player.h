#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>
#include "tile_game_item.h"
#include "renderer.h"

class Player : public TileGameItem
{
public:
  Player(Renderer*, std::vector<AABB*> &boxes);
  ~Player();
  void update();
  void draw();
  void resetXVel(int change) {xVel = 0;}
  void resetYVel(int change) {yVel = 0;change < 0 ? jumpAllowed = true : jumping = false;}
  void changeX(int);
  void changeY(int);
private:
  static int maxXVel;
  static int maxYVel;

  bool jumping;
  bool jumpAllowed;
};

#endif
