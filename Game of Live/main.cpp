#include "Grid.h"

int main() {
	Grid g{60, 30};
	while (true) {
		g.draw();
		g.checkForUpdates();
		g.update();
	}
	
	return 0;
}