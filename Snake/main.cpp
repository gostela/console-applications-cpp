#include <conio.h>
#include <bits/stdc++.h>
using namespace std;


bool pause = false;
bool gameOver, s = false, Wall = false;
int width = 40;
int height = 20;
int fruitX, fruitY, score, speed = 25, wall, rule = 0;
double x, y;
int tailx[100], taily[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % (width-1);
    fruitY = rand() % (height-1);
    score = 0;
}

void Draw()
{
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < width + 1; i++)
    {cout << "#";}
    cout << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0 || j == width - 1) cout << "#";
                if (i == y && j == x) cout << "0";
                else if (i == fruitY && j == fruitX) {cout << "@";}

                else
                {
                        bool print = false;
                        for (int k = 0; k < nTail; k++)
                        {
                            if (tailx[k] == j && taily[k] == i)
                            {
                            cout << "o";
                            print = true;
                            }
                        }
                        if (print == false) cout << " ";
                }
            }
            cout << endl;
        }
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
    if (score <= 0)
        score = 0;
    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'e':
    if (pause == false)
    {
        pause = true; cout << endl << "PAUSE";
    }
    else
        pause = false;
                
        }
    }
}
void start()
{
    if (_kbhit())
    {
        switch(_getch())
        {
        case 'c':
            cout << endl << "Speed:  ";
            cin >> speed;
            cout << endl << "Width: ";
            cin >> width;
            cout << endl << "Height: ";
            cin >> height;
            cout << endl << "Wall (0 / 1) : ";
            cin >> wall;
            if (wall == 1) Wall = true;
            cout << endl << "Rule (0 / 1) : ";
            cin >> rule;
            s = true;
            break;

        case 'l':
            cout << endl << "w - up" << endl
            << "s - down" << endl
            << "a - left" << endl
            << "d - right" << endl
            << "e - pause" << endl
            << "x - exit" << endl
            << "c - Settings" << endl
            << "l - this page";
            break;
        case 't':
            cout << endl << "                                   3...";
            Sleep(1000);
            cout << endl << "                                   2...";
            Sleep(1000);
            cout << endl << "                                   1...";
            Sleep(1000);
            cout << endl << "                                    Go";
            Sleep(1000);
            s = true;
            }
        }
    }
void Logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:;
        y++;
        break;
    }

    if (wall == false) {if (x >= width || x < 0 || y >= height || y < 0) gameOver = true;} // easy
    else {if (x >= width-1) x = 0;
    else if (x < 0) x = width-1;
