#pragma once

struct Position {
	int x, y;

	bool operator==(const Position& other) {
		return x == other.x && y == other.y;
	}
};