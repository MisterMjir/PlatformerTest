#ifndef CLOUDMANAGER
#define CLOUDMANAGER

#include "item_manager.h"
#include "renderer.h"

class CloudManager : public ItemManager
{
public:
  CloudManager(Renderer*);

  void update();
private:
  int ticks;
};

#endif
