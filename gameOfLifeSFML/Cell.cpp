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
		//std::cout << "The mouse is in bounds!";
		isAlive = true;
		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			isAlive = true;
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			isAlive = false;*/

	}
}

void Cell::draw(sf::RenderWindow& window)
{
	if (isAlive) {
		bounds.setFillColor(sf::Color::Blue); 
		std::cout << "drawing!";
	}
		
		
	window.draw(bounds);
}
