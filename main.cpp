#include <iostream>
#include <vector>
#include "snake.cpp"
#include "map.cpp"
#include <conio.h>
#include "fruit.cpp" 
using namespace std;


bool gameOver = false;
Map map;
Snake mainCharacter;
Fruit fruit;

void render() {
    system("cls");
    if(mainCharacter.position[0] == 0 || mainCharacter.position[0] == 20 || mainCharacter.position[1] == 0 || mainCharacter.position[1] == 20) {
        gameOver = true;
    } else {
    map.render(mainCharacter.position, mainCharacter.size, fruit.position);
    cout << "PLAYER POSITION: " << mainCharacter.position[0] << " | " << mainCharacter.position[1] << endl;
    cout << "FRUIT POSITION: " << fruit.position[0] << " | " << fruit.position[1] << endl;
    }
}


int main() {
mainCharacter.position = { map.width/2, map.height/2};
    render();
    while(!gameOver) {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                    mainCharacter.position[1]--;
                    render();
                    break;
                case 'd':
                    mainCharacter.position[1]++;
                    render();
                    break;
                case 'w':
                    mainCharacter.position[0]--;
                    render();
                    break;
                case 's':
                    mainCharacter.position[0]++;
                    render();
                    break;
                case 'x':
                    gameOver = true;
                    break;
            }
        }

        if(mainCharacter.position[0] == fruit.position[0] && mainCharacter.position[1] == fruit.position[1]){
            mainCharacter.size += 1;
            fruit.newFruit();
            render();
        }
    }

    system("pause");
    return 0;
}