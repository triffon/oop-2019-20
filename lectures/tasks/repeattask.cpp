#include "repeattask.hpp"

RepeatTask::RepeatTask(char const* n, unsigned rc, Task const& rt)
    : Task(n), repetitionCount(rc), repetitionProgress(0), currentTask(&rt) {
    if (repetitionCount == 0)
        throw "Опит за създаване на повтаряща се задача (RepeatTask) с 0 на брой повторения";
}

void RepeatTask::print(std::ostream& os) const {}

// работа по задачата
// параметърът time указва колко време искаме да работим по задачата
// като резултат се връща неизработените единици време
unsigned RepeatTask::work(unsigned time) {
    return time;
}
