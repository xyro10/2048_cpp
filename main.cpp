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
