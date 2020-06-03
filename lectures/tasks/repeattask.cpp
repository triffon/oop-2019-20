#include "repeattask.hpp"

RepeatTask::RepeatTask(char const* n, unsigned rc, Task const& rt) : Task(n) {
    throw "Не е реализиран!";
}

void RepeatTask::print(std::ostream& os) const {}

// работа по задачата
// параметърът time указва колко време искаме да работим по задачата
// като резултат се връща неизработените единици време
unsigned RepeatTask::work(unsigned time) {
    return time;
}
