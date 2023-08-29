#include "robot.h"
#include "compass.h"
#include <iostream>
using namespace Space;
using namespace std;

//NOTE: string header file has been included in robot.h

const string compass_str[4] = { "NORTH", "EAST", "SOUTH", "WEST"};

template <class T>
void Robot<T>::set_origin(T &start_x, T &start_y, int &start_direction) {
	x = &start_x;
	y = &start_y;
	direction = &start_direction;
}

template <class T>
void Robot<T>::turn_left() {
	//Force bearing back to positive number again
	if ((*direction - 1) == -1) {
		*direction = COMPASS::WEST;
	}
	else {
		*direction = (*direction - 1) % 4;
	}
	cout << "Turn left" << '\n';
}

template <class T>
void Robot<T>::turn_right() {
	*direction = (*direction + 1) % 4;
	cout << "Turn right" << '\n';
}

template <class T>
void Robot<T>::move_forward() {
	if (*direction == COMPASS::NORTH) {
		*y += 1;
	}
	else if (*direction == COMPASS::EAST) {
		*x += 1;
	}
	else if (*direction == COMPASS::SOUTH) {
		*y -= 1;
	} 
	else if (*direction == COMPASS::WEST) {
		*x -= 1;
	}
	cout << "Move forward" << '\n';
};

template <class T>
T Robot<T>::get_x() {
	return *x;
};

template <class T>
T Robot<T>::get_y() {
	return *y;
};

template <class T>
T Robot<T>::get_direction() {
	return *direction;
};

template <class T>
string Robot<T>::get_direction_str() {
	return compass_str[*direction];
};

//The explicit instantiation part
template class Robot<int>;