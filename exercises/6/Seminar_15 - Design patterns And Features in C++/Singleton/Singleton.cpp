#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>

class Singleton
{
	static Singleton* instance;
	int data;

	// Private constructor so that no objects can be created.
	Singleton()
	{
		data = 0;
	}

public:
	static Singleton* getInstance()
	{
		if ( !instance )
		{
			instance = new Singleton;
		}
		return instance;
	}

	int getData()
	{
		return this->data;
	}

	void setData( int data )
	{
		this->data = data;
	}
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = nullptr;



//=================================================================================================
// From https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class S
{
public:
	static S& getInstance()
	{
		static S    instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}
private:
	S()
	{
	}                    // Constructor? (the {} brackets) are needed here.

								// C++ 03
								// ========
								// Don't forget to declare these two. You want to make sure they
								// are unacceptable otherwise you may accidentally get copies of
								// your singleton appearing.
	//S( S const& );              // Don't Implement
	//S& operator=( const S& );	// Don't implement

							  // C++ 11
							  // =======
							  // We can use the better technique of deleting the methods
							  // we don't want.
public:
	S( const S& )				= delete;
	S& operator=( const S& )	= delete;

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};

//================================================================================================
// Author: Ivan Filipov

#define _B		1
#define _KB		1024 * _B
#define _MB		1024 * _KB
#define _4MB	4	 * _MB

class SingletonBigData {

private:

	char aLotOfData[_4MB];

public:

	SingletonBigData& operator=(const SingletonBigData&) = delete;
	SingletonBigData(const SingletonBigData&) = delete;

private:

	SingletonBigData() = default;

public:

	static SingletonBigData& getInstance() {

		static SingletonBigData instance;	//creates the object only the first time 
											//the getInstance method is invoked
											//here we can "see" the private constructor

		return instance;
	}

	void init() {

		srand(time(NULL));

		for (int i = 0; i < _4MB; i++)
			aLotOfData[i] = rand() % 128;
	}

	void printContain() const {

		for (int i = 0; i < _4MB; i++)
			std::cout << std::setw(4) << aLotOfData[i];
	}
};


int main()
{
	Singleton* s = Singleton::getInstance();
	std::cout << s->getData() << std::endl;
	s->setData( 100 );
	std::cout << s->getData() << std::endl;

	Singleton other( *s ); // we don't want to create other objects
	other.setData( 1000 );
	std::cout << other.getData() << std::endl;


	//====================================================
	S& obj = S::getInstance();
	// do something with obj


	//====================================================
	SingletonBigData& data = SingletonBigData::getInstance();
	data.init();
	data.printContain();
	std::cout << "\n==============================\n";

	SingletonBigData& newData = SingletonBigData::getInstance();
	newData.printContain();

	return 0;
}