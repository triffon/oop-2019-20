#ifndef __SIMPLETASK_HPP
#define __SIMPLETASK_HPP

#include "task.hpp"

class SimpleTask : public Task {
    unsigned executionTime;
    unsigned progress;
public:
    SimpleTask(char const* n = "<проста задача>", unsigned et = 1);

    void print(std::ostream& os = std::cout) const;

    // време за изпълнение на задачата
    unsigned getExecutionTime() const { return executionTime; }

    // прогрес по задачата
    unsigned getProgress() const { return progress; }

    // работа по задачата
    // параметърът time указва колко време искаме да работим по задачата
    // като резултат се връща неизработените единици време
    unsigned work(unsigned time = 1);
};

#endif