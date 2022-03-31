
#include <iostream>
#include"Engine/Engine.h"

int main(int argc, char* args[]) {

	Engine& engine = Engine::get();
	engine.init();
	while (engine.isRunning())
	{
		engine.events();
		engine.update();
		engine.render();

	}
	engine.clean();
	return 0;


}