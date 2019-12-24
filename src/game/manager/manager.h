#ifndef MANAGER
#define MANAGER

#include <vector>
#include "game_object.h"

class Manager : public GameObject
{
public:
  virtual void update();
  virtual void draw();
  GameObject* getObject(int);
  int objectsSize() {return objects.size();}
protected:
  Manager();
  ~Manager();

  void removeObjects();
  std::vector<GameObject*> objects;
};

#endif
