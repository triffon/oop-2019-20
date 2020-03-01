#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME = 50;

class Car {
private:
	char brand[MAX_NAME];
	int hp;
	int weight;

public:
	Car();
	Car(const char* brand, int hp, int weight);
	Car(const Car& other);
	Car& operator=(const Car& other);

	void setHorsePower(int hp);
	void setWeight(int weight);
	void setBrand(const char* brand);

	int getWeight() const;
	int getHorsePower() const;
	const char* getBrand() const;

	float calculatePowerWeightRatio() const;

	void print() const;
};

Car::Car() {
	cout << "Default constructor called" << endl;
	strcpy(brand, "");
	hp = 0;
	weight = 0;
}

Car::Car(const char* brand, int hp, int weight) {
	cout << "Parameterized constructor called" << endl;
	this->hp = hp;
	this->weight = weight;
	strcpy(this->brand, brand);
}

Car::Car(const Car& other) {
	cout << "Copy constructor called" << endl;
	hp = other.hp;
	weight = other.weight;
	strcpy(brand, other.brand);
}

Car& Car::operator=(const Car & other) {
	cout << "Operator= called" << endl;
	if (this != &other) {
		hp = other.hp;
		weight = other.weight;
		strcpy(brand, other.brand);
	}

	return *this;
}

int Car::getWeight() const {
	return weight;
}

int Car::getHorsePower() const {
	return hp;
}

void Car::setHorsePower(int hp) {
	if (hp > 0) {
		this->hp = hp;
	}
}

void Car::setWeight(int weight) {
	if (weight > 0) {
		this->weight = weight;
	}
}

void Car::setBrand(const char* brand) {
	strcpy(this->brand, brand);
}

void Car::print() const {
	cout << "brand : " << brand << endl << "hp : " << hp << endl
		<< "weight : " << weight << endl << "hp per kilogram:" << calculatePowerWeightRatio() << endl;
}

const char* Car::getBrand() const {
	return brand;
}

float Car::calculatePowerWeightRatio() const {
	if (weight == 0) {
		return 0;
	}
	return hp / (float)weight;
}

void race(const Car& first, const Car& second) {
	cout << "Starting a rave between " << first.getBrand() << " and " << second.getBrand() << endl;
	float firstCarRatio = first.calculatePowerWeightRatio();
	float secondCarRatio = second.calculatePowerWeightRatio();
	if (firstCarRatio == secondCarRatio) {
		cout << "Draw" << endl;
	}
	else if (firstCarRatio > secondCarRatio) {
		cout << first.getBrand() << " wins";
	}
	else {
		cout << second.getBrand() << " wins";
	}
}

void printCarByRef(Car& car) { // No constructors called here. We pass car by ref
	car.print();
}

void printCarByValue(Car car) { // Copy constructor called here. We pass car by value
	car.print();
}

int main() {
	Car ferrari("Ferrari", 800, 1000);
	Car bentley("Bentley", 500, 2000);
	Car ferrari2(ferrari); // Copy constructor
	Car ferrari3; // Default constructor
	ferrari3 = ferrari; // operator=

	cout << endl << "Calling print car by ref:"  << endl;
	printCarByRef(ferrari2);
	cout << endl << "Calling print car by value:" << endl;
	printCarByValue(ferrari2);

	race(ferrari, bentley);
	cin.get();
}
