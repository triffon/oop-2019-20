#ifndef __QUICK_TASK_HPP
#define __QUICK_TASK_HPP

#include "task.hpp"

class QuickTask : public Task {
    bool finished;

    static const unsigned QUICKTASK_EXECUTION_TIME;
public:
/*
    static char const* getTaskTypeStatic() { return "Quick task"; } 
    char const* getTaskTypeVirtual() { return "Quick task"; }
*/
    QuickTask(char const* n);

    void print(std::ostream& os = std::cout) const;

    // време за изпълнение на задачата
    unsigned getExecutionTime() const { return QUICKTASK_EXECUTION_TIME; }

    // прогрес по задачата
    unsigned getProgress() const { return finished; }

    // работа по задачата
    // параметърът time указва колко време искаме да работим по задачата
    // като резултат се връща неизработените единици време
    unsigned work(unsigned time = 1);
};

#endif