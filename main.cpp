# include "Classes/IntervalTree.h"

int main() {
    Interval* intervals[] = {new Interval(15, 20), new Interval(10, 30), new Interval(17, 19),
        new Interval(5, 20), new Interval(12, 15), new Interval(30, 40)};

    auto* tree = new IntervalTree() ;

    for (auto & interval : intervals)
        tree->insert(interval) ;

    tree->inOrder() ;

    const Interval* searchList[] = {new Interval(6, 7), new Interval(1, 2), new Interval(10, 50),
        new Interval(12, 17), new Interval(4, 10), new Interval(-50, 10)};

    // should print {[5, 20], No, No, [15, 20], [10, 30], [10, 30]}
    for (auto & interval : searchList) {
        std::cout << "\nSearching for interval [" << interval->getLow() << "," << interval->getHigh() << "]";

        if (const Interval* result = tree->search(interval); result == nullptr)
            std::cout << "\nNo Overlapping Interval";
        else
            std::cout << "\nOverlaps with [" << result->getLow() << ", " << result->getHigh() << "]";
    }

    return 0;
}
