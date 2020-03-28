#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

struct Student {

	char name[24];
	unsigned int fn;
};

//дава дължината на вече отворен файл
//в режим за четене, връща get position-ът в началото на файла
size_t getFileLen( std::ifstream& ifs )
{ //можем да подаваме вече създаден поток на функции

	ifs.seekg( 0, std::ios::end );  //местим се в края на файла
	size_t size = ifs.tellg(); //взимаме текущата позиция
	ifs.seekg( 0, std::ios::beg ); //връщаме се в началото

	return size;
}

//записва няколко студента в двоичен файл
//зададен чрез пътия си, като премахва старото съдържание
//на файла
//връща true при успешно записване, false иначе
bool writeStudents( const char* path )
{

	std::ofstream ofs( path, std::ios::binary | std::ios::trunc );

	if ( !ofs.is_open() ) //проверка дали е отворен успешно файлът
		return false;

	//няколко случайни ученици
	Student students[] = {

		{ "Yasen", 45460 },
		{ "Stefan", 45728 },
		{ "Gosho", 71433}

	};

	//записваме ги във файла един по един
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
	//ofs.write((const char*)&students[i], sizeof(Student));

	//нищо не ни пречи да ги запишем и всички наведнъж :
	ofs.write( (const char*) students, sizeof( students ) ); //students е началото на масива
								//няма нужда от & за да вземем адреса

	if ( !ofs.good() ) // проверяваме дали след операцията потокът е в невалидено състояние
		return false;

	ofs.close();
	return true;
}


//чете неизвестен предварително брой студенти записани в двойчен файл
bool readStudents( const char* path )
{

	std::ifstream ifs( path, std::ios::binary );

	if ( !ifs.is_open() )
		return false;

	size_t fileSize = getFileLen( ifs ); // общия брой записани байтове

	if ( fileSize == 0 )
		return false;

	size_t objCount = fileSize / sizeof( Student ); // общия брой записи

	Student* students; //тук ще прочетем студентите

	students = new Student[ objCount ];

	//прочитаме ги от файла в масива 
	ifs.read( (char*) students, fileSize );

	if ( !ifs ) //ако четенето не е било успешно
		return false;

	for ( size_t i = 0; i < objCount; i++ )
		std::cout << students[ i ].name << ' '
		<< students[ i ].fn << std::endl;

	ifs.seekg( std::ios::beg ); // преместваме пак поинтера за четене в началото на файла
	//можем и да прочетем точно един студент на произволна позиция от файла
	srand( time( nullptr ) );
	size_t randomIndex = rand() % objCount; // избираме рандом индекс
	ifs.seekg( randomIndex * sizeof( Student ) ); // преместваме поинтера за четене толкова байта от началото, колкото се намира randomIndex студента


	Student singleStudent; // Създаваме си студент
	// Student* singleStudent = new Student; // можем и динамично на хийпа
	ifs.read( (char*) &singleStudent, sizeof( Student ) );
	//ifs.read( (char*) singleStudent, sizeof( Student ) ); // няма нужда от & за да вземем адреса на променливата, 
															//тя вече си е адрес и само кастваме към char*

	std::cout << singleStudent.name << ' '
		<< singleStudent.fn << std::endl;

	//освобождаваме ресурсите
	delete[] students;
	ifs.close();
	return true;
}

bool writeStudentsInEndOfFile( const char* path )
{
	std::ofstream ofs( path, std::ios::binary | std::ios::app ); // разлика с std::ios::ate
	//'app' comes from 'append' - all output will be added (appended) to the end of the file. 
	// In other words you cannot write anywhere else in the file but at the end.
	//'ate' comes from 'at end' - it sets the stream position at the end of the file when you open it,
	// but you are free to move it around (seek) and write wherever it pleases you.

	if ( !ofs.is_open() ) //проверка дали е отворен успешно файлът
		return false;

	//няколко случайни ученици
	Student students[] = {

		{ "Ivo", 45260 },
		{ "Viktoria", 45726 },
		{ "Petar", 61433 }
	};

	//записваме ги във файла един по един
	//size_t size = sizeof(students) / sizeof(Student);
	//for (size_t i = 0; i < size; i++)
	//ofs.write((const char*)&students[i], sizeof(Student));

	//нищо не ни пречи да ги запишем и всички наведнъж :
	ofs.write( (const char*) students, sizeof( students ) ); //students е началото на масива
															 //няма нужда от & за да вземем адреса

	if ( !ofs.good() ) // проверяваме дали след операцията потокът е в невалидено състояние
		return false;

	ofs.close();
	return true;
}


int main()
{

	if ( writeStudents( "students.bin" ) )
	{
		std::cout << "successfully written!\n";
	}
	else
	{
		std::cout << "error while writing\n";
	}

	std::cout << "trying to read the information ...\n";

	if ( !readStudents( "students.bin" ) )
	{
		std::cout << "error while reading";
	}

	if ( writeStudentsInEndOfFile( "students.bin" ) )
	{
		std::cout << "successfully written of the end of file!\n";
	}
	else
	{
		std::cout << "error while writing\n";
	}

	return 0;
}
