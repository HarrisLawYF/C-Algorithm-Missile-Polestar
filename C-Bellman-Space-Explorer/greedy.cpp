#include "greedy.h"
#include "compass.h"
#include <iostream>
using namespace Space;
using namespace std;

template <class Edge, class Robot, class T>
void Greedy<Edge, Robot, T>::move_robot(Robot &robot, bool move_x, bool move_y) {
	//This is because we are always travelling from left corner to right corner
	if (move_x == true) {
		if (robot.get_direction() == COMPASS::NORTH) {
			robot.turn_right();
			robot.move_forward();
		}
		else if (robot.get_direction() == COMPASS::EAST) {
			robot.move_forward();
		}
		else if (robot.get_direction() == COMPASS::SOUTH) {
			robot.turn_left();
			robot.move_forward();
		}
		else {
			robot.turn_right();
			robot.turn_right();
			robot.move_forward();
		}
	}
	
	if (move_y == true) {
		if (robot.get_direction() == COMPASS::NORTH) {
			robot.move_forward();
		}
		else if (robot.get_direction() == COMPASS::EAST) {
			robot.turn_left();
			robot.move_forward();
		}
		else if (robot.get_direction() == COMPASS::SOUTH) {
			robot.turn_left();
			robot.turn_left();
			robot.move_forward();
		}
		else {
			robot.turn_right();
			robot.move_forward();
		}
	}
	cout << "Robot moving to (x,y): " << robot.get_x() << "," << robot.get_y() << '\n';
}

template <class Edge, class Robot, class T>
void Greedy<Edge, Robot, T>::find_best_path(Edge **edges, int map_size, Robot &robot) {
	if (robot.get_x() >= map_size && robot.get_y() >= map_size) {
		cout << "Robot has arrived to (x,y): " << robot.get_x() << "," << robot.get_y() << '\n';
	}
	else if (robot.get_x() >= map_size) {
		move_robot(robot, false, true);
		find_best_path(edges, map_size, robot);
	}
	else if (robot.get_y() >= map_size) {
		move_robot(robot, true, false);
		find_best_path(edges, map_size, robot);
	}
	else {
		if (edges[robot.get_x() + 1][robot.get_y()].get_weight() < edges[robot.get_x()][robot.get_y() + 1].get_weight()) {
			move_robot(robot, true, false);
		}
		else {
			move_robot(robot, false, true);
		}
		find_best_path(edges, map_size, robot);
	}
}

//The explicit instantiation part
template class Greedy<Edge<int>, Robot<int>, int>;