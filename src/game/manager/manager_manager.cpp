#include "manager_manager.h"
#include "cloud_manager.h"
#include "component_manager.h"
#include "tile_manager.h"

ManagerManager::ManagerManager(Renderer* renderer)
{
  CloudManager* cloudM = new CloudManager(renderer);
  objects.push_back(cloudM);
  ComponentManager* componentM = new ComponentManager(renderer);
  objects.push_back(componentM);
  TileManager* tileM = new TileManager(renderer);
  objects.push_back(tileM);
}

ManagerManager::~ManagerManager()
{

}
