#pragma once
#include "../Game.h"
#include "Component.h"
#include "ECS.h"

class KeyboardController : public Component {
public:
	SpriteComponent* sprite;
	TransformComponent* transform;
	void init() override  {
    transform = &entity->getComponent<TransformComponent>();
	sprite = &entity->getComponent<SpriteComponent>();
 
  }

  void update() override  {
     
	  /*const Uint8* keystates = SDL_GetKeyboardState(NULL);
	  if (Game::event.type == SDL_QUIT) Game::isRunning = false;
	  if (keystates[SDL_SCANCODE_ESCAPE]) Game::isRunning = false;
	  if (keystates[SDL_SCANCODE_W])
	  {
		  transform->velocity.y = -1;
		  sprite->Play("Walk");
	  }
		 
	  if (keystates[SDL_SCANCODE_A]) 
	  {
		  transform->velocity.x = -1;
		  sprite->Play("Walk");
		  sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
	  }
	  if (keystates[SDL_SCANCODE_D])
	  {
		  transform->velocity.x = 1;
		  sprite->Play("Walk");
	  }
	  if (keystates[SDL_SCANCODE_S])
	  {
		  transform->velocity.y = 1;
		  sprite->Play("Walk");
	  }*/
		  
	  if (Game::event.type == SDL_KEYDOWN)
	  {
		  switch (Game::event.key.keysym.sym)
		  {
		  case SDLK_w:
			  sprite->Play("Walk");
			  transform->velocity.y = -1;
			  
			  break;
		  case SDLK_a:
			  sprite->Play("Walk");
			  transform->velocity.x = -1;
			  sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
			  break;
		  case SDLK_d:
			  sprite->Play("Walk");
			  transform->velocity.x = 1;
			  
			  
			  break;
		  case SDLK_s:
			  sprite->Play("Walk");
			  transform->velocity.y = 1;
			  
			  break;
		  default:
			  break;
		  }
	  }

	  if (Game::event.type == SDL_KEYUP)
	  {
		  switch (Game::event.key.keysym.sym)
		  {
		  case SDLK_w:
			  sprite->Play("Idle");
			  transform->velocity.y = 0;
			  
			  break;
		  case SDLK_a:
			  sprite->Play("Idle");
			  transform->velocity.x = 0;
			  
			  sprite->spriteFlip = SDL_FLIP_NONE;
			  break;
		  case SDLK_d:
			  sprite->Play("Idle");
			  transform->velocity.x = 0;
			 
			  break;
		  case SDLK_s:
			  sprite->Play("Idle");
			  transform->velocity.y = 0;
			  
			  break;
		  case SDLK_ESCAPE:
			  Game::isRunning = false;
		  default:
			  break;
		  }
	  }
      
        
      
    
  }
private:
 
    
};
