# ifndef NODE_H
# define NODE_H
# include "Interval.h"

/**
 * @brief {
 *      Class Node
 *      represent the tree Node
 *      it has an interval, max value
 *      and a left and right children
 * }
 * @authors Mohamed Amir
 * @version 1.0
 */

class Node {
    Interval interval ; /// the node interval
    int max ; /// the max of the (high, max of the left node, max of the right node)
    Node* left, *right ; /// the left and right children

public:
    Node() = default ; /// default constructor

    /// some parameterized constructor
    explicit Node(const Interval interval_) : interval(interval_), max(0), left(nullptr), right(nullptr) {}
    Node(const Interval interval_, const int max) : interval(interval_), max(max), left(nullptr), right(nullptr) {}
    Node(const Interval interval_, const int max, Node* l, Node* r) : interval(interval_), max(max), left(l), right(r) {}

    [[nodiscard]] Interval getInterval() const {return interval;} /// getter to get the interval
    [[nodiscard]] int getMax() const {return max;} /// getter to get the max
    [[nodiscard]] Node * getLeft() const {return left;} /// getter to get the left node
    [[nodiscard]] Node * getRight() const {return right;} /// getter to get the right node

    void setInterval(const Interval &interval) {this->interval = interval;} /// setter to set the interval
    void setMax(const int max) {this->max = max;} /// setter to set the max
    void setLeft(Node * const left) {this->left = left;} /// setter to set the left node
    void setRight(Node * const right) {this->right = right;} /// setter to set the right node
};

# endif //NODE_H