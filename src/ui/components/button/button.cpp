#include "button.h"
#include <SDL2/SDL.h>
#include <cmath>
#include "game.h"
#include <iostream>

void nullClick(Button*) {}
void nullHover(Button*) {}

Button::Button(const char* texturesheet, Renderer* renderer, SDL_Rect startPos, SDL_Rect endPos) : UIComponent(texturesheet, renderer)
{
  state = ANIMATE;
  srcRect = {0, 0, 32, 16};
  destRect = startPos;
  myPos = endPos;
  onClick = nullClick;
  onHover = nullHover;
}

Button::Button(const char* texturesheet, Renderer* renderer, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*)) : UIComponent(texturesheet, renderer)
{
  state = ANIMATE;
  srcRect = {0, 0, 32, 16};
  destRect = startPos;
  myPos = endPos;
  onClick = clickHandler;
  onHover = nullHover;
}

Button::Button(const char* texturesheet, Renderer* renderer, SDL_Rect startPos, SDL_Rect endPos, void (*clickHandler)(Button*), void (*hoverHandler)(Button*)) : UIComponent(texturesheet, renderer)
{
  state = ANIMATE;
  srcRect = {0, 0, 32, 16};
  destRect = startPos;
  myPos = endPos;
  onClick = clickHandler;
  onHover = hoverHandler;
}

void Button::update()
{
  myPos.x = Game::inputs.winW / 2 - 32;
  myPos.y = Game::inputs.winH * 2 / 3 - 16;
  switch (state)
  {
    case ANIMATE:
    {
      // Create a function for these two sections
      double xInc = (myPos.x - destRect.x) / 8.0;
      if (xInc > 0)
        xInc = std::ceil(xInc);
      else
        xInc = std::floor(xInc);
      destRect.x += xInc;

      double yInc = (myPos.y - destRect.y) / 8.0;
      if (yInc > 0)
        yInc = std::ceil(yInc);
      else
        yInc = std::floor(yInc);
      destRect.y += yInc;

      if ((destRect.x == myPos.x) && (destRect.y == myPos.y))
        state = NEUTRAL;

      break;
    }
    case NEUTRAL:
      {
        int range = 4;
        double compression = 0.25;
        destRect.y = myPos.y + (std::sin(compression * ticks) * range);
        if (focused())
        {
          state = HOVER;
        }
        else if (!((destRect.x == myPos.x) && (destRect.y <= myPos.y + range && destRect.y >= myPos.y - range)))
        {
          state = ANIMATE;
        }
        ticks++;
        break;
    }
    case HOVER:
    {
      onHover(this);
      if (Game::inputs.mouseButtonLeft)
      {
        onClick(this);
      }
      if (!focused())
      {
        destRect = myPos;
        state = NEUTRAL;
      }
    }
  }
}

void Button::setClickHandler(void (*clickHandler)(Button*))
{
  onClick = clickHandler;
}

void Button::setHoverHandler(void (*hoverHandler)(Button*))
{
  onHover = hoverHandler;
}

bool Button::focused()
{
  return (Game::inputs.mouseX >= myPos.x &&
          Game::inputs.mouseX <= myPos.x + destRect.w &&
          Game::inputs.mouseY >= myPos.y &&
          Game::inputs.mouseY <= myPos.y + destRect.h);
}

void Button::setColor(Uint8 r, Uint8 g, Uint8 b)
{
  SDL_SetTextureColorMod(texture, r, g, b);
}
