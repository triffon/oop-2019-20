#include <iostream>

//Source: https://www.youtube.com/watch?v=6uqU9Y578n4

struct Vector2 {
	float x, y;
};

struct Vector4 {
	union {
		struct {	
			float x, y, z, w;
		};

		struct {
			Vector2 a, b;	
		};
	};
};

void printVector2(const Vector2& vector) {
	std::cout << "( " << vector.x << ", " << vector.y << " )" << std::endl;
}

int main() {

	Vector4 vec = { 1.0f, 2.0f, 3.0f, 4.0f };
	printVector2(vec.a);
	std::cout << "----------------------" << std::endl;
	vec.z = 500.0f;
	printVector2(vec.b);
	

	return 0;
}
