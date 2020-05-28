#include <iostream>
#include "Maze.h"

int main() {
	Maze maze;
	maze.init();
	while (true) {
		system("cls");
		maze.render();
		maze.update();
	}
}