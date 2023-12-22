# ifndef INTERVALTREE_H
# define INTERVALTREE_H
# include "Node.h"
# include <iostream>

/**
 * @brief {
 *      Class IntervalTree
 *      represent the interval tree
 *      it has an @see {class Node} @code {root}
 * }
 * @author Mohamed Amir
 * @version 1.0
 */
class IntervalTree {
    Node* root ;

    /**
     * \brief overlap method check if the intervals overlap or not
     * \param interval1 represent the first interval
     * \param interval2 represent the second interval
     * \return a boolean value if the
     *          @code {if the intervals overlap it return true}
     *          @code {if the intervals don't overlap it return false}
     */
    static bool overlap(const Interval* interval1, const Interval* interval2) {
        /// if the first interval low smaller than or qual second interval high
        /// and the second interval low smaller than or qual first interval high
        /// then the intervals overlap
        return interval1->getLow() <= interval2->getHigh()
            && interval2->getLow() <= interval1->getHigh() ;
    }

    /**
     * \brief iinsert method insert the new interval
     * \param traverse represent the root of the tree
     * \param interval represent the new interval which wll be inserted
     * \return Node represent the new root for the tree after the insertion
     * @overload {insert}
     */
    static Node* insert(Node* traverse, Interval* interval){
        /// the base case if the traverse node is null
        /// then create a new node and return it
        if (!traverse) {
            traverse = new Node(interval, interval->getHigh()) ;
            return traverse;
        }

        /// if the low of new interval greater than or equal the low of travese interval
        /// then go right
        if (traverse->getInterval()->getLow() <= interval->getLow()) {
            traverse->setRight(insert(traverse->getRight(), interval)) ;
        }
        /// else then go right
        else {
            traverse->setLeft(insert(traverse->getLeft(), interval)) ;
        }

        /// if the max of new interval greater than the max of travese interval
        /// then update the the max of travese interval
        if (traverse->getMax() < interval->getHigh()) {
            traverse->setMax(interval->getHigh());
        }

        return traverse;
    }

    /**
     * \brief inOrder function prints the nodes in order
     * \param traverse represent the root of the tree
     * @overload {inOder}
     */
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

    /**
     * \brief insert wrapper function to insert new interval
     * \param interval represent the new interval which will be inserted
     */
    void insert(Interval* interval) {
        root = insert(root, interval) ;
    }

    /**
     * \brief search function to search for the interval
     * \param interval represent the interval which will searched for
     * \return return minimum low that overlaps with the interval (if exists).
     */
    Interval* search(const Interval* interval) const{
        const auto * traverse = root;

        while (traverse && !overlap(traverse->getInterval(), interval)) {
            if (traverse->getLeft() && traverse->getLeft()->getMax() >= interval->getLow()) {
                traverse = traverse->getLeft() ;
            }
            else {
                traverse = traverse->getRight() ;
            }
        }

        return traverse == nullptr ? nullptr : traverse->getInterval() ;
    }

    /**
     * \brief inOrder wrapper function to prints the tree
     */
    void inOrder() const {
        inOrder(root);
    }

    /**
     * \brief destructor to remove the data from memory
     */
    ~IntervalTree() {
        delete root ;
    }
};

# endif //INTERVALTREE_H