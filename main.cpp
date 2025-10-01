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

int main()
{
    int game[4][4] = {};
    char inputmove = '0';
    bool isEnd = false;
    srand(time(0));
    randFirstNum(game);
    while (!isEnd)
    {
        system("cls");
        jadval(game);
        cout << endl << "Enter move (1 for left / 2 for right / 3 for up / 4 for down): ";
        inputmove = move();
        switch (inputmove)
        {
        case '1': moveLeft(game); 
            break;
        case '2': moveRight(game);
            break;
        case '3': moveUp(game); 
            break;
        case '4': moveDown(game);
            break;
        }
        randContinueNum(game);
        isEnd = isWinLose(game);
        if (isEnd)
        {
            jadval(game);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (game[i][j] == 2048)
                    {
                        cout << "U Win!" << endl;
                        return 0;
                    }
                }
            }
            cout << "U Lost!" << endl;
        }
    }
    return 0;
}


// رسم محیط بازی
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

// گرفتن حرکت از کاربر
// 1: left, 2: right, 3: up, 4: down
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

// حرکت به چپ   
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

// حرکت به راست
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

// حرکت به بالا
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

// حرکت به پایین
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

// قرار دادن دو عدد تصادفی 2 یا 4 در خانه های خالی در ابتدا
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

// قرار دادن یک عدد تصادفی 2 یا 4 در خانه های خالی بعد از هر حرکت
void randContinueNum(int game[4][4])
{
    int emptyplace[16][2] = {};
    int empty = 0;
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
    if (empty > 0)
    {
        int random = rand() % empty;
        int radif = emptyplace[random][0];
        int suton = emptyplace[random][1];
        game[radif][suton] = (rand() % 2 + 1) * 2;
    }
}

// بررسی برد یا باخت
bool isWinLose(int game[4][4])
{
    bool full = true;
    bool win = false;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game[i][j] == 0)
            {
                full = false;
                break;
            }
            if (game[i][j] == 2048)
            {
                win = true;
            }
        }
        if (!full)
        {
            break;
        }
    }
    if (win)
    {
        return true;
    }

    if (full)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i < 3 && game[i][j] == game[i + 1][j])
                    return false;
                if (j < 3 && game[i][j] == game[i][j + 1])
                    return false;
            }
        }
        return true;
    }
    return false;
}