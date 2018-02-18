#pragma once
#include "SFML\System.hpp"




class Game
{
public:
	static float sizeOfCells;
	static int width;
	static int height;
	sf::Vector2<int> size; 
	sf::Vector2f cellSize; 
	sf::Vector2<int> gridSize;
	
	Game();
};

