#include <sstream>
#include "doctest.h"
#include "../quicktask.hpp"

const char NAME[] = "изхвърляне на боклука";

TEST_CASE("Бърза задача с име, по която не е работено, се извежда коректно") {
    // QuickTask qt(nullptr);
    QuickTask qt(NAME);
    /*
    try {
      new char[100000000000];
    } catch (std::bad_alloc const&) {
        std::cerr << "Невъзможност за заделяне на памет!";
    }
    */

    char* large = new (std::nothrow) char[100000000000];
    if (large == nullptr)
        std::cerr << "Невъзможност за заделяне на памет!";

    std::ostringstream os;
    
    /*
    std::ofstream os("test.txt");
    qt.print(os);
    os.close();

    std::ifstream is("test.txt");
    const int MAX = 1000;
    char line[MAX];
    is.getline(line, MAX);
    is.close();

    CHECK_NE ( line, "" );
    CHECK_EQ ( line, "abc");
    */

    qt.print(os);
    CHECK_NE ( os.str(), "");
    CHECK_EQ ( os.str(), "бърза задача 'изхвърляне на боклука', която НЕ е завършена" );
}

TEST_CASE("Бързата задача при създаване не е завършена") {
    QuickTask qt(NAME);
    CHECK_EQ( qt.getProgress(), 0);
    CHECK( !qt.isFinished() );
}

TEST_CASE("Бързата задача не се завършва при работа 0 единици време") {
    QuickTask qt(NAME);
    CHECK_EQ( qt.work(0), 0 );
    CHECK_EQ( qt.getProgress(), 0);
    CHECK( !qt.isFinished() );
}

TEST_CASE("Бързата задача се завършва при работа 1 единица време") {
    QuickTask qt(NAME);
    CHECK_EQ (qt.work(1), 0);
    CHECK_EQ( qt.getProgress(), 1);
    CHECK( qt.isFinished() );
}

TEST_CASE("Бързата задача винаги има време за изпълнение 1") {
    QuickTask qt(NAME);
    CHECK_EQ( qt.getExecutionTime(), 1 );
}

TEST_CASE("Бързата задача се завършва при работа повече от 1 единица време") {
    QuickTask qt(NAME);
    CHECK_EQ (qt.work(10), 9);
    CHECK_EQ( qt.getProgress(), 1);
    CHECK( qt.isFinished() );
}
