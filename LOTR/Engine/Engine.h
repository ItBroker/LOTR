#pragma once
#include "../AssetManager/AssetManager.h"
#include "../ECS/EntityManager.h"
#include <vector>
#include "../ECS/RigidBody.h"
#include "../ECS/SpriteRenderer.h"
#include "SDL.h"
class BoxCollider2D;
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr SDL_Color DARK = {30, 30, 30, 255};
class Engine {
public:
  Engine();
  ~Engine();
  void quit();
  void init();
  void clean();

  void render();
  void update();

  void events();

  inline static Engine &get() {
    if (s_instance == nullptr) {
      s_instance = new Engine();
    }
    return *s_instance;
  }
  inline bool isRunning() { return running; }
  inline SDL_Renderer *getRenderer() { return renderer; }
  static void AddTile(int id, int x, int y);
  static SDL_Event event;
  static SDL_Renderer* renderer;
  static vector<BoxCollider2D*> colliders;
  static EntityManager* manager;
  static SpriteRenderer* sprite;
private:
 
  bool running;
  SDL_Window *window;
  SDL_Color clearColor;
 
  static Engine *s_instance;
};
