#ifndef GAME
#define GAME

#include <SDL2/SDL.h>
#include "window.h"
#include "renderer.h"
#include "manager_manager.h"
#include "game_states.h"
#include "game_input.h"
#include "camera.h"

class Game
{
public:
  static void init(const char* title, int x, int y, int width, int height, bool fullScreen);
  static void close();

  static void input();
  static void update();
  static void draw();

  static bool isRunning();

  static SDL_Texture* getTexture() {return texture;}

  static GameInput inputs;
  static Camera camera;
private:
  Game();

  static bool running;
  static Window* window;
  static Renderer* renderer;
  static ManagerManager* manager;
  static SDL_Texture* texture;
};

#endif
