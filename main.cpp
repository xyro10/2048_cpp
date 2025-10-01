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

char move()
{
    char move = '0';
    do
    {
        cin >> move;
        if (move != '1' && move != '2' && move != '3' && move != '4')
            cout << "Invalid move!" << endl;
    } while (move != '1' && move != '2' && move != '3' && move != '4');
    return move;
}

void moveLeft(int game[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int position = 0;
        for (int j = 0; j < 4; j++)
        {
            if (game[i][j] != 0)
            {
                game[i][position] = game[i][j];
                if (position != j)
                {
                    game[i][j] = 0;
                }
                position++;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (game[i][j] == game[i][j + 1] && game[i][j] != 0)
            {
                game[i][j] *= 2;
                game[i][j + 1] = 0;
                j++;
            }
        }
        position = 0;
        for (int j = 0; j < 4; j++)
        {
            if (game[i][j] != 0)
            {
                game[i][position] = game[i][j];
                if (position != j)
                {
                    game[i][j] = 0;
                }
                position++;
            }
        }
    }
}

void moveRight(int game[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int position = 3;
        for (int j = 3; j >= 0; j--)
        {
            if (game[i][j] != 0)
            {
                game[i][position] = game[i][j];
                if (position != j)
                {
                    game[i][j] = 0;
                }
                position--;
            }
        }
        for (int j = 3; j > 0; j--)
        {
            if (game[i][j] == game[i][j - 1] && game[i][j] != 0)
            {
                game[i][j] *= 2;
                game[i][j - 1] = 0;
                j--;
            }
        }
        position = 3;
        for (int j = 3; j >= 0; j--)
        {
            if (game[i][j] != 0)
            {
                game[i][position] = game[i][j];
                if (position != j)
                {
                    game[i][j] = 0;
                }
                position--;
            }
        }
    }
}

void moveUp(int game[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        int position = 0;
        for (int i = 0; i < 4; i++)
        {
            if (game[i][j] != 0)
            {
                game[position][j] = game[i][j];
                if (position != i)
                {
                    game[i][j] = 0;
                }
                position++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (game[i][j] == game[i + 1][j] && game[i][j] != 0)
            {
                game[i][j] *= 2;
                game[i + 1][j] = 0;
                i++;
            }
        }
        position = 0;
        for (int i = 0; i < 4; i++)
        {
            if (game[i][j] != 0)
            {
                game[position][j] = game[i][j];
                if (position != i)
                {
                    game[i][j] = 0;
                }
                position++;
            }
        }
    }
}

void moveDown(int game[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        int position = 3;
        for (int i = 3; i >= 0; i--)
        {
            if (game[i][j] != 0)
            {
                game[position][j] = game[i][j];
                if (position != i)
                {
                    game[i][j] = 0;
                }
                position--;
            }
        }
        for (int i = 3; i > 0; i--)
        {
            if (game[i][j] == game[i - 1][j] && game[i][j] != 0)
            {
                game[i][j] *= 2;
                game[i - 1][j] = 0;
                i--;
            }
        }
        position = 3;
        for (int i = 3; i >= 0; i--)
        {
            if (game[i][j] != 0)
            {
                game[position][j] = game[i][j];
                if (position != i)
                {
                    game[i][j] = 0;
                }
                position--;
            }
        }
    }
}

void randFirstNum(int game[4][4])
{
    int emptyplace[16][2] = {}, empty = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game[i][j] == 0)
            {
                emptyplace[empty][0] = i;
                emptyplace[empty][1] = j;
                empty++;
            }
        }
    }

    for (int count = 0; count < 2; count++)
    {
        int random = rand() % empty;
        int radif = emptyplace[random][0];
        int suton = emptyplace[random][1];
        game[radif][suton] = (rand() % 25 == 0) ? 4 : 2;
        emptyplace[random][0] = emptyplace[empty - 1][0];
        emptyplace[random][1] = emptyplace[empty - 1][1];
        empty--;
    }
}