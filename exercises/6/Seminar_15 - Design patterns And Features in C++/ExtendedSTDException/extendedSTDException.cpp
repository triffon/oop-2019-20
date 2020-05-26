#include <string>
#include <iostream>
#include <ctime>
#include <chrono>

class Student
{
private:
	enum Status
	{
		enrolled,
		withdrawn,
		graduated
	};

private:
	std::string name;
	unsigned int faculty_number;

	Status status;


public:
	Student() = default;
	Student(std::string name, unsigned int faculty_number);
	Student(const Student& s) = default;
	Student& operator= (const Student& s);
	~Student() = default;


	std::string get_name() const;
	unsigned int get_fn() const;
	std::string get_status() const;

};

std::string Student::get_status() const {
	if(status == enrolled) {
		return "enrolled";
	} else if(status == withdrawn) {
		return "withdrawn";
	} else if(status == graduated) {
		return "graduated";
	}

	throw StudentException("ERROR: Unknown status");
}

class StudentException : virtual public std::exception
{
protected:
	std::string error_message;

public:
	explicit StudentException( const char* msg )
		: error_message( msg )
	{
	}

	explicit StudentException( const std::string& msg )
		: error_message( msg )
	{
	}

	virtual ~StudentException() throw ( )
	{
	}

	virtual const char* what() const throw ( )
	{
		return error_message.c_str();
	}
};




class Exception : virtual public std::exception
{
public:
	std::string error_message;

public:
	explicit Exception( const char* msg )
		: error_message( msg )
	{
	}

	explicit Exception( const std::string& msg )
		: error_message( msg )
	{
	}

	virtual ~Exception() throw ( )
	{
	}

	virtual const char* what() const throw ( )
	{
		return error_message.c_str();
	}
};

class framework_exception : virtual public std::exception
{
public:
	std::string error_message;

public:
	explicit framework_exception( const char* msg )
		: error_message( msg )
	{
	}

	explicit framework_exception( const std::string& msg )
		: error_message( msg )
	{
	}

	virtual ~framework_exception() throw ( )
	{
	}

	virtual const char* what() const throw ( )
	{
		return error_message.c_str();
	}

	const char* Details() const
	{
		// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
		auto currentTime = std::chrono::system_clock::now();
		std::time_t tCurrentTime = std::chrono::system_clock::to_time_t( currentTime );
		std::cout << "Time of throw the exception: " << std::ctime( &tCurrentTime );
		return error_message.c_str();
	}
};


void ComplexOperationThatCouldFailABunchOfWays()
{
	srand(time(NULL));

	switch ( rand() % 4 )
	{
		case 0:
		{
			Student().get_status();
		}
		case 1:
		{
			throw Exception("Very bad exception");
		}
		case 2:
		{
			throw framework_exception( "framework exceion" );
		}
	}
}

int main()
{
	try {
		ComplexOperationThatCouldFailABunchOfWays();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// If exceptions do NOT inherit from std::exception, this gets much uglier:
	// https://softwareengineering.stackexchange.com/questions/305641/should-one-derive-inherit-from-stdexception
	try {
		ComplexOperationThatCouldFailABunchOfWays();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	} catch (Exception& e) {
		std::cerr << e.error_message << std::endl;
	} catch (framework_exception& e) {
		std::cerr << e.Details() << std::endl;
	}

	return 0;
}