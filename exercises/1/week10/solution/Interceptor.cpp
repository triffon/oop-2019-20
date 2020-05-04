#include "Interceptor.h"
#include <iostream>
using namespace std;

Interceptor::Interceptor()
	: Starship("Interceptor", 10)
{
}


void Interceptor::attack()
{
	cout << "Interceptor: attacking" << endl;
	attacks_count++;
}
void Interceptor::printInfo()
{
	cout << "Interceptor Info: " << endl;
	cout << "  number of attacks: " << attacks_count << endl;
	cout << "  weight: " << weight_in_tons << endl;
}