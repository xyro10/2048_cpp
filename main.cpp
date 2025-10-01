#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void jadval(int game[4][4]);
char move();
void moveLeft(int game[4][4]);
void moveRight(int game[4][4]);
void moveUp(int game[4][4]);
void moveDown(int game[4][4]);
void randFirstNum(int game[4][4]);
void randContinueNum(int game[4][4]);
bool isWinLose(int game[4][4]);


void jadval(int game[4][4]) {    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "-------";
        }
        cout << "-" << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << "| " << setw(4) << game[i][j] << " ";
        }
        cout << "|" << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << "-------";
        }
        cout << "-" << endl;
    }
}