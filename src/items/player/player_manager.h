#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "player.h"

class PlayerManager : public ItemManager
{
public:
  PlayerManager(Renderer*);
  ~PlayerManager();
  void update();
  Player* getPlayer(int index);
};

#endif
