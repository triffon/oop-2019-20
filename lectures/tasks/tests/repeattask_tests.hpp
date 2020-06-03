#include "doctest.h"
#include "../repeattask.hpp"

RepeatTask createTestRepeatTask() {
    return RepeatTask("лекции по ООП", 15, SimpleTask("лекция по ООП", 3));
}

TEST_CASE("Повтаряща се задача с име, по която не е работено, се извежда коректно") {
    RepeatTask rt = createTestRepeatTask();
    std::ostringstream os;
    rt.print(os);
    CHECK_NE ( os.str(), "");
    CHECK_EQ ( os.str(), "повтаряща се задача 'лекции по ООП', която повтаря проста задача 'лекция по ООП', която изисква 3 единици време и е с прогрес 0, която вече е повторена общо 0 от 15 пъти");
}

TEST_CASE("Повтарящата се задача при създаване не е завършена") {
    RepeatTask rt = createTestRepeatTask();
    CHECK_EQ( rt.getProgress(), 0);
    CHECK( !rt.isFinished() );
}

TEST_CASE("Повтарящата се задача не се завършва при работа 0 единици време") {
    RepeatTask rt = createTestRepeatTask();
    CHECK_EQ( rt.work(0), 0 );
    CHECK_EQ( rt.getProgress(), 0);
    CHECK( !rt.isFinished() );
}

TEST_CASE("Работа по повтаряща се задача на стъпки по 1 единица време") {
    RepeatTask rt = createTestRepeatTask();
    for(int i = 0; i < rt.getExecutionTime(); i++) {
        CHECK_EQ( rt.getProgress(), i );
        CHECK_EQ( rt.work(1), 0 );
    }
    CHECK_EQ( rt.getProgress(), rt.getExecutionTime() );
    CHECK( rt.isFinished() );
    CHECK_EQ( rt.work(1), 1 );
    CHECK_EQ( rt.getProgress(), rt.getExecutionTime() );
    CHECK( rt.isFinished() );
}

TEST_CASE("Работа по повтаряща се задача на различни стъпки време") {
    RepeatTask rt = createTestRepeatTask();

    // частична работа по първото повторение
    CHECK_EQ( rt.work(2), 0 );
    CHECK_EQ( rt.getProgress(), 2 );

    // приключваме първото повторение и започваме второто
    CHECK_EQ( rt.work(3), 0);
    CHECK_EQ( rt.getProgress(), 5 );

    // не работим
    CHECK_EQ( rt.work(0), 0);
    CHECK_EQ( rt.getProgress(), 5 );

    // приключваме второто повторение, правим третото и четвъртото наведнъж и започваме петото
    CHECK_EQ( rt.work(8), 0);
    CHECK_EQ( rt.getProgress(), 13 );

    // приключваме петото повторение
    CHECK_EQ( rt.work(2), 0);
    CHECK_EQ( rt.getProgress(), 15 );

    // изработваме шестото и седмото повторение
    CHECK_EQ( rt.work(6), 0);
    CHECK_EQ( rt.getProgress(), 21 );

    // започваме осмото повторение
    CHECK_EQ( rt.work(1), 0);
    CHECK_EQ( rt.getProgress(), 22 );

    // довършваме осмото повторение, и правим цялото девето
    CHECK_EQ( rt.work(5), 0);
    CHECK_EQ( rt.getProgress(), 27 );

    // изработваме цялото време докато не ни останат само две единици време
    CHECK_EQ( rt.work(16), 0);
    CHECK_EQ( rt.getProgress(), 43 );

    SUBCASE("Довършваме задачата на по една стъпка") {
        CHECK_EQ( rt.work(1), 0);
        CHECK_EQ( rt.getProgress(), 44 );

        CHECK_EQ( rt.work(1), 0);
        CHECK_EQ( rt.getProgress(), 45 );

        CHECK_EQ( rt.work(1), 1);
        CHECK_EQ( rt.getProgress(), 45 );
    }

    SUBCASE("Довършваме задачата като даваме точния брой единици време") {
        CHECK_EQ( rt.work(2), 0);
        CHECK_EQ( rt.getProgress(), 45 );

        CHECK_EQ( rt.work(1), 1);
        CHECK_EQ( rt.getProgress(), 45 );
    }

    SUBCASE("Довършваме задачата като даваме брой единици време, надвишаващ нужния") {
        CHECK_EQ( rt.work(3), 1);
        CHECK_EQ( rt.getProgress(), 45 );

        CHECK_EQ( rt.work(3), 0);
        CHECK_EQ( rt.getProgress(), 45 );
    }

    SUBCASE("Довършваме задачата като даваме много голям брой единици време, надвишаващ нужния") {
        CHECK_EQ( rt.work(300), 298);
        CHECK_EQ( rt.getProgress(), 45 );

        CHECK_EQ( rt.work(300), 0);
        CHECK_EQ( rt.getProgress(), 45 );
    }
}