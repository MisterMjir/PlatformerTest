#ifndef COMPONENT_MANAGER
#define COMPONENT_MANAGER

#include "manager.h"
#include "renderer.h"

class ComponentManager : public Manager
{
public:
  ComponentManager(Renderer* ren);
  ~ComponentManager();
};

#endif
