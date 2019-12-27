#ifndef TILE_MANAGER
#define TILE_MANAGER

#include "item_manager.h"
#include "renderer.h"
#include "tile.h"
#include <vector>
#include <deque>
#include <string>

class TileManager : public ItemManager
{
public:
  TileManager(Renderer*);
  ~TileManager();
  void update();
  void draw();
  void loadMap(const std::string &);

  std::deque<Tile*> onScreen;
  std::deque<Tile*> n, s, w, e; // look at std::deque
private:
  void linkTiles(int rows, int cols);
  void setTiles(int rows, int cols);
  void manageTiles();
  // Go into the screen
  void goInN();
  void goInS();
  void goInE();
  void goInW();
};

#endif
