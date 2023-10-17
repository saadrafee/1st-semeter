#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;
char player[3][3];
void gotoxy(int x, int y);
void load();
string loaddata(string line, int num);
int x = 20;
int y = 20;
int playerX=15;
int playerY=15;
main()
{
    system("cls");
    load();
}
void load()
{
    string line;
    fstream file;
    int row = 0;
    int chara;

    file.open("player.txt", ios ::in);
    while (getline(file, line))
    {
        for (int col = 0; col < 3; col++)
        {
            chara = stoi(loaddata(line, col));
            player[row][col] = chara;
        }
        row++;
    }
    file.close();
}
string loaddata(string line, int num)
{
    int commacount = 0;
    string word = "";
    int index = line.length();

    for (int idx = 0; idx < index; idx++)
    {
        if (line[idx] == ',')
        {
            commacount++;
            continue;
        }
        else if (commacount == num)
        {
            word = word + line[idx];
        }
    }

    return word;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printplayer()
{

    for (int row = 0; row < 3; row++)
    {
        gotoxy(playerX, playerY);
        for (int col = 0; col < 3; col++)
        {
            cout << player[row][col];
        }
        playerY++;
    }

}
void eraseplayer()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(playerX, playerY);
        for (int col = 0; col < 3; col++)
        {
            cout << erase[row][col];
        }
        playerY++;
    }
}