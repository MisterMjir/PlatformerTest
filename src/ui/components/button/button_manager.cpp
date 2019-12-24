#include "button_manager.h"
#include "button.h"
#include "game.h"
#include "game_states.h"

void menuButtonOnClick(Button* button)
{
  GameStates::changeState(GAME_GAME);
}

void menuButtonOnHover(Button* button)
{

}

ButtonManager::ButtonManager(Renderer* ren) : ItemManager(ren)
{

}

ButtonManager::~ButtonManager()
{

}

void ButtonManager::update()
{
  // Handle object creation and deletion
  if (GameStates::getFirstTick())
  {
    removeObjects();
    if (GameStates::getState() == GAME_MENU)
    {
      Button* button = new Button("images/go_button.png", renderer, {Game::inputs.winW / 2 - 32, Game::inputs.winH, 64, 32}, {Game::inputs.winW / 2 - 32, Game::inputs.winH * 2 / 3 - 16, 64, 32}, menuButtonOnClick);
      objects.push_back(button);
    }
    else if (GameStates::getState() == GAME_GAME)
    {

    }
    else if (GameStates::getState() == GAME_OVER)
    {

    }
  }
  Manager::update(); // Call the update of every object
}
