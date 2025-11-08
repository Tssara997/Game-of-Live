#include "Grid.h"

Grid::Grid(size_t gridSizeX, size_t gridSizeY) : gridSizeX{defGridSizeX}, gridSizeY{defGridSizeY}
{
	grid = new bool* [gridSizeY];
	loadWzorSerce();
	createGrid();	
}

Grid::~Grid()
{
	if (defGridSizeY) delete[] grid[0];
	delete[] grid;
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
	for (size_t i{}; i < gridSizeX; i++) {
		grid[i] = new bool[gridSizeX*gridSizeY];
		for (size_t j{}; j < gridSizeY; j++) {
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

void Grid::rules(int x, int y)
{
	int neighbourPopulation{};

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i != 0 || j != 0) && x + i >= 0 && validPosition(x+i, y+j)) {
				neighbourPopulation += grid[i + x][j + y];
			}
		}
	}

	bool isLive = grid[x][y];

	if ((isLive && neighbourPopulation < 2) ||  // underpopulation
		(isLive && neighbourPopulation > 3) ||  // overpopulation
		(!isLive && neighbourPopulation == 3)) { // reproduction
		positionsToChange.push_back(Position{size_t(x), size_t(y), isLive});
	}
}

bool Grid::validPosition(int x, int y) const
{
	return x >=0 && x < gridSizeX && y >= 0 && y < gridSizeY;
}

void Grid::draw() const
{
	for (size_t i{}; i < gridSizeX; i++) {
		for (size_t j{}; j < gridSizeY; j++) {
			char rysuj = grid[i][j] ? grid[i][j] + 48 : ' ';
			std::cout << rysuj << ' ';
		}
		std::cout << "\n";
	}
}

void Grid::checkForUpdates()
{
	for (size_t i{}; i < gridSizeX; i++) {
		for (size_t j{}; j < gridSizeY; j++) {
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
