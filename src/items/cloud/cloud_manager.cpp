#include "cloud_manager.h"
#include "cloud.h"

CloudManager::CloudManager(Renderer* ren) : ItemManager(ren)
{
  ticks = 0;
}

void CloudManager::update()
{
  ticks++;
  if (ticks % 25 == 0)
  {
    Cloud* cloud = new Cloud("", renderer);
    objects.push_back(cloud);
  }
  for (int i = objects.size() - 1; i >= 0; i--)
  {
    objects.at(i)->update();
    if (dynamic_cast<Cloud*>(objects.at(i))->offScreen())
    {
      delete objects.at(i);
      objects.erase(objects.begin() + i);
    }
  }
}
