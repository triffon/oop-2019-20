#pragma once
#include <iostream>
// https://en.cppreference.com/w/cpp/language/static


struct Object
{
	int x, y; // coordinates of the object
	static int x_center, y_center; // coordinates of the center

	static int* somePointer;
};

int* Object::somePointer = nullptr; // this is how to initialize static pointer

struct Entity
{
private:
	static unsigned count; // this static member is not in the struct memory. All instances of type 'Entity' shared only one variable 'count'

public:
	Entity()
	{
		++count; // when create a instance we increment the variable
	}

	~Entity()
	{
		--count; // when destroy instance we decrement the variable
	}

	static void print_count()
	{
		std::cout << "Count instances: " << count << std::endl;
	}
};

unsigned Entity::count = 0; // always initialize the static variables



int main()
{
	Object obj1;
	Object obj2;

	obj1.x = 5;
	obj1.y = 8;

	obj2.x = 6; // this 'x' is different from 'x' on the obj1
	obj2.y = 3; // and this 'y' is different from 'y' on the obj1

	// but
	obj1.x_center = 1; // this two variables are shared from all of the instances 
	obj1.y_center = 1; // and
	// obj2.x_center and obj2.y_center should be the same
	std::cout << obj2.x_center << ' ' << obj2.y_center << std::endl;

	// and that's why because they are static members and they don't need instances
	// I can do that
	Object::x_center = 2;
	Object::y_center = 2;
	// and this will be the same 

	// ===================================
	Entity::print_count();
	{
		Entity e;
		Entity e2;
		Entity::print_count();
		Entity e3;
	}

	Entity::print_count();

	Entity* array = new Entity[ 10 ];
	Entity::print_count();

	delete[] array;
	Entity::print_count();
}