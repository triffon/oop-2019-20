#include "task.hpp"

void Task::print(std::ostream& os) const {
    os << "задача '" << getName() << "'";
}