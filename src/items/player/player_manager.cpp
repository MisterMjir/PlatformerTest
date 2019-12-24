#include "player_manager.h"
#include "game.h"

PlayerManager::PlayerManager(Renderer* ren) : ItemManager(ren)
{

}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::update()
{
  // Handle object creation and deletion
  if (GameStates::getFirstTick())
  {
    removeObjects();
    if (GameStates::getState() == GAME_MENU)
    {

    }
    else if (GameStates::getState() == GAME_GAME)
    {
      std::vector<AABB*> boxes;
      AABB* box1 = new AABB(282, 80, 28, 32, true, false, false);
      AABB* box2 = new AABB(280, 82, 32, 28, true, false, false);
      boxes.push_back(box1);
      boxes.push_back(box2);
      Player* player = new Player(".res/images/musgrave.png", renderer, boxes);
      objects.push_back(player);
    }
    else if (GameStates::getState() == GAME_OVER)
    {

    }
  }
  Manager::update(); // Call the update of every object
}

Player* PlayerManager::getPlayer(int index)
{
  return (Player*) objects.at(0);
}
