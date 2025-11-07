#include "Grid.h"

Grid::Grid()
{
	loadWzorSerce();
	createGrid();	
}

void Grid::loadWzorSerce()
{
	std::ifstream serce ("serce.csv");
	size_t x{}, y{};
	int i{};
	while (serce >> x >> y) {
		wzorSerce[i][0] = x;
		wzorSerce[i][1] = y;
		i++;
	}

	serce.close();
}

void Grid::createGrid() {
	for (size_t i{}; i < defGridSize; i++) {
		for (size_t j{}; j < defGridSize; j++) {
			grid[i][j] = false;
			for (size_t test{}; test < 10; test++) {
				if (wzorSerce[test][1] == i && wzorSerce[test][0] == j) {
					grid[i][j] = true;
					break;
				}

			}
		}

	}
}

void Grid::rules(size_t x, size_t y)
{
	int neighbourPopulation{};

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i != 0 || j != 0) && (x + i >= 0 && y + j >= 0)) {
				neighbourPopulation += grid[i + x][j + y];
			}
		}
	}

	bool isLive = grid[x][y];

	if ((isLive && neighbourPopulation < 2) ||  // underpopulation
		(isLive && neighbourPopulation > 3) ||  // overpopulation
		(!isLive && neighbourPopulation == 3)) { // reproduction
		positionsToChange.push_back(Position{x, y, isLive});
	}
}

void Grid::draw() const
{
	//for (size_t i{}; i < defGridSize; i++) {
	//	for (size_t j{}; j < defGridSize; j++) {
	//		char rysuj = grid[i][j] ? grid[i][j] + 48 : ' ';
	//		std::cout << rysuj << ' ';
	//	}
	//	std::cout << "\n";
	//}
}

void Grid::checkForUpdates()
{
	for (size_t i{}; i < defGridSize; i++) {
		for (size_t j{}; j < defGridSize; j++) {
			rules(i, j);
		}
	}
}

void Grid::update()
{
	for (const auto& pos : positionsToChange) {
		grid[pos.x][pos.y] = !pos.val;
	}
	positionsToChange.clear();
}
