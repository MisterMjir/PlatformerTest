#include "tile_manager.h"
#include "game.h"
#include "game_states.h"
#include "constants.h"
#include "aabb.h"
#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

TileManager::TileManager(Renderer* ren, std::vector<ItemManager*> list) : ItemManager(ren)
{
  aabbObjects = list;
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
      Game::camera.set(TILE_WIDTH, TILE_HEIGHT);
      loadMap(".res/maps/0_0.txt");
    }
    else if (GameStates::getState() == GAME_OVER)
    {

    }
  }
  manageTiles();

  // Update Everything OnScreen
  for (auto obj : onScreen)
   obj->update();
}

void TileManager::draw()
{
  for (auto obj : onScreen)
   obj->draw();
}

static std::vector<std::string> seperateString(std::string str, std::string sepStr)
{
	std::vector<std::string> list;
	std::string word = "";

	// Get the args
	for (auto letter : str)
	{
		std::string strLetter(1, letter);
		if (strLetter.compare(sepStr) == 0)
		{
			list.push_back(word);
			word = "";
		}
		else
			word += letter;
	}
	list.push_back(word);

	return list;
}

void TileManager::loadMap(const std::string &loc)
{
  int rows = 0, cols = 0;
  int row = 0, col = 0;
  std::ifstream rFile;

  rFile.open(loc);
  if (rFile.is_open())
  {
    std::string output = "";
    while (!rFile.eof())
    {
      std::string tempChar;
      tempChar = rFile.get();
      if (!tempChar.compare(" "))
      {
        std::vector<std::string> data = seperateString(output, ":");
        output = "";

        AABB* box = new AABB(col * TILE_WIDTH, row * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, COLLISIONBOX, true);
        std::vector<AABB*> boxes(1, box);

        bool isDynamic = false;
        if (!data[1].compare("1"))
          isDynamic = true;

        Tile* tile = new Tile(renderer, boxes, std::stoi(data[0]), isDynamic, aabbObjects);
        objects.push_back(tile);

        col++;
      }
      else if (!tempChar.compare("\n"))
      {
        if (rows == 0 && cols == 0)
        {
          std::vector<std::string> data = seperateString(output, "x");
          output = "";
          cols = std::stoi(data[0]);
          rows = std::stoi(data[1]);
          removeObjects();
          objects.reserve(cols * rows);
        }
        else
        {
          std::vector<std::string> data = seperateString(output, ":");
          output = "";

          AABB* box = new AABB(col * TILE_WIDTH, row * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, COLLISIONBOX, true);
          std::vector<AABB*> boxes(1, box);

          bool isDynamic = false;
          if (!data[1].compare("1"))
            isDynamic = true;
          Tile* tile = new Tile(renderer, boxes, std::stoi(data[0]), isDynamic, aabbObjects);
          objects.push_back(tile);

          row++;
          col = 0;
        }
      }
      else
      {
        output += tempChar;
      }
    }
  }
  rFile.close();

  linkTiles(rows, cols);
  setTiles(rows, cols);
}

void TileManager::linkTiles(int rows, int cols)
{
  int index = 0;
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      // NOTE: This code can be simplified
      std::vector<Tile*> neighbors;
      neighbors.reserve(8);

      // n
      if (index / cols != 0)
        neighbors.push_back((Tile*) objects[index - cols]);
      else
        neighbors.push_back(NULL);

      // w
      if (index % cols != 0)
        neighbors.push_back((Tile*) objects[index - 1]);
      else
        neighbors.push_back(NULL);

      // e
      if (index % cols != cols - 1)
        neighbors.push_back((Tile*) objects[index + 1]);
      else
        neighbors.push_back(NULL);

      // s
      if (index / cols != rows - 1)
        neighbors.push_back((Tile*) objects[index + cols]);
      else
        neighbors.push_back(NULL);


      dynamic_cast<Tile*>(objects[index])->setNeighbors(neighbors);
      index++;
    }
  }
}

void TileManager::setTiles(int rows, int cols)
{
  int startX = Game::camera.getX() / TILE_WIDTH - 1;
  int startY = Game::camera.getY() / TILE_WIDTH - 1;
  int index = startX + (startY * X_TILES) + 1;

  for (int col = 0; col < X_TILES; col++)
  {
    n.push_back((Tile*) objects[index++]);
  }
  index = index + cols - X_TILES - 1;
  for (int row = 0; row < Y_TILES; row++)
  {
    w.push_back((Tile*) objects[index++]);

    for (int col = 0; col < X_TILES; col++)
    {
      onScreen.push_back((Tile*) objects[index++]);
    }

    e.push_back((Tile*) objects[index]);
    index = index + cols - X_TILES - 1;
  }
  for (int col = 0; col < X_TILES; col++)
  {
    s.push_back((Tile*) objects[++index]);
  }
}

void TileManager::manageTiles()
{
  // Manage what's OnScreen
  CAMERA_DIRECTION direction = Game::camera.getDirection();
  switch (direction)
  {
    case NORTH_WEST:
      goInN();
      goInW();
      break;
    case NORTH:
      goInN();
      break;
    case NORTH_EAST:
      goInN();
      goInE();
      break;
    case WEST:
      goInW();
      break;
    case EAST:
      goInE();
      break;
    case SOUTH_WEST:
      goInS();
      goInW();
      break;
    case SOUTH:
      goInS();
      break;
    case SOUTH_EAST:
      goInS();
      goInE();
      break;
    case NONE:
      break;
  }
}

void TileManager::goInN()
{
  if (n[0]->getNeighbors()[0] != NULL)
  {
    if (n[0]->getY() + TILE_HEIGHT > Game::camera.getY())
    {
      std::deque<Tile*> newN;
      for (int i = 0; i < n.size(); i++)
      {
        onScreen.push_back(n[i]);
        newN.push_back(n[i]->getNeighbors()[0]);
      }
      n.swap(newN);

      // West and East
      w.push_front(w[0]->getNeighbors()[0]);
      e.push_front(e[0]->getNeighbors()[0]);

      if (s[0]->getY() - (Game::camera.getY() + WINDOW_HEIGHT) >= TILE_WIDTH)
      {
        std::deque<Tile*> newS;
        for (int i = 0; i < s.size(); i++)
        {
          newS.push_back(s[i]->getNeighbors()[0]);
          onScreen.erase(std::remove(onScreen.begin(), onScreen.end(), s[i]->getNeighbors()[0]), onScreen.end());
        }
        s.swap(newS);

        // West and East
        w.pop_back();
        e.pop_back();
      }
    }
  }
}

void TileManager::goInS()
{
  if (s[0]->getNeighbors()[3] != NULL)
  {
    if (Game::camera.getY() + WINDOW_HEIGHT > s[0]->getY())
    {
      std::deque<Tile*> newS;
      for (int i = 0; i < s.size(); i++)
      {
        onScreen.push_back(s[i]);
        newS.push_back(s[i]->getNeighbors()[3]);
      }
      s.swap(newS);

      // West and East
      w.push_back(w.back()->getNeighbors()[3]);
      e.push_back(e.back()->getNeighbors()[3]);

      if (Game::camera.getY() - (n[0]->getY() + TILE_HEIGHT) >= TILE_WIDTH)
      {
        std::deque<Tile*> newN;
        for (int i = 0; i < n.size(); i++)
        {
          newN.push_back(n[i]->getNeighbors()[3]);
          onScreen.erase(std::remove(onScreen.begin(), onScreen.end(), n[i]->getNeighbors()[3]), onScreen.end());
        }
        n.swap(newN);

        // West and East
        w.pop_front();
        e.pop_front();
      }
    }
  }
}

void TileManager::goInE()
{
  if (e[0]->getNeighbors()[2] != NULL)
  {
    if (Game::camera.getX() + WINDOW_WIDTH > e[0]->getX())
    {
      std::deque<Tile*> newE;
      for (int i = 0; i < e.size(); i++)
      {
        onScreen.push_back(e[i]);
        newE.push_back(e[i]->getNeighbors()[2]);
      }
      e.swap(newE);

      // North and south
      n.push_back(n.back()->getNeighbors()[2]);
      s.push_back(s.back()->getNeighbors()[2]);

      if (Game::camera.getX() - (w[0]->getX() + TILE_WIDTH) >= TILE_WIDTH)
      {
        std::deque<Tile*> newW;
        for (int i = 0; i < w.size(); i++)
        {
          newW.push_back(w[i]->getNeighbors()[2]);
          onScreen.erase(std::remove(onScreen.begin(), onScreen.end(), w[i]->getNeighbors()[2]), onScreen.end());
        }
        w.swap(newW);

        // North and South
        n.pop_front();
        s.pop_front();
      }
    }
  }
}

void TileManager::goInW()
{
  if (w[0]->getNeighbors()[1] != NULL)
  {
    if (w[0]->getX() + TILE_WIDTH > Game::camera.getX())
    {
      std::deque<Tile*> newW;
      for (int i = 0; i < w.size(); i++)
      {
        onScreen.push_back(w[i]);
        newW.push_back(w[i]->getNeighbors()[1]);
      }
      w.swap(newW);

      // North and south
      n.push_front(n[0]->getNeighbors()[1]);
      s.push_front(s[0]->getNeighbors()[1]);

      if (e[0]->getX() - (Game::camera.getX() + WINDOW_WIDTH) >= TILE_WIDTH)
      {
        std::deque<Tile*> newE;
        for (int i = 0; i < e.size(); i++)
        {
          newE.push_back(e[i]->getNeighbors()[1]);
          onScreen.erase(std::remove(onScreen.begin(), onScreen.end(), e[i]->getNeighbors()[1]), onScreen.end());
        }
        e.swap(newE);

        // North and South
        n.pop_back();
        s.pop_back();
      }
    }
  }
}
