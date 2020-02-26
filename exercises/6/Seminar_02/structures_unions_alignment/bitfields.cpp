#include <iostream>
#include <stdint.h>
// https://en.cppreference.com/w/cpp/language/bit_field
// 

struct S {
	// three-bit unsigned field,
	// allowed values are 0...7
	unsigned int b : 3;
};

struct K {
	// will usually occupy 2 bytes:
	// 3 bits: value of b1
	// 2 bits: unused
	// 6 bits: value of b2
	// 2 bits: value of b3
	// 3 bits: unused
	unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};

struct T {
	// will usually occupy 2 bytes:
	// 3 bits: value of b1
	// 5 bits: unused
	// 6 bits: value of b2
	// 2 bits: value of b3
	unsigned char b1 : 3;
	unsigned char :0; // start a new byte
	unsigned char b2 : 6;
	unsigned char b3 : 2;
};

struct L {
	std::uint8_t b : 1000;
};

int main() {
	S s = {6};
	++s.b; // store the value 7 in the bit field
	std::cout << s.b << std::endl;
	++s.b; //the value 8 does not fit in this bit field
	std::cout << s.b << std::endl; // formally implementation defined, typically 0

	std::cout << "Size of struct S in bytes: " << sizeof(S) << std::endl; // usially prints 4
	std::cout << "Size of struct K in bytes: " << sizeof(K) << std::endl; // usially prints 2
	std::cout << "Size of struct T in bytes: " << sizeof(T) << std::endl; // usially prints 2
	std::cout << "Size of struct L in bytes: " << sizeof(T) << std::endl; // usially prints 2


}
