#include "manager_manager.h"
#include "cloud_manager.h"
#include "component_manager.h"
#include "tile_manager.h"
#include "player_manager.h"
#include "item_manager.h"
#include <vector>

ManagerManager::ManagerManager(Renderer* renderer)
{
  CloudManager* cloudM = new CloudManager(renderer);
  objects.push_back(cloudM);
  ComponentManager* componentM = new ComponentManager(renderer);
  objects.push_back(componentM);
  PlayerManager* playerM = new PlayerManager(renderer);
  objects.push_back(playerM);

  std::vector<ItemManager*> aabbObjs;
  aabbObjs.push_back(playerM);
  TileManager* tileM = new TileManager(renderer, aabbObjs);
  objects.push_back(tileM);
}

ManagerManager::~ManagerManager()
{

}
