#include "Grid.h"

int main() {
	Grid g{};
	while (true) {
		g.draw();
		g.checkForUpdates();
		g.update();
	}
	
	return 0;
}