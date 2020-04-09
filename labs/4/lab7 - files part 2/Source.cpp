#include "Car.h"
#include "CarDealership.h"
#include <iostream>
using namespace std;

const char* ADD_CAR_CMD = "addCar";
const char* EXIT_CMD = "exit";

void save(const CarDealership& dealership) {
	ofstream fileOut;
	fileOut.open("CarDealership.txt");
	dealership.serialize(fileOut);
	fileOut.close();
}

int runProgram() {
	CarDealership carDealership;

	while (true) {
		char command[100];
		cout << "Enter command: ";
		cin.getline(command, 100);
		if (strcmp(command, EXIT_CMD) == 0) {
			cout << "Exiting..." << endl;
			break;
		}
		else if (strcmp(command, ADD_CAR_CMD) == 0) {
			char name[100];
			char manufacturer[20];
			int price;
			cout << "Enter car manufacturer: ";
			cin.getline(manufacturer, 20);
			cout << "Enter car modelName: ";
			cin.getline(name, 100);
			cout << "Enter car price: ";
			cin >> price;

			carDealership.addCar(Car(manufacturer, name, price));
		}
		cin.ignore();
	}
	save(carDealership);
	return 0;
}

int main() {
	runProgram();

	ifstream fileIn;
	fileIn.open("CarDealership.txt");
	CarDealership carDealership2;
	carDealership2.deserialize(fileIn);
	fileIn.close();
	carDealership2.print();
}
