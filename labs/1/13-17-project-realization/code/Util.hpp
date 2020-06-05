#pragma once

#include <cassert>

/**
 * Static class used for utility functions
 */
class Util
{
public:
    Util() = delete;
    Util(const Util&) = delete;
    Util& operator=(const Util&) = delete;
    ~Util() = delete;

    /**
     * @brief Returns the value clamped between low and high.
     * @param value A value of arbitrary type.
     * @param low A lower limit of arbitrary type.
     * @param high An upper limit of arbitrary type.
     * @return max(value, low) if value < high or min(value, high) otherwise
     */
    template<class T>
    static constexpr const T& clamp(const T& value, const T& low, const T& high)
    {
        assert(!(high < low));
        return (value < low) ? low : (high < value) ? high : value;
    }
};
