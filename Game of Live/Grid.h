#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Position.h"

class Grid
{
private:
	static constexpr size_t defGridSizeX = 30;
	static constexpr size_t defGridSizeY = 30;
protected:
	std::vector<Position> positionsToChange;
	bool** grid;
	// moze byc zle indeksy gridSizeX i gridSizeX
	const size_t gridSizeX;
	const size_t gridSizeY;
	size_t wzorSerce[10][2];

	void createGrid();
	void loadWzorSerce();
	void rules(int x, int y);
	bool validPosition(int x, int y) const;
public:
	Grid(size_t gridSizeX = defGridSizeX, size_t gridSizeY = defGridSizeY);
	~Grid();
	void draw() const;
	void checkForUpdates();
	void update();

};

