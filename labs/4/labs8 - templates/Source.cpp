#include <iostream>
#include "Vector.h"

using namespace std;


int main() {
	Vector<int> myArrayInt;
	Vector<float> myArrayFloat;

	myArrayInt.add(1);
	myArrayInt.add(2);
	myArrayInt.add(3);
	myArrayInt[2] = 2;

	for (int i = 0; i < myArrayInt.getLength(); ++i) {
		cout << myArrayInt[i] << ' ';
	}
	cout << endl;

	myArrayInt.remove(0);
	myArrayInt.remove(0);
	myArrayInt.remove(0);

	for (int i = 0; i < myArrayInt.getLength(); ++i) {
		cout << myArrayInt[i] << ' ';
	}
	cout << endl;
}