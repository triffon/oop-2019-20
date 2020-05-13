Salad::Salad(const int productsCount, const bool isSpiced, 
			const int weight, const double price) : Food(weight, 1, price) {
	this->productsCount = productsCount;
	this->isSpiced = isSpiced;
}

void Salad::category() {
	cout << "SALAD " << endl;
}

Food* Salad::clone() {
	return new Salad(*this);
}

void Salad::print() {
	cout << "Products Count: " << productsCount << endl;
	cout << "Is Spiced: " << isSpiced << endl;
	Food::print();
}
