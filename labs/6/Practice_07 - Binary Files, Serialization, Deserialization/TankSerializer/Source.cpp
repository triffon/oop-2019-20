#include "Tank.h"
#include "Army.h"
#include <string>
#include <vector>

int main()
{
	// serialize and deserialize single tank
	ofstream ofs ("tanks.bin", std::ios::binary );
	Tank t1( "tank1", 40, 100 );
	Tank t2( "tank2", 20, 200 );

	t1.serialize( ofs );
	ofs.close();


	std::ifstream ifs( "tanks.bin", std::ios::binary );
	Tank t3;
	t3.deserialize( ifs );

	t3.tankInfo();
	ifs.close();

	// serialize and deserialize whole army
	Army yasenAleksievArmy;
	yasenAleksievArmy.addTank( t1 );
	yasenAleksievArmy.addTank( t2 );
	yasenAleksievArmy.addTank( t3 );
	
	ofs.open( "army.bin", std::ios::binary );

	yasenAleksievArmy.serialize( ofs );
	ofs.close();
	// изпращам на Ясен Бонев по интернет армията във бинарния файл

	Army yasenBonevArmy;
	ifs.open( "army.bin", std::ios::binary );
	yasenBonevArmy.deserialize( ifs );

	yasenBonevArmy.print();

	ifs.close();

//========================================================
//	two armies take battle
	Tank tank1("TankaNaAlexiev1", 50.0, 100.0);

	Tank tank2("TankaNaAlexiev2", 30.0, 100.0);
	Tank tank3("TankaNaAlexiev3", 60.0, 100.0);
	Tank tank4("TankaNaAlexiev4", 55.5, 100.0);
	Tank tank5("TankaNaAlexiev5", 10.0, 100.0);
	Army alexievArmy(5);

	alexievArmy.addTank(tank1);
	alexievArmy.addTank(tank2);
	alexievArmy.addTank(tank3);
	alexievArmy.addTank(tank4);
	alexievArmy.addTank(tank5);

	ofstream ofs( "tanks.bin", std::ios::binary | std::ios::app);

	Tank tank6("TankaNaBonev1", 40.0, 100.0);
	Tank tank7("TankaNaBonev2", 80.0, 100.0);
	Tank tank8("TankaNaBonev3", 12.3, 100.0);
	Tank tank9("TankaNaBonev4", 31.4, 100.0);
	Tank tank10("TankaNaBonev5", 60.0, 100.0);

	Army bonevArmy(5);

	bonevArmy.addTank(tank6);
	bonevArmy.addTank(tank7);
	bonevArmy.addTank(tank8);
	bonevArmy.addTank(tank9);
	bonevArmy.addTank(tank10);


	alexievArmy.attack(tank7);

	return 0;
}
