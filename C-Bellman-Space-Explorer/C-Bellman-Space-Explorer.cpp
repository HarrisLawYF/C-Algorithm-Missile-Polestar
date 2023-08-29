// C-Bellman-Space-Explorer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*



*/

#include <iostream>
#include <sstream>
#include "robot.h"
#include "map.h"
#include "greedy.h"
#include "compass.h"
#include "edge.h"

using namespace std;
using namespace Space;

int main()
{
    try {
        int size = 0;
        int x = 0;
        int y = 0;
        int direction = COMPASS::EAST;
        string input;

        cout << "Decide your map size \n";
        getline(cin, input);
        stringstream(input) >> size;

        cout << "Decide your initial X \n";
        getline(cin, input);
        stringstream(input) >> x;
        if (x < 0 || x > size) {
            x = 0;
        }

        cout << "Decide your initial Y \n";
        getline(cin, input);
        stringstream(input) >> y;
        if (y < 0 || y > size) {
            y = 0;
        }

        Map<int> map;
        map.create_map(size);

        Greedy<Edge<int>, Robot<int>, int> greedy;

        Robot<int> polestar;
        polestar.set_origin(x, y, direction);

        cout << "Map generated: \n";
        map.print_map();
        cout << "Start operation...\n";
        cout << "Polestar current direction: " << polestar.get_direction_str() << "\n";
        cout << "Polestar current coordinates (x,y): " << polestar.get_x() << "," << polestar.get_y() << "\n";
        cout << "---------------------------------------\n";
        greedy.find_best_path(map.get_map(), size, polestar);
    }
    catch(exception& e){
        cout << "Error: " << e.what() << "\n";
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add e
// xisting code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
