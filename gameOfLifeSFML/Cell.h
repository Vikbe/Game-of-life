#pragma once
#include "Game.h" 
#include "SFML\Graphics.hpp" 

class Cell
{
public:
	
	bool isAlive;
	sf::Vector2<int> position; 
	sf::RectangleShape bounds;

	Cell(sf::Vector2<int> p, const Game& game);


	void update(sf::RenderWindow& window);
	

	void draw(sf::RenderWindow& window);
	
};