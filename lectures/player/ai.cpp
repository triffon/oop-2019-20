#include <cstring>
#include "ai.hpp"

AI::AI(char const* _algo, double _t) : algorithm(nullptr), threshold(_t) {
    setAlgorithm(_algo);
}

AI::AI(AI const& other) : algorithm(nullptr), threshold(other.threshold) {
    setAlgorithm(other.algorithm);
}

AI& AI::operator=(AI const& other) {
    if (this != &other) {
        delete[] algorithm;
        setAlgorithm(other.algorithm);
        threshold = other.threshold;
    }
    return *this;
}

AI::~AI() {
    delete[] algorithm;
}

void AI::setAlgorithm(char const* _algo) {
    // разчитаме, че за name има заделена памет и в нея има записано нещо
    // изтриваме старата памет
    delete[] algorithm;
    // заделяме нова
    algorithm = new char[strlen(_algo) + 1];
    // сигурни сме, че имаме достатъчно памет
    strcpy(algorithm, _algo);
}

void AI::print(std::ostream& os) const {
    os << "изкуствен интелект с алогритъм " << getAlgorithm() << " с праг " << getThreshold();
}

std::ostream& operator<<(std::ostream& os, AI const& ai) {
    ai.print(os);
    return os << std::endl;
}