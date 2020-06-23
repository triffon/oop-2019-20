#pragma once

struct Vec2D {
	float x, y;

	Vec2D& operator+=(const Vec2D& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
};