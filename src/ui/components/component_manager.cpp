#include "component_manager.h"
#include "button_manager.h"

ComponentManager::ComponentManager(Renderer* ren)
{
  ButtonManager* buttonM = new ButtonManager(ren);
  objects.push_back(buttonM);
}

ComponentManager::~ComponentManager()
{

}
