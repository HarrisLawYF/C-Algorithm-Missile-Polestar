#pragma once
#ifndef GREEDY_H
#define GREEDY_H
#include "algorithm.h"
namespace Space
{
    template <class Edge, class Robot, class T>
    class Greedy : public Algorithm<Edge, Robot, T>{
    public:
        virtual void move_robot(Robot& robot, bool move_x, bool move_y);
        virtual void find_best_path(Edge **edges, int map_size, Robot &robot);
    };
}

#endif