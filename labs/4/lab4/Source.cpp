#include "Product.h"
#include "Store.h"
#include <iostream>

using namespace std;

int main() {
	Product a("Coca Cola", "The Coca Cola Company", 1.5f, 100);
	Store store(10);

	// The compiler will chose the right method, depending on the arguments
	// given to addProduct method
	store.addProduct(a);
	store.addProduct("7Days Chocolate Croissant", "7Days", 1, 100);

	store.print();

	Store store2(store);
	store2.print();

	Store store3;
	store3 = store2;

	store3.print();
}