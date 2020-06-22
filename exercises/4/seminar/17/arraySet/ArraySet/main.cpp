#include <iostream>
#include <vector>
#include "ArraySet.h"
using namespace std;

#include <chrono> 
void time() {
	auto start = std::chrono::high_resolution_clock::now();

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

int main() {
	ArraySet s;
	for (int i = 0; i < 10000; i += 1) {
		s.insert(i);
	}
	//s.print();

	const int* elementPointer = s.getElement(5433);

	if (elementPointer == nullptr) {
		cout << "wrong element" << endl;
	} else {
		cout << *elementPointer << endl;
	}

	time();

	return 0;
}