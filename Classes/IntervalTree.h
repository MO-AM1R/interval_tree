# ifndef INTERVALTREE_H
# define INTERVALTREE_H
#include <iostream>

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

    static bool overlap(const Interval* interval1, const  Interval* interval2) {
        return interval1->getLow() <= interval2->getHigh()
            && interval2->getLow() <= interval1->getHigh() ;
    }

    static Node* insert(Node* traverse, Interval* interval){
        if (!traverse) {
            traverse = new Node(interval, interval->getHigh()) ;
            return traverse;
        }

        if (traverse->getInterval()->getLow() <= interval->getLow()) {
            traverse->setRight(insert(traverse->getRight(), interval)) ;
        }
        else {
            traverse->setLeft(insert(traverse->getLeft(), interval)) ;
        }

        if (traverse->getMax() <= interval->getHigh()) {
            traverse->setMax(interval->getHigh());
        }

        return traverse;
    }

    static void inOrder(const Node* traverse){
        if (!traverse) {
            return;
        }
        inOrder(traverse->getLeft()) ;

        std::cout << "[" << traverse->getInterval()->getLow() << ", "
        << traverse->getInterval()->getHigh() << "]" << ", max -> "
        << traverse->getMax() << '\n' ;

        inOrder(traverse->getRight()) ;
    }

public:
    IntervalTree() = default; /// default constructor

    void insert(Interval* interval) { /// insert function to insert new interval
        root = insert(root, interval) ;
    }

    Interval search(const Interval interval) const{ /// search function to search for the interval
    }

    void inOrder() const {
        inOrder(root);
    }
};

# endif //INTERVALTREE_H