# include "Classes/IntervalTree.h"

int main() {
    Interval* intervals[] = {new Interval(15, 20), new Interval(10, 30), new Interval(17, 19),
        new Interval(5, 20), new Interval(12, 15), new Interval(30, 40)};

    auto* tree = new IntervalTree() ;

    for (auto & interval : intervals)
        tree->insert(interval) ;

    tree->inOrder() ;

    return 0;
}
