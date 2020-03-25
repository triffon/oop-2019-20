#include <iostream>

#include "Car.h"


int main()
{
	// Дебъгнете това създаване на инстанции
	EngineDetails ed( 200, 200, EngineType::Petrol );
	VisualDetails vd( 5, true, "chernooo" );
	ManufactureDetails md( "name", "model", 2020 );
	Car car( ed, vd, md, true, 20000000 );

	/* След това дебъгнете това създаване на обекти
	Car car(	EngineDetails( 200, 200, EngineType::Petrol ), 
				VisualDetails( 5, true, "chernooo" ), 
				ManufactureDetails( "name", "model", 2020 ), 
				true, 20000000 );
	*/

	return 0;
}
