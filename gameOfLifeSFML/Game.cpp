#include "Game.h" 




Game::Game() 
{
	size.x = width;
	size.y = height;
	cellSize.x = sizeOfCells;
	cellSize.y = sizeOfCells; 
	gridSize.x = width / sizeOfCells; 
	gridSize.y = height / sizeOfCells;
} 


//Settings
float Game::sizeOfCells = 10;
int Game::width = 800;
int Game::height = 600;
