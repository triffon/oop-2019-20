#include <iostream>

// https://stackoverflow.com/questions/4306186/structure-padding-and-packing

struct X {
	char a;
	int b;
	char c;
};

struct Y {
	int b;
	char a;
	char c;
};

int main() {
	std::cout << "Size of struct X in bytes: " << sizeof(X) << std::endl;
	std::cout << "Size of struct Y in bytes: " << sizeof(Y) << std::endl;

	X array1[1000];
	Y array2[1000];

	std::cout << "Array with 1000 elements of type X is: " << sizeof(array1) << " bytes\n";
	std::cout << "Array with 1000 elements of type Y is: " << sizeof(array2) << " bytes\n";

	return 0;
}
