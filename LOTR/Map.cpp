#include "Map.h"
#include "Engine/Engine.h"
#include <fstream>





void Map::LoadMap(std::string path, int sixeX, int sizeY) {
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sixeX; x++)
		{
			mapFile.get(tile);
			{
				//cout << atoi(&tile) << endl;
				Engine::AddTile(atoi(&tile), x*128,y*64);
				mapFile.ignore();
			}
		}
	}

	mapFile.close();
};

