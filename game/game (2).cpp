#include <iostream>
#include <windows.h>
using namespace std;
int playerX = 4;
int playerY = 4;
char nextlocation;
int loginmenu();
void printMaze();
void gotoxy(int x,int y);
void printplayer();
void eraseplayer();
char getCharAtxy(short int x, short int y);
void moveplayerleft();
void moveplayerright();
void moveplayerup();
void moveplayerdown();
void movebullet();
main()
{
    bool running = true;
    system("cls");
    printMaze();
    printplayer();
    while (running)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveplayerleft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveplayerright();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveplayerup();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveplayerdown();
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            movebullet();
        }
         
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            running = false;
        }
        Sleep(200);
    }
}
int loginmenu()
{
    int option;
    cout << "1. for start " << endl;
    cout << "2.for option" << endl;
    cout << "3.for exit" << endl;
    cout << "Enter your option: ";
    cin >> option;
    return option;
}
void printMaze()
{
    cout << "##############################################################" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "#                                                            #" << endl;
    cout << "##############################################################" << endl;
}
void player()
{
    char character = 219;
}
void gotoxy(int x,int y)
{
    COORD coordinates;
    coordinates.X = playerX;
    coordinates.Y = playerY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void playermovement()
{
}
void moveplayerleft()
{

    nextlocation = getCharAtxy(playerX - 1, playerY);
    if (nextlocation == ' ')
    {
        eraseplayer();
        playerX--;
        printplayer();
    }
}
void moveplayerright()
{
    nextlocation = getCharAtxy(playerX + 1, playerY);
    if (nextlocation == ' ')
    {
        eraseplayer();
        playerX++;
        printplayer();
    }
}
void moveplayerup()
{

    nextlocation = getCharAtxy(playerX, playerY - 1);
    if (nextlocation == ' ')
    {
        eraseplayer();
        playerY--;
        printplayer();
    }
}
void moveplayerdown()
{

    nextlocation = getCharAtxy(playerX, playerY + 1);
    if (nextlocation == ' ')
    {
        eraseplayer();
        playerY++;
        printplayer();
    }
}
void eraseplayer()
{
    gotoxy(playerX,playerY);
    cout << " ";
}
void printplayer()
{
    gotoxy(playerX,playerY);
    cout << "p";
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x,y};
    COORD coordBufSize;
     coordBufSize.X=1;
     coordBufSize.Y=1;

    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize , xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void score()
{
    gotoxy;
}    
void movebullet()
{
    for(int col=0;col<63;col++)
    {
        for(int row=0;row<17;row--)
        {
          char current=getCharAtxy(col,row); 
          if(current=='.')
          {
            gotoxy(col,row);
            cout <<" ";
            gotoxy(col,row--);
            cout <<".";
          }

        }
    }
}
