CPPFLAGS = -std=c++14 -MD -MP 

SRC = $(wildcard ./src/*.cpp)

all: main

main: $(SRC:%.cpp=%.o)
	g++ $(CPPFLAGS) -o $@ $^ 

-include $(SRC:%.cpp=%.d)
