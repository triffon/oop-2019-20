#include <iostream>



struct Entity
{
private:
	static unsigned count;

public:
	Entity()
	{
		++count;
	}

	~Entity()
	{
		--count;
	}

	static void print_count()
	{
		std::cout << "Count instances: " << count << std::endl;
	}
};

unsigned Entity::count = 0;
/*
int main()
{

	return 0;
}
*/