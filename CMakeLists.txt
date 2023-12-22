cmake_minimum_required(VERSION 3.27)
project(Interval_Tree)

set(CMAKE_CXX_STANDARD 23)

add_executable(Interval_Tree main.cpp
        Classes/IntervalTree.h
        Classes/Node.h
        Classes/Interval.h)
