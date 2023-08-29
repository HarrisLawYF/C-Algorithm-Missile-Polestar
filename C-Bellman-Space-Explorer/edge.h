#pragma once
#ifndef EDGE_H
#define EDGE_H

namespace Space
{
    template <class T>
    class Edge
    {
        T weight;
    public:
        void set_weight(T start_weight);
        T get_weight();
    };
}

#endif