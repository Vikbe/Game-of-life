#include "Cell.h" 
#include <iostream>






Cell::Cell(sf::Vector2<int> p, const Game& game)
	: position(p)
{
		position = p;
		bounds.setSize(game.cellSize);
		bounds.setPosition(position.x * game.sizeOfCells, position.y * game.sizeOfCells);
		isAlive = false;
}

void Cell::update(sf::RenderWindow& window)
{
	if (bounds.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
	{
		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//std::cout << position.x << position.y; 
			isAlive = true; 
			
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			isAlive = false; 
			
		}
			

	}
}

void Cell::draw(sf::RenderWindow& window)
{
	if (isAlive) {
		bounds.setFillColor(sf::Color::Black); 
	} 
	else {
		bounds.setFillColor(sf::Color::White);
	}
		
		
	window.draw(bounds);
}
