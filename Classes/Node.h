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
 * @author Mohamed Amir
 * @version 1.0
 */
class Node {
    Interval* interval ; /// the node interval
    int max ; /// the max of the (high, max of the left node, max of the right node)
    Node* left, *right ; /// the left and right children

public:
    Node() = default ; /// default constructor

    /// parameterized constructor to initialize the @code {interval}
    explicit Node(Interval* interval_) : interval(interval_), max(0), left(nullptr), right(nullptr) {}

    /**
     * \brief parameterized constructor to initialize @code {interval, max}
     * \param interval_ the interval parameter
     * \param max the max value of the interval
     */
    Node(Interval* interval_, const int max) : interval(interval_), max(max), left(nullptr), right(nullptr) {}

    /**
     * \brief parameterized constructor to initialize @code {interval, max, left, right}
     * \param interval_ the interval parameter
     * \param max the max value of the interval
     * \param l the left child of the node
     * \param r the left right of the node
     */
    Node(Interval* interval_, const int max, Node* l, Node* r) : interval(interval_), max(max), left(l), right(r) {}

    /**
     * \brief getter to get the interval
     * \return Interval represent the interval of the node
     */
    [[nodiscard]] Interval* getInterval() const {return interval;}

    /**
     * \brief getter to get the max
     * \return int represent the max of the node
     */
    [[nodiscard]] int getMax() const {return max;}

    /**
     * \brief getter to get the left node
     * \return Node represent the left child of the node
     */
    [[nodiscard]] Node * getLeft() const {return left;}

    /**
     * \brief getter to get the right node
     * \return Node represent the right child of the node
     */
    [[nodiscard]] Node * getRight() const {return right;}

    /**
     * \brief setter to set the interval
     */
    void setInterval(Interval* interval) {this->interval = interval;}

    /**
     * \brief setter to set the max
     */
    void setMax(const int max) {this->max = max;}

    /**
     * \brief setter to set the left nodel
     */
    void setLeft(Node * const left) {this->left = left;}

    /**
     * \brief setter to set the right node
     */
    void setRight(Node * const right) {this->right = right;}

    /// destructor to remove the data from memory
    ~Node() {
        delete left ;
        delete right ;
        delete interval ;
    }
};

# endif //NODE_H