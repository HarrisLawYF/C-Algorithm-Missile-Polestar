#pragma once
#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "edge.h"
#include "robot.h"

namespace Space
{
    template <class Edge, class Robot, class T>
    class Algorithm
    {
    public:
        virtual void move_robot(Robot &robot);
        virtual void find_best_path(Edge **edges, int map_size, Robot &robot);
    };
}

#endif