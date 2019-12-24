#include "tile_manager.h"
#include "game.h"
#include "game_states.h"
#include "constants.h"
#include "aabb.h"
#include <SDL2/SDL.h>

TileManager::TileManager(Renderer* ren, std::vector<ItemManager*> objLists) : ItemManager(ren)
{
  aabbObjects = objLists;
}

TileManager::~TileManager()
{

}

void TileManager::update()
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
      for (int row = 0; row < 3; row++)
      {
        for (int col = 0; col < 20; col++)
        {
          // There has to be a way to simplify this
          SDL_Rect destRect = {(WINDOW_WIDTH / 2 - TILE_SIZE * 2) + col * TILE_SIZE, (WINDOW_HEIGHT / 2 - TILE_SIZE * 2) + row * TILE_SIZE, TILE_SIZE, TILE_SIZE};
          SDL_Rect srcRect = {16, row * 16, 16, 16};
          if (col == 0)
            srcRect.x = 0;
          else if (col == 19)
            srcRect.x = 32;
          std::vector<AABB*> boxes;
          AABB* box = new AABB(destRect.x, destRect.y, destRect.w, destRect.h, true, false ,false);
          boxes.push_back(box);
          Tile* tile = new Tile(".res/images/tilemap.png", renderer, srcRect, destRect, boxes, aabbObjects);
          objects.push_back(tile);
        }
      }
    }
    else if (GameStates::getState() == GAME_OVER)
    {

    }
  }
  Manager::update(); // Call the update of every object
}
