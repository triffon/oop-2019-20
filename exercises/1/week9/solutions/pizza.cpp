Pizza::Pizza(const string type,
			const int weight, const int parts, 
			const double price) : Food(weight, parts, price) {
	this->type = type;
}

void Pizza::print() {
	cout << "Type: " << this->type << endl;
	Food::print();
}

void Pizza::category() {
	cout << "PIZZA" << endl;
}

Food* Pizza::clone() {
	return new Pizza(*this);
}
