cmake_minimum_required(VERSION 3.10)

# Project Name
project(platformer)

# Create executable
add_executable(platformer
  src/main.cpp

  src/game/game_item.cpp
  src/game/game_states.cpp
  src/game/game.cpp

  src/game/manager/item_manager.cpp
  src/game/manager/manager_manager.cpp
  src/game/manager/manager.cpp

  src/items/cloud/cloud_manager.cpp
  src/items/cloud/cloud.cpp
  src/items/tile/tile_manager.cpp
  src/items/tile/tile.cpp

  src/physics/aabb_game_item.cpp
  src/physics/aabb.cpp
  src/physics/camera.cpp

  src/ui/renderer.cpp
  src/ui/window.cpp

  src/ui/components/component_manager.cpp
  src/ui/components/ui_component.cpp

  src/utilities/texture_manager.cpp
)
target_include_directories(platformer PUBLIC
  src
  src/game
  src/game/manager
  src/items/cloud
  src/items/tile
  src/physics
  src/ui
  src/ui/components
  src/ui/components/button
  src/utilities
)
target_link_libraries(platformer SDL2 SDL2_image)
set_target_properties(platformer PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin)
