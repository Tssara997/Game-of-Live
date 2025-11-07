#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Position.h"

class Grid
{
private:
	static constexpr size_t defGridSize = 30;
protected:
	std::vector<Position> positionsToChange;
	bool grid[defGridSize][defGridSize];

	void createGrid();
	void loadWzorSerce();
	void rules(size_t x, size_t y);
public:
	int wzorSerce[10][2];

	Grid();
	~Grid() = default;
	void draw() const;
	void checkForUpdates();
	void update();

};

