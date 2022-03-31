#include "Engine.h"
#include <iostream>
#include "../ECS/KeyboardController.h"
#include "../ECS/TileComonent.h"
#include "../ECS/BoxCollider2D.h"
#include "../Collision/Collision.h"
#include "../Map.h"
Entity* player;
SpriteRenderer* Engine::sprite;
EntityManager* Engine::manager = new EntityManager();
auto& player1(Engine::manager->addEntity1());
Engine* Engine::s_instance = nullptr;
SDL_Event Engine::event;
SDL_Renderer* Engine::renderer = nullptr;
vector<BoxCollider2D*> Engine::colliders;
Map* map = new Map();

enum groupLabels : size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

Engine::Engine()
{
	running = false;
	window = nullptr;
	renderer = nullptr;
}

Engine::~Engine()
{
}

void Engine::quit()
{
	running = false;
}

void Engine::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL ERROR - %s\n", SDL_GetError());
	}
	auto wflags = (SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);
	window = SDL_CreateWindow("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, wflags);
	if (!window)
	{
		printf("SDL ERROR - %s\n", SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, -1, (SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	if (!renderer)
	{
		printf("SDL ERROR - %s\n", SDL_GetError());
	}
	AssetManager::get().loadTexture("Frodo","D:/C++/SDL/LOTR/LOTR/images/Charackters/Frodo_png.png");
	AssetManager::get().loadTexture("FrodoAnim", "D:/C++/SDL/LOTR/LOTR/images/Charackters/Frodo_Anim2.png");
	AssetManager::get().loadTexture("water", "D:/C++/SDL/LOTR/LOTR/images/Textures/TILES/water.png");
	AssetManager::get().loadTexture("dirt", "D:/C++/SDL/LOTR/LOTR/images/Textures/TILES/dirt.png");
	AssetManager::get().loadTexture("grass", "D:/C++/SDL/LOTR/LOTR/images/Textures/TILES/grass.png");
	
	
	
	player = new Entity(*manager);
	Map::LoadMap("D:/C++/SDL/LOTR/LOTR/images/Textures/TILES/pyxel_16x16.txt",16,16);
	player->addComponent<Transform>();
	player->addComponent<SpriteRenderer>(renderer, "Frodo");
	auto sprite = &player->getComponent<SpriteRenderer>();
	player->addComponent<BoxCollider2D>(renderer,sprite->getWidth(),sprite->getHeight(),"Frodo");
	player->addComponent<KeyboardController>();
	cout<<player->hasComponent<KeyboardController>()<<endl;
	player->addGroup(groupPlayers);
	

	
	clearColor = DARK;
	running = true; 
	
}

void Engine::clean()
{
	
	AssetManager::get().clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
auto& tiles(Engine::manager->getGroup(groupMap));
auto& players(Engine::manager->getGroup(groupPlayers));
void Engine::render()
{
	SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	SDL_RenderClear(renderer);
	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : players)
	{
		p->draw();
	}
	SDL_RenderPresent(renderer);
}

void Engine::update()
{

	manager->refresh();
	manager->update(); 
	player->getComponent<KeyboardController>().update();
	for(auto cc: colliders)
	{ 
		if (Collision::AABB(player->getComponent<BoxCollider2D>(), *cc));
	}
}
void Engine::AddTile(int id, int x, int y)
{
	Entity* tile = new Entity(*manager);
	tile->addComponent<TileComponent>(x, y,64,64, id);
	tile->addGroup(groupMap);
	manager->addEntity(tile);
}

void Engine::events()
{
	
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
		
	}
}
