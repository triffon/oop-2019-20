#ifndef _AI_HPP
#define _AI_HPP

#include <iostream>
#include "printable.hpp"

class AI : virtual public Printable {
    char* algorithm;
    double threshold;

    void setAlgorithm(char const* _algo);
public:
    AI(char const* _algo = "<неизвестен алгоритъм>", double _t = 1);
    AI(AI const&);
    AI& operator=(AI const&);
    ~AI();

    char const* getAlgorithm() const { return algorithm; }
    double getThreshold() const { return threshold; }

    void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, AI const& p);

#endif