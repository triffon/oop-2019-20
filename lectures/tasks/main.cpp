#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "quicktask_tests.hpp"
#include "simpletask_tests.hpp"
#include "repeattask_tests.hpp"

/*
// Пример за непрехванато изключение
#include "quicktask.hpp"

int main() {
    doctest::Context().run();

    QuickTask qt("Бърза задача");
    std::cout << qt;
    Task* t = &qt;
    std::cout << t->getTaskTypeStatic() << std::endl;
    std::cout << t->getTaskTypeVirtual() << std::endl;
}
*/