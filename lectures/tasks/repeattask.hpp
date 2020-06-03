#ifndef __REPEATTASK_HPP
#define __REPEATTASK_HPP

#include "task.hpp"

class RepeatTask : public Task {
    Task const* currentTask;
    unsigned repetitionProgress;
    unsigned repetitionCount;
public:
    RepeatTask(char const* n, unsigned rc, Task const& rt);

    void print(std::ostream& os = std::cout) const;

    // колко пъти е повторило задачата до момента
    unsigned getRepetitionProgress() const { return repetitionProgress; }

    // колко пъти общо ще повтаряме задачата
    unsigned getRepetitionCount() const { return repetitionCount; }

    // време за изпълнение на задачата
    unsigned getExecutionTime() const { return 1; }

    // прогрес по задачата
    unsigned getProgress() const { return 0; }

    // работа по задачата
    // параметърът time указва колко време искаме да работим по задачата
    // като резултат се връща неизработените единици време
    unsigned work(unsigned time = 1);
};

#endif