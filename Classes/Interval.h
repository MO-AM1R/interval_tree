# ifndef INTERVAL_H
# define INTERVAL_H

/**
 * @brief {
 *      Class Interval
 *      represent the interval [low, high] e.g. [5, 10]
 * }
 * @author Mohamed Amir
 * @version 1.0
 */
class Interval {
    int low, high ; /// low, and high represent the interval endpoints

public:
    Interval() = default ; /// default constructor

    /**
     * \brief parameterized constructor to initialize @code {low, high}
     * \param l the low of the interval
     * \param h the high of the interval
     */
    explicit Interval(const int l, const int h) : low(l), high(h) {} /// parameterized constructor

    /**
     * \brief getter to get the low
     * \return int represent the low of the interval
     */
    [[nodiscard]] int getLow() const {return low ;}

    /**
     * \brief getter to get the high
     * \return int represent the high of the interval
     */
    [[nodiscard]] int getHigh() const {return high ;}

    ~Interval() = default ; /// default destructor
};

# endif //INTERVAL_H