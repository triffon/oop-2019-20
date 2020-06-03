#include "quicktask.hpp"

const unsigned QuickTask::QUICKTASK_EXECUTION_TIME = 1;

QuickTask::QuickTask(char const* n) : Task(n), finished(false) {}

void QuickTask::print(std::ostream& os) const {
    os << "бърза ";
    Task::print(os);
    os << ", която ";
    if (!finished)
        os << "НЕ ";
    os << "е завършена";
}

unsigned QuickTask::work(unsigned time) {
    if (time > 0 && !finished) {
        time--;
        finished = true;
    }
    return time;
}
