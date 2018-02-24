#pragma once
#include <vector> 
#include "Cell.h"
#include "Game.h" 
#include "SFML\Window.hpp"  
#include "SFML\Graphics.hpp"  
#include <iostream>

using namespace std;

class Grid
{
public: 
	
	sf::Vector2<int> size; 
	vector<vector<Cell>> cells;
	vector<vector<bool>> nextCellState; 
	Game game;
	
	Grid(Game game); 
	void setNextState(); 
	void update(sf::RenderWindow& window, sf::Clock& time);  
	int getLivingNeighbors(int x, int y); 
	void draw(sf::RenderWindow& window);

};