#ifndef BUTTON
#define BUTTON

#include <SDL2/SDL.h>
#include "ui_component.h"
#include "renderer.h"

enum ButtonState {ANIMATE, NEUTRAL, HOVER};

class Button : public UIComponent
{
public:
  // Constructor
  Button(const char* texturesheet, Renderer*, SDL_Rect startPos, SDL_Rect endPos);
  Button(const char* texturesheet, Renderer*, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*));
  Button(const char* texturesheet, Renderer*, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*), void (*hoverHandler)(Button*));

  void update();

  void setClickHandler(void (*clickHandler)(Button*));
  void setHoverHandler(void (*hoverHandler)(Button*));
  bool focused();
  void setDestRect(SDL_Rect);

  void setColor(Uint8 r, Uint8 g, Uint8 b);
private:
  ButtonState state;
  // Events
  void (*onClick)(Button*);
  void (*onHover)(Button*);
  SDL_Rect myPos;
  unsigned int ticks;
};

#endif
