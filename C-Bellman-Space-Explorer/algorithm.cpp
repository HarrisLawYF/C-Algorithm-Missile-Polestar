#include "algorithm.h"
#include <random>

using namespace Space;

template <class Edge, class Robot, class T>
void Algorithm<Edge, Robot, T>::move_robot(Robot &robot) {}

template <class Edge, class Robot, class T>
void Algorithm<Edge, Robot, T>::find_best_path(Edge** edges, int map_size, Robot& robot) {}


//The explicit instantiation part
template class Algorithm<Edge<int>, Robot<int>, int>;