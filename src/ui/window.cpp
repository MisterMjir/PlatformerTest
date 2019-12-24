#include "window.h"

Window::Window(const char* title, int x, int y, int width, int height, bool fullScreen)
{
  int flags = 0;

  if (fullScreen)
    flags = SDL_WINDOW_FULLSCREEN;

  window = SDL_CreateWindow(title, x, y, width, height, flags);
  // SDL_SetWindowResizable(window, SDL_TRUE);
  // NOTE: Create a window icon
}

Window::~Window()
{
  // SDL_DestroyWindow(window); According to Valgrind using this increases lost memory
}

SDL_Window* Window::getWindow()
{
  return window;
}
