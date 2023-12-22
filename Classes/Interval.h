# ifndef INTERVAL_H
# define INTERVAL_H

/**
 * @brief {
 *      Class Interval
 *      represent the interval [low, high] e.g. [5, 10]
 * }
 * @authors Mohamed Amir
 * @version 1.0
 */
class Interval {
    int low, high ; /// low, and high represent the interval endpoints

public:
    Interval() = default ; /// default constructor
    explicit Interval(const int l, const int h) : low(l), high(h) {} /// parameterized constructor

    int getLow() const {return low ;} /// getter to get the interval low
    int getHigh() const {return high ;} /// getter to get the interval high
};

# endif //INTERVAL_H