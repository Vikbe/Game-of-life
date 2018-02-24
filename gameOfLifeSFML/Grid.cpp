#include "Grid.h" 


Grid::Grid(Game game)
	:size(game.gridSize), game(game)
{
	cells.resize(size.x, vector<Cell>());
	nextCellState.resize(size.x, vector<bool>(size.y, false));

	for (int x = 0; x < size.x; x++)
		for (int y = 0; y < size.y; y++) {
			cells[x].push_back(Cell(sf::Vector2<int>(x, y), game));
		}
}

void Grid::setNextState()
{
	for (int x = 0; x < size.x; x++)
		for (int y = 0; y < size.y; y++) {
			cells[x][y].isAlive = nextCellState[x][y];
		}
}

void Grid::update(sf::RenderWindow& window, sf::Clock& time)
{
	for (int x = 0; x < size.x; x++)
		for (int y = 0; y < size.y; y++) {
			cells[x][y].update(window);

		}

	sf::Time elapsed = time.getElapsedTime();
	sf::Int32 msec = elapsed.asMilliseconds();

	if (msec >= 75)
	{
		for (int x = 0; x < size.x; x++)
		{
			for (int y = 0; y < size.y; y++)
			{
				bool living = cells[x][y].isAlive;
				int count = getLivingNeighbors(x, y);
				bool result = false;


				if (living && count < 2)
					result = false;
				if (living && (count == 2 || count == 3))
					result = true;
				if (living && count > 3)
					result = false;
				if (!living && count == 3)
					result = true;


				nextCellState[x][y] = result;
			}
		}

		setNextState();
		time.restart();
	}

}

int Grid::getLivingNeighbors(int x, int y)
{
	int count = 0;

	// Check cell on the right.
	if (x != size.x - 1)
		if (cells[x + 1][y].isAlive)
			count++;

	// Check cell on the bottom right.
	if (x != size.x - 1 && y != size.y - 1)
		if (cells[x + 1][y + 1].isAlive)
			count++;

	// Check cell on the bottom.
	if (y != size.y - 1)
		if (cells[x][y + 1].isAlive)
			count++;

	// Check cell on the bottom left.
	if (x != 0 && y != size.y - 1)
		if (cells[x - 1][y + 1].isAlive)
			count++;

	// Check cell on the left.
	if (x != 0)
		if (cells[x - 1][y].isAlive)
			count++;

	// Check cell on the top left.
	if (x != 0 && y != 0)
		if (cells[x - 1][y - 1].isAlive)
			count++;

	// Check cell on the top.
	if (y != 0)
		if (cells[x][y - 1].isAlive)
			count++;

	// Check cell on the top right.
	if (x != size.x - 1 && y != 0)
		if (cells[x + 1][y - 1].isAlive)
			count++;

	return count;
}

void Grid::draw(sf::RenderWindow& window)
{
	for (int x = 0; x < size.x; x++)
		for (int y = 0; y < size.y; y++) {
			cells[x][y].draw(window);
		}

	for (int x = 0; x < size.x; x++)
	{
		sf::Vertex verticalLine[] =
		{
			sf::Vertex(sf::Vector2f(x * game.sizeOfCells, 0), sf::Color::Black),
			sf::Vertex(sf::Vector2f(x * game.sizeOfCells, game.height), sf::Color::Black)
		};

		window.draw(verticalLine, 2, sf::Lines);
	}


	for (int y = 0; y < size.y; y++)
	{
		sf::Vertex Horizontalline[] =
		{
			sf::Vertex(sf::Vector2f(0, y * game.sizeOfCells), sf::Color::Black),
			sf::Vertex(sf::Vector2f(game.width, y * game.sizeOfCells), sf::Color::Black)
		};

		window.draw(Horizontalline, 2, sf::Lines);
	}


}