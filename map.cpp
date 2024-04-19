#include <vector>
#include <iostream>

using namespace std;

class Map {
    public:
        int width = 20;
        int height = 20;

        void render(vector<int> playerPosition, int size, vector<int> fruitPos) {
        
             for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            if (i == 0 || i == height || j == 0 || j == width) {
                cout << "# ";
            }
            else if(i == fruitPos[0] && j == fruitPos[1]) {
                cout << "F ";
            }

         else if (i == playerPosition[0] && j >= playerPosition[1] && j < playerPosition[1] + size) {
                cout << "P ";                    
            }
            else {
                cout << "  ";
            }
        }
        cout << "\r\n";
    }

        }


};