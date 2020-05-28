#include <cassert>
#include "task.hpp"

void Task::print(std::ostream& os) const {
    assert(os.good());
    os << "задача '" << getName() << "'";
}

std::ostream& operator<<(std::ostream& os, Task const& t) {
    t.print(os);
    return os << std::endl;
}
