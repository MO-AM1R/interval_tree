# ifndef INTERVALTREE_H
# define INTERVALTREE_H
# include "Node.h"

/**
 * @brief {
 *      Class IntervalTree
 *      represent the interval tree
 *      it has an @see {class Node} @code {root}
 * }
 * @authors Mohamed Amir
 * @version 1.0
 */
class IntervalTree {
    Node* root ;

public:
    IntervalTree() = default; /// default constructor

    void insert(const Interval interval) { /// insert function to insert new interval

    }

    Interval search(const Interval interval) const{ /// search function to search for the interval

    }
};

# endif //INTERVALTREE_H