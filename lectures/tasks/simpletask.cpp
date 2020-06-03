#include <cassert>
#include "simpletask.hpp"

SimpleTask::SimpleTask(char const* n, unsigned et) : Task(n), executionTime(et), progress(0) {
    if (executionTime == 0)
        throw "Опит за създаване на проста задача (SimpleTask) с време за изпълнение 0";
        // { executionTime = 1; std::clog << "[WARNING] Зададено време за изпълнение 0 и автоматично коригиране на 1\n"; }
}

void SimpleTask::print(std::ostream& os) const {
    os << "проста ";
    Task::print(os);
    os << ", която изисква " << getExecutionTime() << " единици време и е с прогрес " << getProgress();
}

unsigned SimpleTask::work(unsigned time) {
    // пресмятаме времето, което реално ще изработим по задачата
    unsigned workTime = std::min(executionTime - progress, time);
    progress += workTime;
    assert( progress <= executionTime );
    return time - workTime;
}