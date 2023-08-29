#include "edge.h"
using namespace Space;

template <class T>
void Edge<T>::set_weight(T start_weight) {
	weight = start_weight;
}

template <class T>
T Edge<T>::get_weight() {
	return weight;
}

//The explicit instantiation part
template class Edge<int>;