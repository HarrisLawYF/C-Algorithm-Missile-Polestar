#include "map.h"
#include <random>
#include <iostream>

using namespace Space;
using namespace std;

// Declare a class template
template <bool is_integral, typename T> struct uniform_distribution_selector;

// Specialize for true
template <typename T> struct uniform_distribution_selector<true, T>
{
	using type = typename uniform_int_distribution<T>;
};

// Specialize for false
template <typename T> struct uniform_distribution_selector<false, T>
{
	using type = typename uniform_real_distribution<T>;
};

template <class T>
void Map<T>::create_map(const int &start_size) {
	size = &start_size;
	edges = new Edge<T>*[start_size];
	//Generate a seed using time so we won't get same number
	random_device r;
	// or default_random_engine eng{static_cast<long unsigned int>(time(0))};
	default_random_engine eng{ r() };
	using uniform_distribution_type = typename uniform_distribution_selector<std::is_integral<T>::value, T>::type;
	uniform_distribution_type urd(1, start_size);
	for (T x = 0; x <= start_size; x++)
	{
		edges[x] = new Edge<T>[start_size];
		for (T y = 0; y <= start_size; y++)
		{
			edges[x][y].set_weight(urd(eng));
		}
	}
}

template <class T>
Edge<T>** Map<T>::get_map() {
	return edges;
}

template <class T>
void Map<T>::print_map() {
	for (T x = 0; x <= *size; x++)
	{
		for (T y = 0; y <= *size; y++)
		{
			cout << x << "," << y << ": " << edges[x][y].get_weight() << '\n';
			cout << "------------------------------" << '\n';
		}
	}
}

//The explicit instantiation part
template class Map<int>;
//TODO: array can't take in decimal values
//template class Map<float>;
//template class Map<double>;