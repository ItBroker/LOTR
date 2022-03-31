#pragma once
#include "../Engine/Engine.h"
#include "Component.h"
#include "Entity.h"

class KeyboardController : public Component {
public:
  bool init() override final {
    transform = &entity->getComponent<Transform>();
    
    return true;
  }

  void update() override  {
     
     
         
          if (Engine::event.type == SDL_KEYDOWN) {
              cout << "Ok" << endl;
              switch (Engine::event.key.keysym.sym) {
              case SDLK_w:

                  transform->velosity.y = -1;
                  break;
              case SDLK_a:
                  transform->velosity.x = -1;
                  break;
              case SDLK_d:
                  transform->velosity.x = 1;
                  break;
              case SDLK_s:
                  transform->velosity.y = 1;
                  break;
              default:
                  break;
              }
          }

          else if (Engine::event.type == SDL_KEYUP) {
              switch (Engine::event.key.keysym.sym) {
              case SDLK_w:
                  transform->velosity.y = 0;
                  break;
              case SDLK_a:
                  transform->velosity.x = 0;
                  break;
              case SDLK_d:
                  transform->velosity.x = 0;
                  break;
              case SDLK_s:
                  transform->velosity.y = 0;
                  break;
              default:
                  break;
              }
          }
      
        
      
    
  }
private:
 
    Transform* transform;
};
