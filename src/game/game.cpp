#include "game.h"
#include "constants.h"
#include "camera.h"
#include "texture_manager.h"
#include <iostream>

bool Game::running;
Window* Game::window;
Renderer* Game::renderer;
ManagerManager* Game::manager;
GameInput Game::inputs = {false, false, false, false};
Camera Game::camera = Camera();
SDL_Texture* Game::texture;

void Game::init(const char* title, int x, int y, int width, int height, bool fullScreen)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    window = new Window(title, x, y, width, height, fullScreen);
    renderer = new Renderer(window->getWindow());
    texture = TextureManager::loadTexture(".res/images/spritesheet.png", renderer);
    manager = new ManagerManager(renderer);
    running = true;
  }
  else
  {
    running = false;
  }
}

void Game::close()
{
  delete window;
  delete renderer;
  SDL_DestroyTexture(texture);
  delete manager;

  SDL_Quit();
}

void Game::input()
{
  SDL_Event e;
  SDL_PollEvent(&e);
  switch (e.type)
  {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      switch (e.key.keysym.sym)
      {
        case SDLK_LEFT:
          inputs.left = true;
          break;
        case SDLK_RIGHT:
          inputs.right = true;
          break;
        case SDLK_UP:
          inputs.up = true;
          break;
        case SDLK_DOWN:
          inputs.down = true;
          break;
      }
      break;
    case SDL_KEYUP:
      switch (e.key.keysym.sym)
      {
        case SDLK_LEFT:
          inputs.left = false;
          break;
        case SDLK_RIGHT:
          inputs.right = false;
          break;
        case SDLK_UP:
          inputs.up = false;
          break;
        case SDLK_DOWN:
          inputs.down = false;
          break;
      }
      break;
  }
}

void Game::update()
{
  manager->update();
  GameStates::updateState();
}

void Game::draw()
{
  renderer->setDrawColor(0x00, 0x99, 0xdb, 255);
  renderer->clear();

  manager->draw();

  renderer->present();
}

bool Game::isRunning()
{
  return running;
}
