
#include "Game.h" 
#include "Grid.h"
#include "SFML\Window.hpp"  
#include "SFML\Graphics.hpp" 
#include <iostream>


int main()
{
	//Load settings
	Game game;
	
	
	
	sf::RenderWindow window(sf::VideoMode(game.width, game.height), "Game of life");
	
	window.setFramerateLimit(60);
	sf::Clock clock;
	Grid grid(game);
	while (window.isOpen())
	{
		sf::Event event; 

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		} 

		
		
		window.clear(sf::Color::White); 

		
		
		grid.update(window, clock);
		grid.draw(window); 
		

		window.display();
	}
	return 0; 
}