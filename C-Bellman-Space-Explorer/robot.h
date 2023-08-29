#pragma once
#ifndef ROBOT_H
#define ROBOT_H

#include <string>
using namespace std;
namespace Space
{
    template <class T>
    class Robot
    {
        T *x, *y;
        int *direction;
        public:
            void set_origin(T &start_x, T &start_y, int &start_direction);
            void turn_left();
            void turn_right();
            void move_forward();
            string get_direction_str();
            T get_x();
            T get_y();
            T get_direction();
    };

}

#endif