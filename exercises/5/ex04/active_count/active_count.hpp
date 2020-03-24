#ifndef __ACTIVE_COUNT_HPP__
#define __ACTIVE_COUNT_HPP__

class ActiveCount {

public:
    ActiveCount();
    ~ActiveCount();
    static int getInstancesCount();

private:
    static int instancesCount;

};

#endif