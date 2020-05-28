#include "gmock/gmock.h"

#ifndef MOCKFOOD
#define MOCKFOOD

#include"Food.h"
class MockFood : public Food{
public:
MOCK_METHOD(int,eat, (int count), (override));
};


#endif /* MOCKFOOD */
