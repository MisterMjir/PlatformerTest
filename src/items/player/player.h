#ifndef PLAYER
#define PLAYER

#include <SDL2/SDL.h>
#include "aabb_game_item.h"
#include "renderer.h"

class Player : public AABBGameItem
{
public:
  Player(Renderer*, std::vector<AABB*> &boxes);
  ~Player();
  void update();
  void draw();
  void resetXVel() {xVel = 0;}
  void resetYVel(int change) {yVel = 0;change < 0 ? jumpAllowed = true : jumping = false;}
  void changeX(int);
  void changeY(int);
private:
  static int maxXVel;
  static int maxYVel;

  double xVel;
  double yVel;

  bool jumping;
  bool jumpAllowed;
};

#endif
