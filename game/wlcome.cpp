#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
//
char printMaze[30][75];
char erase[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};
char eraseLeader[4][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},

                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char enemyleader[4][8];
void printenemyLeader();
// test
char player[3][3];
void load();
string loaddata(string line, int num);
char loaddataChar(string line, int num);
void wlcome2();
void gotoxy(int x, int y);
void loading();
// menus
void mainmenu();
void header();
void option();
void keys();
void instruction();
// color
char nextlocation;
void red();
void green();
void blue();
void white();
// game data
void game();
void storeData();
// sataics
int score = 0;
int enemy1damage = 0;
int enemy2damage = 0;
int playerdamage = 0;
int enemyLeaderdamage = 0;
void addScore();
void addplayerdamage();
void addenemy1damage();
void addenemyLeaderdamage();
void printplayerdamage();
void printenemy1damage();
void addenemy2damage();
void printenemy2damage();
void printenemyLeaderdamage();
void printscore();
void printyouWin();
void youlosse();
// player
void printplayer();
char firstlayer = 202;
char middlelayer = 219;
char lastlayer = 203;
char first[3] = {' ', firstlayer, ' '};
char second[3] = {middlelayer, middlelayer, middlelayer};
char third[3] = {lastlayer, ' ', lastlayer};
void eraseplayer();
char getCharAtxy(short int x, short int y);
void moveplayerleft();
void moveplayerright();
void moveplayerup();
void moveplayerdown();
// palyer bullter
int bulletplayerx[200];
int bulletplayery[200];
void printbullet(int x, int y);
void createbullet();
void erasebullet(int x, int y);
int playerbulletidx = 0;
void movebullet();
int bulletcounter = playerbulletidx;
bool isBulletActive[200];
void makeBulletInactive(int x);
void deletbullet();
void bulletCollisionwithEnemy();
void bulletCollisionwithEnemyLeader();
// axsis
int playerX = 22;
int playerY = 19;
// enemy

void printenemy1();
int enemy1X = 2;
int enemy1Y = 3;
int enemyLeaderX = 5;
int enemyLeaderY = 5;
string direction = "right";
string directionLeader = "right";
void enemy1move();
void enemyLeadermove();
void printmaze();
void eraseenemy1();
void eraseenemyLeader();
int enemy1mov = 0;
// enemy 2
void printenemy2();
int enemy2X = 50;
int enemy2Y = 8;
string directionForE2 = "left";
void enemy2move();
void random();
void eraseenemy2();
void bulletCollisionwithEnemy2();
// enemy1 bullter
int bulletenemy1x[200];
int bulletenemy1y[200];
int enemy1bulletidx = 0;
void createbullet1();

void movebullet1();
bool makebulletenemy1active[200];
void Makebulletenemy1inactive(int x);
void bulletCollisionwithplayer();
// enemyLeader bullter
int bulletenemyLeaderx[200];
int bulletenemyLeadery[200];
int enemyLeaderbulletidx = 0;
void createbulletEnemyLeader();
int enemyLeaderTimer = 0;
void movebulletLeader();
bool makebulletenemyLeaderactive[200];
void MakebulletenemyLeaderinactive(int x);
// enemy2 bullter
int bulletenemy2x[200];
int bulletenemy2y[200];
void createbullet2();
int enemy2bulletidx = 0;
void movebullet2();
bool makebulletenemy2active[200];
void Makebulletenemy2inactive(int x);
// Pallets
void lifePallet();
int lifePalletX;
int lifePalletY = 2;
void PrintPallet();
void ereaseLifePallet();
void moveLifePallet();
bool lifeLifePallet = false;
void PalletCollisionwithplayer();
char life;
string palletType;
// timer
int enemy2timer = 0;
int rando = 0;
int lifePallettimer = 200;
void leaderEnemy();
// level
int timer = 10;
int leaderTime = 10;
int level = 1;
void youWin();
void printlevel();

void loadForContinue();
void newGame();
//higher socer
void loadHigherSocre();
void storeHigherSocre();
int higherSocre;
void printHigherScore();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    load();
    bool runing = true;
    wlcome2();
    mainmenu();
    int op;
    while (runing)
    {loadHigherSocre();
        header();
        mainmenu();
        cin >> op;
        if (op == 1)
        {
            loadForContinue();
            game();
        }
        if (op == 2)
        {
            newGame();
            game();
        }
        if (op == 3)
        {
            option();
        }
        if (op == 4)
        {
            runing = false;
        }
    }
}

void wlcome2()
{
    green();
    system("cls");
    string line;
    fstream file;
    int y = 1;

    file.open("Rocket.txt", ios::in);
    while (getline(file, line))
    {
        gotoxy(20, y);
        cout << line;
        y++;
    }
    file.close();

    white();
    loading();
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void loading()
{
    red();
    int x = 20;
    int y = 28;
    int ch = 219;
    char load = ch;
    gotoxy(x, y);
    cout << "l o a d i n g";

    for (int idx = x; idx < 33; idx++)
    {
        Sleep(100);
        gotoxy(idx, y);
        cout << load;
        Sleep(150);
    }
    white();
}
void mainmenu()
{
    header();

    cout << endl;
    cout << "1. Continue " << endl;
    cout << "2. Start New Game " << endl;
    cout << "3. Option " << endl;
    cout << "4. Exit " << endl;

    cout << "Enter one option " << endl;
}
void header()
{
    blue();
    char dash = 196;
    system("cls");

    string line;
    fstream file;
    file.open("header.txt", ios::in);
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    white();
    cout << "menu ." << endl;
    for (int idx = 0; idx < 20; idx++)
    {
        cout << dash;
    }
    cout << endl;
    white();
}
void red()
{
    SetConsoleTextAttribute(h, 4);
}
void green()
{
    SetConsoleTextAttribute(h, 10);
}
void blue()
{
    SetConsoleTextAttribute(h, 3);
}
void white()
{
    SetConsoleTextAttribute(h, 15);
}
void option()
{

    blue();
    int op;
    bool runing = true;
    while (runing)
    {
        header();
        cout << "1. Keys " << endl;
        cout << "2. instruction " << endl;
        cout << "3. exit " << endl;
        cin >> op;
        if (op == 1)
        {
            keys();
        }
        if (op == 2)
        {
            instruction();
        }
        if (op == 3)
        {
            runing = false;
        }
    }
    white();
}
void keys()
{
    header();
    char up = 24;
    char down = 25;
    char right = 26;
    char left = 27;
    cout << "Press " << up << "         GO UP" << endl;
    cout << "Press " << down << "         GO DOWN" << endl;
    cout << "Press " << right << "         GO Right" << endl;
    cout << "press "
         << "-->"
         << "       GO left" << endl;
    cout << "press ESc              to exit " << endl;
    cout << endl
         << "press any key to continue......" << endl;
    getch();
}
void instruction()
{
    header();
    cout << "you are the captain of ship you " << endl;
    cout << "have to elminate all alien ships " << endl;
    cout << "by firing .first destory the tow alpha  " << endl;
    cout << "ships then leader of alien ship come  " << endl;
    cout << "you have have to elminate all alien ship  " << endl;
    cout << "to win the level as level increase diffculty   " << endl;
    cout << "increase  " << endl;
    cout << endl
         << "press any key to continue......" << endl;
    getch();
}
void game()
{
    bool running = true;
    system("cls");
    printmaze();
    printplayer();
    printenemy1();
    printenemy2();
    int timerp = 0;
    int palletmove = 10;
    int move = 0;
    
    while (running)

    {
        PalletCollisionwithplayer();
        if (timerp == lifePallettimer)
        {
            timerp = 0;
            lifePallet();

            lifeLifePallet = true;
        }
        if (palletmove == move)
        {
            if (lifeLifePallet == true)
            {

                moveLifePallet();
            }
            move = 0;
        }
        if (lifeLifePallet == true)
        {

            moveLifePallet();
        }
        move++;
        movebullet();
        storeData();
        if (enemy1damage <= 40)
        {
            bulletCollisionwithEnemy();
        }
        if (enemy2damage <= 40)
        {
            bulletCollisionwithEnemy2();
        }
        bulletCollisionwithplayer();

        printplayerdamage();

        movebullet1();
        movebullet2();
        movebulletLeader();

        if (enemy1mov == timer)
        {

            if (enemy1damage < 40)
            {
                enemy1move();

                createbullet1();
            }
            if (enemy1damage >= 40)
            {
                eraseenemy1();
            }
            if (enemy2damage < 40)
            {
                enemy2move();
                createbullet2();
            }
            if (enemy2damage >= 40)
            {
                eraseenemy2();
            }
            enemy1mov = 0;
        }
        if (rando == 50)
        {
            random();
            rando = 0;
        }

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
            createbullet();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            running = false;
        }
        if (enemy1damage >= 40 && enemy2damage >= 40)
        {
            printenemyLeader();
            bulletCollisionwithEnemyLeader();
            leaderEnemy();
        }

        if (enemyLeaderdamage >= 40)
        {
            youWin();
        }
        if (playerdamage >= 40)
        {
            newGame();
            storeData();
            youlosse();
            score = 0;
            running = false;
        }
        if(score >= higherSocre)
        {
            higherSocre = score;
        }
        printenemy1damage();
        printenemy2damage();
        printenemyLeaderdamage();
        printHigherScore();
        printlevel();
        enemy1mov++;
        enemy2timer++;
        timerp++;
        rando++;
        printscore();
 storeHigherSocre();
        Sleep(100);
    }
}
void printmaze()
{
    blue();
    system("cls");
    for (int idx = 0; idx < 30; idx++)
    {
        for (int idx2 = 0; idx2 < 75; idx2++)
        {
            cout << printMaze[idx][idx2];
        }
        cout << endl;
    }
    white();
}
void printenemy1()
{
    red();
    int y = enemy1Y;
    for (int row = 2; row >= 0; row--)
    {
        gotoxy(enemy1X, y);
        for (int col = 0; col < 3; col++)
        {
            cout << player[row][col];
        }
        y++;
    }
    white();
}
void leaderEnemy()
{
    if (timer == enemyLeaderTimer)
    {
        enemyLeadermove();
        createbulletEnemyLeader();

        enemyLeaderTimer = 0;
    }
    enemyLeaderTimer++;
}
void youWin()
{
    enemy1damage = 0;
    enemy2damage = 0;
    enemyLeaderdamage = 0;
    printyouWin();
    level++;
    timer = timer - 2;
    printmaze();
    printenemy2();
    printenemy1();
}
void moveplayerleft()
{

    nextlocation = getCharAtxy(playerX - 1, playerY);
    if (nextlocation == ' ' || nextlocation == '.')
    {
        eraseplayer();
        playerX--;
        printplayer();
    }
}
void moveplayerright()
{
    nextlocation = getCharAtxy(playerX + 3, playerY);
    if (nextlocation == ' ' || nextlocation == '.')
    {
        eraseplayer();
        playerX++;
        printplayer();
    }
}
void moveplayerup()
{

    nextlocation = getCharAtxy(playerX, playerY - 1);
    if (nextlocation == ' ' || nextlocation == '.')
    {
        eraseplayer();
        playerY--;
        printplayer();
    }
}
void moveplayerdown()
{

    nextlocation = getCharAtxy(playerX, playerY + 3);
    if (nextlocation == ' ' || nextlocation == '.')
    {
        eraseplayer();
        playerY++;
        printplayer();
    }
}
void eraseplayer()
{
    int y = playerY;
    for (int row = 0; row < 3; row++)
    {
        gotoxy(playerX, y);
        for (int col = 0; col < 3; col++)
        {
            cout << erase[row][col];
        }
        y++;
    }
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;

    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printplayer()
{
    green();
    int y = playerY;
    for (int row = 0; row < 3; row++)
    {
        gotoxy(playerX, y);
        for (int col = 0; col < 3; col++)
        {
            cout << player[row][col];
        }
        y++;
    }
    white();
}
void printenemyLeader()
{
    red();
    int y = enemyLeaderY;
    for (int row = 0; row < 4; row++)
    {
        gotoxy(enemyLeaderX, y);
        for (int col = 0; col < 8; col++)
        {
            cout << enemyleader[row][col];
        }
        y++;
    }
    white();
}
void enemy1move()
{
    char next;
    if (direction == "right")
    {
        next = getCharAtxy(enemy1X + 3, enemy1Y);
        if (next == ' ' || next == '.')
        {
            eraseenemy1();
            enemy1X++;
            gotoxy(enemy1X, enemy1Y);
            printenemy1();
        }
        else
        {
            direction = "left";
        }
    }
    if (direction == "left")
    {
        next = getCharAtxy(enemy1X - 1, enemy1Y);
        if (next == ' ' || next == '.')
        {
            eraseenemy1();
            enemy1X--;
            gotoxy(enemy1X, enemy1Y);
            printenemy1();
        }
        else
        {
            direction = "right";
        }
    }
}
void enemyLeadermove()
{
    char next;
    if (directionLeader == "right")
    {
        next = getCharAtxy(enemyLeaderX + 8, enemyLeaderY);
        if (next == ' ' || next == '.')
        {
            eraseenemyLeader();
            enemyLeaderX++;
            gotoxy(enemyLeaderX, enemyLeaderY);
            printenemyLeader();
        }
        else
        {
            directionLeader = "left";
        }
    }
    if (directionLeader == "left")
    {
        next = getCharAtxy(enemyLeaderX - 1, enemyLeaderY);
        if (next == ' ' || next == '.')
        {
            eraseenemyLeader();
            enemyLeaderX--;
            gotoxy(enemyLeaderX, enemyLeaderY);
            printenemyLeader();
        }
        else
        {
            directionLeader = "right";
        }
    }
}
void eraseenemy1()
{
    int y = enemy1Y;
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, y);
        for (int col = 0; col < 3; col++)
        {
            cout << erase[row][col];
        }
        y++;
    }
}
void eraseenemyLeader()
{
    int y = enemyLeaderY;
    for (int row = 0; row < 4; row++)
    {
        gotoxy(enemyLeaderX, y);
        for (int col = 0; col < 8; col++)
        {
            cout << eraseLeader[row][col];
        }
        y++;
    }
}
void createbullet()
{
    green();
    char next;
    char sample = 176;
    next = getCharAtxy(playerX, playerY - 1);
    if (next != sample)
    {
        bulletplayerx[playerbulletidx] = playerX + 1;
        bulletplayery[playerbulletidx] = playerY - 1;
        isBulletActive[playerbulletidx] = true;
        gotoxy(bulletplayerx[playerbulletidx],
               bulletplayery[playerbulletidx]);
        cout << ".";
        playerbulletidx++;
    }
}
void movebullet()
{

    for (int idx = 0; idx < playerbulletidx; idx++)
    {
        if (isBulletActive[idx] == true)
        {
            char next = getCharAtxy(bulletplayerx[idx], bulletplayery[idx] - 1);

            if (next != ' ')
            {
                erasebullet(bulletplayerx[idx], bulletplayery[idx]);
                makeBulletInactive(idx);
            }
            else
            {
                erasebullet(bulletplayerx[idx], bulletplayery[idx]);
                bulletplayery[idx] = bulletplayery[idx] - 1;
                printbullet(bulletplayerx[idx], bulletplayery[idx]);
            }
        }
    }
}
void erasebullet(int x, int y)
{

    gotoxy(x, y);
    cout << " ";
}
void printbullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void makeBulletInactive(int x)
{
    isBulletActive[x] = false;
}
void deletbullet()
{
    for (int idx = 0; idx < playerbulletidx - 1; idx++)
    {
        if (isBulletActive[idx] == false)
        {
            bulletplayerx[idx] = bulletplayerx[idx + 1];
            bulletplayery[idx] = bulletplayery[idx + 1];
        }
    }
    playerbulletidx--;
}
void bulletCollisionwithEnemy()
{
    for (int idx = 0; idx < playerbulletidx; idx++)
    {
        if (isBulletActive[idx] == true)
        {
            if (bulletplayery[idx] - 1 == enemy1Y + 2 && (bulletplayerx[idx] == enemy1X || bulletplayerx[idx] == enemy1X + 1 || bulletplayerx[idx] == enemy1X + 2))
            {
                addScore();
                addenemy1damage();
            }
        }
    }
}
void bulletCollisionwithEnemyLeader()
{
    for (int idx = 0; idx < playerbulletidx; idx++)
    {
        if (isBulletActive[idx] == true)
        {
            if (bulletplayery[idx] - 1 == enemyLeaderY + 4 && (bulletplayerx[idx] == enemyLeaderX ||
                                                               bulletplayerx[idx] == enemyLeaderX + 1 || bulletplayerx[idx] == enemyLeaderX + 2 || bulletplayerx[idx] == enemyLeaderX + 3 || bulletplayerx[idx] == enemyLeaderX + 4 || bulletplayerx[idx] == enemyLeaderX + 5 || bulletplayerx[idx] == enemyLeaderX + 6 || bulletplayerx[idx] == enemyLeaderX + 7 || bulletplayerx[idx] == enemyLeaderX + 8))
            {
                addScore();
                addenemyLeaderdamage();
            }
        }
    }
}
void addScore()
{
    score++;
}
void addenemy1damage()
{
    enemy1damage++;
}
void addenemyLeaderdamage()
{
    enemyLeaderdamage = enemyLeaderdamage + 1;
}
void printenemy2()
{
    red();
    int y = enemy2Y;
    for (int row = 2; row >= 0; row--)
    {
        gotoxy(enemy2X, y);
        for (int col = 0; col < 3; col++)
        {
            cout << player[row][col];
        }
        y++;
    }
    white();
}

void enemy2move()
{

    char next;
    if (directionForE2 == "right")
    {
        next = getCharAtxy(enemy2X + 3, enemy2Y);
        if (next == ' ')

        {
            eraseenemy2();
            enemy2X++;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
    }
    if (directionForE2 == "left")
    {
        next = getCharAtxy(enemy2X - 1, enemy2Y);
        if (next == ' ')
        {
            eraseenemy2();
            enemy2X--;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
    }
    if (directionForE2 == "up")
    {
        next = getCharAtxy(enemy2X, enemy2Y - 1);
        if (next == ' ')
        {
            eraseenemy2();
            enemy2Y--;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
    }
    if (directionForE2 == "down")
    {
        next = getCharAtxy(enemy2X, enemy2Y + 3);
        if (next == ' ')
        {
            eraseenemy2();
            enemy2Y++;
            gotoxy(enemy2X, enemy2Y);
            printenemy2();
        }
    }
}
void random()
{
    int x = rand() % 4;

    if (x == 0)
    {
        directionForE2 = "up";
    }

    if (x == 1)
    {
        directionForE2 = "down";
    }

    if (x == 2)
    {
        directionForE2 = "right";
    }

    if (x == 3)
    {
        directionForE2 = "left";
    }
}
void eraseenemy2()
{
    int y = enemy2Y;
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy2X, y);
        for (int col = 0; col < 3; col++)
        {
            cout << erase[row][col];
        }
        y++;
    }
}
void bulletCollisionwithEnemy2()
{
    for (int idx = 0; idx < playerbulletidx; idx++)
    {
        if (isBulletActive[idx] == true)
        {
            if (bulletplayery[idx] - 1 == enemy2Y + 2 && (bulletplayerx[idx] == enemy2X || bulletplayerx[idx] == enemy2X + 1 || bulletplayerx[idx] == enemy2X + 2))
            {
                addScore();
                addenemy2damage();
            }
        }
    }
}

void createbullet1()
{
    red();
    bulletenemy1x[enemy1bulletidx] = enemy1X + 1;
    bulletenemy1y[enemy1bulletidx] = enemy1Y + 3;
    makebulletenemy1active[enemy1bulletidx] = true;
    gotoxy(bulletenemy1x[enemy1bulletidx], bulletenemy1y[enemy1bulletidx]);
    cout << ".";
    enemy1bulletidx++;
    white();
}
void createbulletEnemyLeader()
{
    red();
    bulletenemyLeaderx[enemyLeaderbulletidx] = enemyLeaderX + 2;
    bulletenemyLeadery[enemyLeaderbulletidx] = enemyLeaderY + 4;
    makebulletenemyLeaderactive[enemyLeaderbulletidx] = true;
    gotoxy(bulletenemyLeaderx[enemyLeaderbulletidx], bulletenemyLeadery[enemyLeaderbulletidx]);
    cout << ".";
    enemyLeaderbulletidx++;
    bulletenemyLeaderx[enemyLeaderbulletidx] = enemyLeaderX + 5;
    bulletenemyLeadery[enemyLeaderbulletidx] = enemyLeaderY + 4;
    makebulletenemyLeaderactive[enemyLeaderbulletidx] = true;
    gotoxy(bulletenemyLeaderx[enemyLeaderbulletidx], bulletenemyLeadery[enemyLeaderbulletidx]);
    cout << ".";
    enemyLeaderbulletidx++;
    white();
}
void movebullet1()
{
    for (int idx = 0; idx < enemy1bulletidx; idx++)
    {

        if (makebulletenemy1active[idx] == true)
        {
            char next = getCharAtxy(bulletenemy1x[idx], bulletenemy1y[idx] + 1);
            if (next != ' ')
            {
                erasebullet(bulletenemy1x[idx], bulletenemy1y[idx]);
                Makebulletenemy1inactive(idx);
            }
            else
            {
                erasebullet(bulletenemy1x[idx], bulletenemy1y[idx]);
                bulletenemy1y[idx] = bulletenemy1y[idx] + 1;
                printbullet(bulletenemy1x[idx], bulletenemy1y[idx]);
            }
        }
    }
}
void Makebulletenemy1inactive(int x)
{
    makebulletenemy1active[x] = false;
}
void bulletCollisionwithplayer()
{
    for (int idx = 0; idx < enemy1bulletidx; idx++)
    {
        if (makebulletenemy1active[idx] == true)
        {
            if (bulletenemy1y[idx] + 1 == playerY && (bulletenemy1x[idx] == playerX || bulletenemy1x[idx] == playerX + 1 || bulletenemy1x[idx] == playerX + 2))
            {
                addplayerdamage();
            }
        }
    }
    for (int idx = 0; idx < enemy2bulletidx; idx++)
    {
        if (makebulletenemy2active[idx] == true)
        {
            if (bulletenemy2y[idx] + 2 == playerY && (bulletenemy2x[idx] == playerX || bulletenemy2x[idx] == playerX + 1 || bulletenemy2x[idx] == playerX + 2))
            {
                addplayerdamage();
            }
        }
    }
    for (int idx = 0; idx < enemyLeaderbulletidx; idx++)
    {
        if (makebulletenemyLeaderactive[idx] == true)
        {
            if (bulletenemyLeadery[idx] + 1 == playerY && (bulletenemyLeaderx[idx] == playerX ||
                                                           bulletenemyLeaderx[idx] == playerX + 1 || bulletenemyLeaderx[idx] == playerX + 2))
            {
                addplayerdamage();
            }
        }
    }
}
void addplayerdamage()
{
    playerdamage++;
}
void addenemy2damage()
{
    enemy2damage++;
}
void printplayerdamage()
{
    gotoxy(75, 6);
    cout << "Player Damage    " << playerdamage;
}
void printenemy1damage()
{
    gotoxy(75, 8);
    cout << "Damage Enemy 1   " << enemy1damage;
}
void printenemy2damage()
{
    gotoxy(75, 9);
    cout << "Damage Enemy 2   " << enemy2damage;
}
void printenemyLeaderdamage()
{
    gotoxy(75, 10);
    cout << "Damage Enemy Leader   " << enemyLeaderdamage;
}
void printlevel()
{
    gotoxy(75, 2);
    cout << "LEVEL " << level;
}
void printscore()
{
    gotoxy(75, 4);
    cout << "Score  " << score;
}
void printHigherScore()
{
    gotoxy(75, 5);
    cout << "Highest Score  " << higherSocre;
}
void createbullet2()
{
    red();
    char next = getCharAtxy(enemy2X, enemy2Y + 3);

    if (next == ' ')
    {
        bulletenemy2x[enemy2bulletidx] = enemy2X + 1;
        bulletenemy2y[enemy2bulletidx] = enemy2Y + 3;
        makebulletenemy2active[enemy2bulletidx] = true;
        gotoxy(bulletenemy2x[enemy2bulletidx], bulletenemy2y[enemy2bulletidx]);
        cout << ".";
        enemy2bulletidx++;
    }
}
void movebullet2()
{
    for (int idx = 0; idx < enemy2bulletidx; idx++)
    {

        if (makebulletenemy2active[idx] == true)
        {
            char next = getCharAtxy(bulletenemy2x[idx], bulletenemy2y[idx] + 1);
            if (next != ' ')
            {
                erasebullet(bulletenemy2x[idx], bulletenemy2y[idx]);
                Makebulletenemy2inactive(idx);
            }
            else
            {
                erasebullet(bulletenemy2x[idx], bulletenemy2y[idx]);
                bulletenemy2y[idx] = bulletenemy2y[idx] + 1;
                printbullet(bulletenemy2x[idx], bulletenemy2y[idx]);
            }
        }
    }
}
void movebulletLeader()
{
    for (int idx = 0; idx < enemyLeaderbulletidx; idx++)
    {

        if (makebulletenemyLeaderactive[idx] == true)
        {
            char next = getCharAtxy(bulletenemyLeaderx[idx], bulletenemyLeadery[idx] + 1);
            if (next != ' ')
            {
                erasebullet(bulletenemyLeaderx[idx], bulletenemyLeadery[idx]);
                MakebulletenemyLeaderinactive(idx);
            }
            else
            {
                erasebullet(bulletenemyLeaderx[idx], bulletenemyLeadery[idx]);
                bulletenemyLeadery[idx] = bulletenemyLeadery[idx] + 1;
                printbullet(bulletenemyLeaderx[idx], bulletenemyLeadery[idx]);
            }
        }
    }
}
void storeData()
{
    fstream file;
    file.open("continue.txt", ios::out);

    file << playerX << "," << playerY << "," << enemy1X << "," << enemy1Y << "," << enemy2X << "," << enemy2Y << "," << enemyLeaderX << "," << enemyLeaderY << "," << playerdamage << "," << enemy1damage << "," << enemy2damage << "," << enemyLeaderdamage << "," << level << "," << timer << "," << score;

    file.close();
}
void Makebulletenemy2inactive(int x)
{
    makebulletenemy2active[x] = false;
}
void MakebulletenemyLeaderinactive(int x)
{
    makebulletenemyLeaderactive[x] = false;
}
void printyouWin()
{
    system("cls");
    gotoxy(4, 4);
    green();
    cout << "##  ##    ## ##   ##  ###           ##   ##    ####   ###  ##           ## " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##      ## ##           ## " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##     # ## #           ## " << endl;
    cout << " ## ##   ##   ##  ##   ##           ## # ##     ##     ## ##            ## " << endl;
    cout << "  ##     ##   ##  ##   ##           # ### #     ##     ##  ##              " << endl;
    cout << "  ##     ##   ##  ##   ##            ## ##      ##     ##  ##           ## " << endl;
    cout << "  ##      ## ##    ## ##            ##   ##    ####   ###  ##           ## " << endl;
    getch();
    getch();
    getch();
    white();
    system("cls");
}
void youlosse()
{
    system("cls");
    red();
    string line;
    fstream file;
    file.open("YouLose.txt", ios::in);
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    Sleep(200);
    getch();
    getch();
    system("cls");
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
            player[row][col] = stoi(loaddata(line, col));
        }
        row++;
    }
    file.close();

    row = 0;

    file.open("maze.txt", ios::in);
    while (getline(file, line))
    {
        for (int idx = 0; idx < 75; idx++)
        {
            printMaze[row][idx] = loaddataChar(line, idx);
        }
        row++;
    }
    file.close();
    row = 0;
    file.open("mainenemy.txt", ios::in);
    while (getline(file, line))
    {
        for (int idx = 0; idx < 8; idx++)
        {
            enemyleader[row][idx] = loaddataChar(line, idx);
        }
        row++;
    }
    file.close();
}
void loadForContinue()
{
    string line;
    fstream file;
    file.open("continue.txt", ios::in);
    while (getline(file, line))
    {
        playerX = stoi(loaddata(line, 0));
        playerY = stoi(loaddata(line, 1));
        enemy1X = stoi(loaddata(line, 2));
        enemy1Y = stoi(loaddata(line, 3));
        enemy2X = stoi(loaddata(line, 4));
        enemy2Y = stoi(loaddata(line, 5));
        enemyLeaderX = stoi(loaddata(line, 6));
        enemyLeaderY = stoi(loaddata(line, 7));
        playerdamage = stoi(loaddata(line, 8));
        enemy1damage = stoi(loaddata(line, 9));
        enemy2damage = stoi(loaddata(line, 10));
        enemyLeaderdamage = stoi(loaddata(line, 11));
        level = stoi(loaddata(line, 12));
        timer = stoi(loaddata(line, 13));
        score = stoi(loaddata(line, 14));
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
char loaddataChar(string line, int num)
{
    int commacount = 0;
    string word;
    char asci;
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
    asci = stoi(word);
    return asci;
}
void newGame()
{
    playerX = 22;
    playerY = 19;
    timer = 10;
    leaderTime = 10;
    level = 1;
    enemy2X = 50;
    enemy2Y = 8;
    enemy1X = 2;
    enemy1Y = 3;
    enemyLeaderX = 5;
    enemyLeaderY = 5;
    score = 0;
    enemy1damage = 0;
    enemy2damage = 0;
    playerdamage = 0;
    enemyLeaderdamage = 0;
}
void lifePallet()
{
    lifePalletX = (rand() % 26) + 2;
    int pallet = rand() % 2;

    if (pallet == 0)
    {
        life = 3;
        palletType = "life";
    }
    if (pallet == 1)
    {
        life = 2;
        palletType = "socre";
    }
}
void printPallet()
{

    gotoxy(lifePalletX, lifePalletY);
    cout << life;
}
void eraseLifePallet()
{
    gotoxy(lifePalletX, lifePalletY);
    cout << " ";
}
void moveLifePallet()
{
    char check = 176;
    char next = getCharAtxy(lifePalletX, lifePalletY + 1);
    if (next == ' ')
    {
        eraseLifePallet();
        lifePalletY++;
        printPallet();
    }
    if (next == check)
    {
        eraseLifePallet();
        lifeLifePallet = false;
        lifePalletY = 2;
    }
}
void PalletCollisionwithplayer()
{
    if (palletType == "life")
    {
        if (lifePalletY + 1 == playerY && (lifePalletX == playerX || lifePalletX == playerX + 1 || lifePalletX == playerX + 2))
        {
            if (playerdamage >= 5)
            {
                playerdamage = playerdamage - 5;
            }
            else
            {
                playerdamage = 0;
            }
            eraseLifePallet();
            lifePalletY = 2;
            lifeLifePallet = false;
        }
    }
    if (palletType == "socre")
    {
        if (lifePalletY + 1 == playerY && (lifePalletX == playerX || lifePalletX == playerX + 1 || lifePalletX == playerX + 2))
        {
            score = score + 10;
            eraseLifePallet();
            lifePalletY = 2;
            lifeLifePallet = false;
        }
    }
}
void loadHigherSocre()
{
    string line;
    fstream file;
    file.open("higherScore.txt", ios::in);
    getline(file, line);
    higherSocre = stoi(loaddata(line, 0));
    file.close();
}
void storeHigherSocre()
{fstream file;
    file.open("higherScore.txt ", ios::out);
    file << higherSocre;
    file.close();
}
