#pragma once
#ifndef MAP_H
#define MAP_H

#include "edge.h"

namespace Space
{
    template <class T>
    class Map
    {
        Edge<T> **edges;
        const int *size;
    public:
        void create_map(const int &start_size);
        Edge<T>** get_map();
        void print_map();
    };

}

#endif