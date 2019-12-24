#include "game.h"
#include "constants.h"
#include "camera.h"

bool Game::running;
Window* Game::window;
Renderer* Game::renderer;
ManagerManager* Game::manager;
GameInput Game::inputs = {WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, false, false, false};

void Game::init(const char* title, int x, int y, int width, int height, bool fullScreen)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    window = new Window(title, x, y, width, height, fullScreen);
    renderer = new Renderer(window->getWindow());
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
    case SDL_WINDOWEVENT:
      switch (e.window.event)
      {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
          inputs.winW = e.window.data1;
          inputs.winH = e.window.data2;
          // std::cout << "Width: " << e.window.data1 << "\tHeight: " << e.window.data2 << "\n";
          break;
      }
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
          // Camera::changeY(-1);
          break;
        case SDLK_DOWN:
          // Camera::changeY(1);
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
          // Camera::changeY(-1);
          break;
        case SDLK_DOWN:
          // Camera::changeY(1);
          break;
      }
      break;
    case SDL_MOUSEBUTTONDOWN:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          inputs.mouseButtonLeft = true;
          break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          inputs.mouseButtonLeft = false;
          break;
      }
      break;
  }
  // Update mouse position
  SDL_GetMouseState(&inputs.mouseX, &inputs.mouseY);
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
