#include "task.hpp"

void Task::print(std::ostream& os) const {
    os << "задача '" << getName() << "'";
}

std::ostream& operator<<(std::ostream& os, Task const& t) {
    t.print(os);
    return os << std::endl;
}
