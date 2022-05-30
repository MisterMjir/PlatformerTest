#include "player_manager.h"
#include "game.h"
#include "constants.h"

static int divideFactor = 2;

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
      AABB* box1 = new AABB(280 + ((TILE_WIDTH / divideFactor) / 2), 80, TILE_WIDTH - (TILE_WIDTH / divideFactor), TILE_HEIGHT, COLLISIONBOX, true);
      AABB* box2 = new AABB(280, 80 + ((TILE_HEIGHT / divideFactor) / 2), TILE_WIDTH, TILE_HEIGHT - (TILE_HEIGHT / divideFactor), COLLISIONBOX, true);
      boxes.push_back(box1);
      boxes.push_back(box2);
      Player* player = new Player(renderer, boxes);
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
