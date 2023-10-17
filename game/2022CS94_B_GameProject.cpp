#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

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
// sataics
int score = 0;
int enemy1damage = 0;
int enemy2damage = 0;
int playerdamage = 0;
void addScore();
void addplayerdamage();
void addenemy1damage();
void printplayerdamage();
void printenemy1damage();
void addenemy2damage();
void printenemy2damage();
void printscore();
void youwin();
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
// axsis
int playerX = 22;
int playerY = 19;
// enemy
void enemy1();
int enemy1X = 2;
int enemy1Y = 1;
string direction = "right";
void enemy1move();
void printMaze();
void eraseenemy1();
int enemy1mov = 0;
// enemy 2
void enemy2();
int enemy2X = 50;
int enemy2Y = 14;
string directionForE2 = "left";
void enemy2move();
void random();
void eraseenemy2();
void bulletCollisionwithEnemy2();
// enemy1 bullter
int bulletenemy1x[200];
int bulletenemy1y[200];
void createbullet1();
int enemy1bulletidx = 0;
void movebullet1();
bool makebulletenemy1active[200];
void Makebulletenemy1inactive(int x);
void bulletCollisionwithplayer();
// enemy2 bullter
int bulletenemy2x[200];
int bulletenemy2y[200];
void createbullet2();
int enemy2bulletidx = 0;
void movebullet2();
bool makebulletenemy2active[200];
void Makebulletenemy2inactive(int x);

// timer
int enemy2timer = 0;
int rando = 0;
// level
int timer = 10;
void printlevel();
int level = 1;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    bool runing = true;
    wlcome2();
    mainmenu();
    int op;
    while (runing)
    {
        header();
        mainmenu();
        cin >> op;
        if (op == 1)
        {
            game();
        }
        if (op == 2)
        {
            option();
        }
        if (op == 3)
        {
            runing = false;
        }
    }
}

void wlcome2()
{
    green();
    system("cls");
    cout << "                                                       ..                                 " << endl;
    cout << "                                                   -+##@*                                 " << endl;
    cout << "                                               :=##+:  ##                                 " << endl;
    cout << "                                             =##=.     #*                                 " << endl;
    cout << "                                          .+%+.        @+                                 " << endl;
    cout << "                                        .+%=.- +*=.   .@:                                 " << endl;
    cout << "                                       =%+.+#-   -%:  +@                                  " << endl;
    cout << "                                     .##. =%      **  @+                                  " << endl;
    cout << "                                   :=@=   -%.    :%: =@.                                  " << endl;
    cout << "                               .=**@%:     -#+=+**: .@=                                   " << endl;
    cout << "                             :**- *%.    .=:  ..    %#                                    " << endl;
    cout << "                           .*#.  #%.   .+#+%       *%.                                    " << endl;
    cout << "                          :%-  :*%.   :%- **      *%.                                     " << endl;
    cout << "                         -%:.+#+=@=. =%. .@.    .#@#                                      " << endl;
    cout << "                        -%=#*:   .+%#%   #+    :%*=%                                      " << endl;
    cout << "                        @@+.       :@.  #*    =@= +#                                      " << endl;
    cout << "                        ..    ..   %= -%+##+-#%.  %=                                      " << endl;
    cout << "                             *#.  :@=#+.   :=#*  +%                                       " << endl;
    cout << "                            **     -:        %= =%.                                       " << endl;
    cout << "                           -%        =+     :@.*#                                         " << endl;
    cout << "                           #=        **     ###+                                          " << endl;
    cout << "                          -%        -%.    .%#.                                           " << endl;
    cout << "                         .@-     :%@#.                                            " << endl;
    cout << "                        .%#+%= .**.                                      " << endl;
    cout << "                        :+=%#=#+:                               " << endl;
    cout << "                          #*=:                                  " << endl;
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
    cout << "1. Start " << endl;
    cout << "2. Option " << endl;
    cout << "3. Exit " << endl;

    cout << "Enter one option " << endl;
}
void header()
{
    blue();
    int y = 196;
    char line = y;
    system("cls");
    cout << " ## ##   ### ##     ##      ## ##   ### ###           ### ##     ##     #### ##  #### ##  ####     ### ###  " << endl;
    cout << "##   ##   ##  ##     ##    ##   ##   ##  ##            ##  ##     ##    # ## ##  # ## ##   ##       ##  ##  " << endl;
    cout << "####      ##  ##   ## ##   ##        ##                ##  ##   ## ##     ##       ##      ##       ##      " << endl;
    cout << " #####    ##  ##   ##  ##  ##        ## ##             ## ##    ##  ##    ##       ##      ##       ## ##   " << endl;
    cout << "    ###   ## ##    ## ###  ##        ##                ##  ##   ## ###    ##       ##      ##       ##      " << endl;
    cout << "##   ##   ##       ##  ##  ##   ##   ##  ##            ##  ##   ##  ##    ##       ##      ##  ##   ##  ##  " << endl;
    cout << " ## ##   ####     ###  ##   ## ##   ### ###           ### ##   ###  ##   ####     ####    ### ###  ### ###  " << endl;
    cout << endl;
    cout << "menu ." << endl;
    for (int idx = 0; idx < 20; idx++)
    {
        cout << line;
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
    printMaze();
    printplayer();
    enemy1damage = 0;
    enemy2damage = 0;
    playerdamage = 0;

    while (running)
    {
        movebullet();

        bulletCollisionwithEnemy();
        bulletCollisionwithEnemy2();
        bulletCollisionwithplayer();

        printplayerdamage();

        movebullet1();
        movebullet2();
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
        if (rando == 60)
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
            if (timer >= 2)
            {
                enemy1damage = 0;
                enemy2damage = 0;
                youwin();
                level++;
                timer = timer - 2;
                printMaze();
            }
            else
            {
                youwin();
                score = 0;
                running = false;
            }
        }
        if (playerdamage >= 40)
        {

            youlosse();
            score = 0;
            running = false;
        }
        printenemy1damage();
        printenemy2damage();
        printlevel();
        enemy1mov++;

        enemy2timer++;
        rando++;
        printscore();

        Sleep(100);
    }
}
void printMaze()
{
    blue();
    system("cls");
    cout << "############################################################" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "#                                                          #" << endl;
    cout << "############################################################" << endl;
    white();
}
void enemy1()
{
    red();
    gotoxy(enemy1X, enemy1Y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << third[idx];
    }
    gotoxy(enemy1X, enemy1Y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << second[idx];
    }
    gotoxy(enemy1X, enemy1Y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << first[idx];
    }
    white();
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
    gotoxy(playerX, playerY);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(playerX, playerY + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(playerX, playerY + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
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
    gotoxy(playerX, playerY);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << first[idx];
    }
    gotoxy(playerX, playerY + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << second[idx];
    }
    gotoxy(playerX, playerY + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << third[idx];
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
            enemy1();
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
            enemy1();
        }
        else
        {
            direction = "right";
        }
    }
}
void eraseenemy1()
{
    gotoxy(enemy1X, enemy1Y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
}
void createbullet()
{
    green();
    bulletplayerx[playerbulletidx] = playerX + 1;
    bulletplayery[playerbulletidx] = playerY - 1;
    isBulletActive[playerbulletidx] = true;
    gotoxy(bulletplayerx[playerbulletidx],
           bulletplayery[playerbulletidx]);
    cout << ".";
    playerbulletidx++;
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
void addScore()
{
    score++;
}
void addenemy1damage()
{
    enemy1damage++;
}
void enemy2()
{
    red();
    gotoxy(enemy2X, enemy2Y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << third[idx];
    }
    gotoxy(enemy2X, enemy2Y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << second[idx];
    }
    gotoxy(enemy2X, enemy2Y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << first[idx];
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
            enemy2();
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
            enemy2();
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
            enemy2();
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
            enemy2();
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
    gotoxy(enemy2X, enemy2Y);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 1);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 2);
    for (int idx = 0; idx < 3; idx++)
    {
        cout << " ";
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
    gotoxy(65, 6);
    cout << "Player Damage    " << playerdamage;
}
void printenemy1damage()
{
    gotoxy(65, 8);
    cout << "Damage Enemy 1   " << enemy1damage;
}
void printenemy2damage()
{
    gotoxy(65, 9);
    cout << "Damage Enemy 2   " << enemy2damage;
}
void printlevel()
{
    gotoxy(63, 2);
    cout << "LEVEL " << level;
}
void printscore()
{
    gotoxy(63, 4);
    cout << "Score  " << score;
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
void Makebulletenemy2inactive(int x)
{
    makebulletenemy2active[x] = false;
}
void youwin()
{
    system("cls");
    gotoxy(4, 4);
    cout << "##  ##    ## ##   ##  ###           ##   ##    ####   ###  ##           ## " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##      ## ##           ## " << endl;
    cout << "##  ##   ##   ##  ##   ##           ##   ##     ##     # ## #           ## " << endl;
    cout << " ## ##   ##   ##  ##   ##           ## # ##     ##     ## ##            ## " << endl;
    cout << "  ##     ##   ##  ##   ##           # ### #     ##     ##  ##              " << endl;
    cout << "  ##     ##   ##  ##   ##            ## ##      ##     ##  ##           ## " << endl;
    cout << "  ##      ## ##    ## ##            ##   ##    ####   ###  ##           ## " << endl;
    Sleep(200);
    getch();
    system("cls");
}
void youlosse()
{
    system("cls");
    cout << "##  ##    ## ##   ##  ###           ####      ## ##    ## ##    ## ##   ### ###  " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ##   ##  ##   ##   ##  ##  " << endl;
    cout << "##  ##   ##   ##  ##   ##            ##      ##   ##  ##   ##  ####      ##      " << endl;
    cout << " ## ##   ##   ##  ##   ##            ##      ##   ##  ##   ##   #####    ## ##   " << endl;
    cout << "  ##     ##   ##  ##   ##            ##      ##   ##  ##   ##      ###   ##      " << endl;
    cout << "  ##     ##   ##  ##   ##            ##  ##  ##   ##  ##   ##  ##   ##   ##  ##  " << endl;
    cout << "  ##      ## ##    ## ##            ### ###   ## ##    ## ##    ## ##   ### ###  " << endl;
    Sleep(200);
    getch();
    system("cls");
}