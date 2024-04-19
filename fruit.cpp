#include <vector>
#include <iostream>

using namespace std;


class Fruit {
    public:
        vector<int> position = {rand() % 20, rand() % 20};


        void newFruit() {
            position = {rand() % 20, rand() % 20};
            if(position[0] == 0 || position[1] == 0 || position[0] == 20 || position[1] == 20) {
            position = {rand() % 20, rand() % 20};
            }
        }

};