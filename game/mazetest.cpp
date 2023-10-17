#include <iostream>
#include <fstream>
using namespace std;
// void printmaze;
char printMaze[30][75];
char enemyleader[4][8];
void printenemyLeader();
int col = 0;
void load();
char dataload(string line, int num);
void print2D();
main()
{
    load();
     printenemyLeader();
    // print2D();
}
void load()
{
    string line;
    fstream file;
    int row = 0;
    file.open("maze.txt", ios::in);
    while (getline(file, line))
    {
        for (int idx = 0; idx < 75; idx++)
        {
            printMaze[row][idx] = dataload(line, idx);
        }
        row++;
    }
    file.open("mainenemy.txt", ios::in);
    while (getline(file, line))
    {
        for (int idx = 0; idx < 8; idx++)
        {
            enemyleader[row][idx] = dataload(line, idx);
        }
        row++;
    }
    file.close();
}
char dataload(string line, int num)
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

void print2D()
{

    for (int idx = 0; idx < 30; idx++)
    {

        for (int idx2 = 0; idx2 < 75; idx2++)
        {
            cout << printMaze[idx][idx2];
        }
        cout << endl;
    }
}
void printenemyLeader()
{
 
    
    for (int row = 0; row < 4; row++)
    {
       
        for (int col = 0; col < 8; col++)
        {
            cout << enemyleader[row][col];
        }
     cout<<endl;
    }
}