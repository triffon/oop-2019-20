#include <sstream>
#include "doctest.h"
#include "../simpletask.hpp"

SimpleTask createTestSimpleTask() {
    return SimpleTask("писане на проект по C++", 6);
}

TEST_CASE("Проста задача с име, по която не е работено, се извежда коректно") {
    SimpleTask st = createTestSimpleTask();
    std::ostringstream os;
    st.print(os);
    CHECK_NE ( os.str(), "");
    CHECK_EQ ( os.str(), "проста задача 'писане на проект по C++', която изисква 6 единици време и е с прогрес 0" );
}

TEST_CASE("Простата задача при създаване не е завършена") {
    SimpleTask st = createTestSimpleTask();
    CHECK_EQ( st.getProgress(), 0);
    CHECK( !st.isFinished() );
}

TEST_CASE("Простата задача не се завършва при работа 0 единици време") {
    SimpleTask st = createTestSimpleTask();
    CHECK_EQ( st.work(0), 0 );
    CHECK_EQ( st.getProgress(), 0);
    CHECK( !st.isFinished() );
}

TEST_CASE("Работа по проста задача на стъпки по 1 единица време") {
    SimpleTask st = createTestSimpleTask();
    for(int i = 0; i < st.getExecutionTime(); i++) {
        CHECK_EQ( st.getProgress(), i );
        CHECK_EQ( st.work(1), 0 );
    }
    CHECK_EQ( st.getProgress(), st.getExecutionTime() );
    CHECK( st.isFinished() );
    CHECK_EQ( st.work(1), 1 );
    CHECK_EQ( st.getProgress(), st.getExecutionTime() );
    CHECK( st.isFinished() );
}

TEST_CASE("Работа по проста задача на различни стъпки време") {
    SimpleTask st = createTestSimpleTask();
    CHECK_EQ( st.work(2), 0 );
    CHECK_EQ( st.getProgress(), 2 );

    CHECK_EQ( st.work(3), 0);
    CHECK_EQ( st.getProgress(), 5 );

    CHECK_EQ( st.work(0), 0);
    CHECK_EQ( st.getProgress(), 5 );

    CHECK_EQ( st.work(4), 3);
    CHECK_EQ( st.getProgress(), 6 );

    CHECK_EQ( st.work(5), 5);
    CHECK_EQ( st.getProgress(), 6 );
}