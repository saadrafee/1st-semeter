#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
// all data (global)
// buses details
string cities[15] = {"islamabad", "multan    ", "dera ghazi khan", "sargodha", "fasialabad", "karachi    "};
int citiesIdx = 6;
float rent[15] = {2450, 1700, 1900, 1020, 950, 5700};
// color

// passanger related information
string passangerName[50];
string passangerDestination[50];
string id[50];
int idxForpassangers = 0;
string destination[50];
int destinationIdx = 0;
// ticket
int ticketSold = 0;
int eachCitySoldticket[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float incomeFromtickets = 0;
// expanse
string expanse[10];
int costprice[10];
int expanseIdx = 0;
int totalExpance = 0;
// sign
string username[50] = {"saad rafi", "usman ali", "ahmed khan"};
string post[50] = {"admin", "employ", "Guard"};
string password[50] = {"1234", "1234", "Nill "};
string accesspassword = "saad1234";
int signidx = 3;
// function
void header();
void option();
void employ();
void admin();
void passangermenu();
void booking();
void allPassangerDetails();
void cancelTicket();
void expenses();
void seeYourdetails();
void ticketSales();
void changeprice();
void seeExpanses();
void netProfit();
void signUp();
void signIn();
void seeEmployeDetail();
void AddorRemove();
void newDestination();
void changeaccesspassword();
main()
{
    system("cls");
    bool runing = true;
    int op = 0;

    while (runing)
    {
        header();
        option();
        cin >> op;

        if (op == 1)
        {
            signUp();
        }
        if (op == 2)
        {
            signIn();
        }
        if (op == 3)
        {
            passangermenu();
        }
        if (op == 4)
        {
            runing = false;
        }
    }
}
void option()
{
    cout << "press 1 for sign up " << endl;
    cout << "press 2 for sign in  " << endl;
    cout << "press 3 for passanger  " << endl;
    cout << "press 4 exsit  " << endl;
}
void admin()
{

    bool runing = true;
    int op = 0;
    while (runing)
    {
        header();
        cout << "press 1 for see ticket sales  " << endl;
        cout << "press 2 for passanger detials " << endl;
        cout << "press 3 for change price   " << endl;
        cout << "press 4 for Add or remove (employ/admin)" << endl;
        cout << "press 5 for see expences " << endl;
        cout << "press 6 for net profit " << endl;
        cout << "press 7 for see employe detail" << endl;
        cout << "press 8 for add new destination " << endl;
        cout << "press 9 for change the access password" << endl;
        cout << "press 0 for exit" << endl;
        cin >> op;
        if (op == 1)
        {
            ticketSales();
        }
        if (op == 2)
        {
            allPassangerDetails();
        }
        if (op == 3)
        {
            changeprice();
        }
        if (op == 4)
        {
            AddorRemove();
        }
        if (op == 5)
        {
            seeExpanses();
        }
        if (op == 6)
        {
            netProfit();
        }
        if (op == 7)
        {
            seeEmployeDetail();
        }
        if (op == 8)
        {
            newDestination();
        }
        if (op == 9)
        {
            changeaccesspassword();
        }
        if (op == 0)
        {
            runing = false;
        }
    }
}
void employ()
{

    bool runing = true;
    int op = 0;
    while (runing)
    {
        header();
        cout << "press 1 Book ticket " << endl;
        cout << "press 2 cancel ticket " << endl;
        cout << "press 3 see passengers  " << endl;
        cout << "press 4 for add expenses " << endl;
        cout << "press 5 for exit " << endl;
        cin >> op;
        if (op == 1)
        {
            booking();
        }
        if (op == 2)
        {
            cancelTicket();
        }
        if (op == 3)
        {
            allPassangerDetails();
        }
        if (op == 4)
        {
            expenses();
        }
        if (op == 5)
        {
            runing = false;
        }
    }
}
void header()
{
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "            Bus Reservation system " << endl;
    cout << "*****************************************************" << endl;
}
void passangermenu()
{

    bool runing = true;
    int op = 0;
    while (runing)
    {
        header();
        cout << "press 1 for book the ticket  " << endl;
        cout << "press 2 for cancel the ticket " << endl;
        cout << "press 3 for see your ticket details  " << endl;
        cout << "press 4 for exit" << endl;
        cin >> op;
        if (op == 1)
        {
            booking();
        }
        if (op == 2)
        {
            cancelTicket();
        }
        if (op == 3)
        {
            seeYourdetails();
        }
        if (op == 4)
        {
            runing = false;
        }
    }
}
void booking()
{
    header();
    int city;
    int confirm;

    cout << "Select destination " << endl;
    for (int idx = 0; idx < citiesIdx; idx++)
    {
        cout << "Press " << idx + 1 << " for " << cities[idx] << endl;
    }
    cin >> city;
    header();
    cout << "Ticket price is " << rent[city - 1] << endl;
    cout << "press 1 for book the ticket " << endl;
    cout << "press 0 for cancel the process " << endl;
    cin >> confirm;

    cout << endl;
    if (confirm == 1)
    {
        header();
        cout << "Enter Passanger name ";
        getline(cin, passangerName[idxForpassangers]);
        getline(cin, passangerName[idxForpassangers]);

        cout << "Enter ID No ";
        cin >> id[idxForpassangers];
        cout << "Ticket is booked " << endl;
        cout << "Press any key to continue....." << endl;
        passangerDestination[idxForpassangers] = cities[city - 1];
        idxForpassangers++;
        ticketSold++;
        eachCitySoldticket[(city - 1)] = eachCitySoldticket[(city - 1)] + 1;
        cout << "press any key to continue.....";
        getch();
    }
    if (confirm == 0)
    {
        cout << "press any key to continue.....";
        getch();
    }
}
void allPassangerDetails()

{
    cout << "name"
         << "\t"
         << "\t"
         << "\t"
         << "destination"
         << "\t"
         << "\t"
         << "\t"
         << "IDs" << endl;
    for (int idx = 0; idx < idxForpassangers; idx++)
    {
        if (passangerName[idx] == "``")
        {
            continue;
        }
        cout << passangerName[idx] << "\t"
             << "\t"
             << passangerDestination[idx] << "\t"
             << "\t" << id[idx] << endl;
    }
    cout << "Press any key to continue....." << endl;
    getch();
}
void cancelTicket()
{
    header();
    string name;
    string idcancel;
    bool check = false;
    cout << "Enter passanger name ";
    getline(cin, name);
    getline(cin, name);
    cout << "Enter id number of passanger ";
    cin >> idcancel;
    cout << "press any key to continue.....";
    getch();
    header();
    int i = 0;
    for (int idx = 0; idx < idxForpassangers; idx++)
    {

        if (name == passangerName[idx] && idcancel == id[idx])
        {
            check = true;
            i = idx;
            break;
        }
    }
    for (int idx = 0; idx < citiesIdx; idx++)
    {
        if (destination[i] == cities[idx])
        {
            eachCitySoldticket[idx] = eachCitySoldticket[idx] - 1;
        }
    }
    for (int idx = i; idx < idxForpassangers - 1; idx++)
    {

        passangerName[idx] = passangerName[idx + 1];

        passangerDestination[idx] = passangerDestination[idx + 1];
        id[idx] = id[idx + 1];
    }
    idxForpassangers--;
    if (check == true)
    {
        cout << "booking cancel successfully " << endl;
    }
    if (check == false)
    {
        cout << "Wrong input " << endl;
    }
    cout << "Press any key to continue....." << endl;
    getch();
}
void seeYourdetails()
{
    header();
    string name;
    string idcheck;
    bool check = false;
    cout << "Enter your name ";
    getline(cin, name);
    getline(cin, name);
    cout << "Enter your id number ";
    cin >> idcheck;
    getch();
    for (int idx = 0; idx < idxForpassangers; idx++)
    {
        if (passangerName[idx] == name && idcheck == id[idx])
        {
            check = true;
        }
    }
    if (check = true)
    {
        header();
        cout << "Name"
             << "\t\t"
             << "id"
             << "\t"
             << "Destination" << endl;
        for (int idx = 0; idx < idxForpassangers; idx++)
        {
            if (passangerName[idx] == name && idcheck == id[idx])
            {
                cout << passangerName[idx] << "\t" << id[idx] << '\t' << passangerDestination[idx] << endl;
            }
        }
        cout << "press any key to continue....";
        getch();
    }
    else
    {
        cout << "there is no booked ticked for you " << endl;
        cout << "press any key to continue";
        getch();
    }
}
void ticketSales()

{
    header();
    cout << "\t"
         << "   Sold ticket "
         << "\t"
         << "\t"
         << "sales" << endl;
    for (int idx = 0; idx < citiesIdx; idx++)
    {
        cout << cities[idx] << "\t"
             << "\t" << eachCitySoldticket[idx] << "\t"
             << "\t" << eachCitySoldticket[idx] * rent[idx] << endl;
    }
    getch();
}
void changeprice()
{
    header();
    int op;
    int change;
    float per;
    cout << "press 1 for change all buses price automatically  " << endl;
    cout << "press 2 for change  ticket pricec one by one  " << endl;
    cin >> op;
    cout << "press any key to continue" << endl;
    getch();

    if (op == 1)
    {
        header();
        cout << "press 1 for increase in price" << endl;
        cout << "press 2 for decrease in price" << endl;
        cin >> change;
        if (change == 1)
        {
            header();
            cout << "press 1 for increase by percentage " << endl;
            cout << "press 2 for increase by rupee" << endl;
            cin >> change;
            getch();
            header();
            if (change == 1)
            {
                cout << "Enter persentage you want to increase ";
                cin >> per;
                per = per / 100;
                for (int idx = 0; idx < citiesIdx; idx++)
                {
                    cout << "old price for " << cities[idx] << " is " << rent[idx] << " and new is " << rent[idx] + rent[idx] * per << endl
                         << endl;
                    rent[idx] = rent[idx] + rent[idx] * per;
                }
            }
            if (change == 2)
            {
                cout << "Enter rupee you want to increase ";
                cin >> per;
                for (int idx = 0; idx < citiesIdx; idx++)
                {
                    cout << "old price for " << cities[idx] << " is " << rent[idx] << " and new is " << rent[idx] + per << endl
                         << endl;
                    rent[idx] = rent[idx] + per;
                }
            }
        }
        if (change == 2)
        {
            cout << "press 1 for decrease by percentage " << endl;
            cout << "press 2 for decrease by rupee" << endl;
            cin >> change;
            if (change == 1)
            {
                cout << "Enter persentage you want to decrease ";
                cin >> per;
                per = per / 100;
                for (int idx = 0; idx < citiesIdx; idx++)
                {
                    cout << "old price for " << cities[idx] << " is " << rent[idx] << " and new is " << rent[idx] - rent[idx] * per << endl
                         << endl;
                    rent[idx] = rent[idx] - rent[idx] * per;
                }
            }
            if (change == 2)
            {
                cout << "Enter rupee you want to decrease ";
                cin >> per;
                for (int idx = 0; idx < citiesIdx; idx++)
                {
                    cout << "old price for " << cities[idx] << " is " << rent[idx] << " and new is " << rent[idx] - per << endl
                         << endl;
                    rent[idx] = rent[idx] - per;
                }
            }
        }
    }
    if (op == 2)
    {
        for (int idx = 0; idx < citiesIdx; idx++)
        {
            cout << "current price for " << cities[idx] << " is " << rent[idx]
                 << " set new price ";
            cin >> per;
            rent[idx] = per;
        }
    }
    cout << "Press any key to continue ";
    getch();
}
void expenses()
{
    header();
    cout << "Enter Title of expance(like fuel) ";
    getline(cin, expanse[expanseIdx]);
    getline(cin, expanse[expanseIdx]);
    cout << "Enter price ";
    cin >> costprice[expanseIdx];
    expanseIdx++;
    cout << "press any key to continue" << endl;
    getch();
}
void seeExpanses()
{
    header();
    for (int idx = 0; idx < expanseIdx; idx++)
    {
        cout << "cost of " << expanse[idx] << " is " << costprice[idx] << endl;
        totalExpance = totalExpance + costprice[idx];
    }
    cout << "Total Expance is " << totalExpance << endl
         << endl;
    cout << "press any key to continue....." << endl;

    getch();
}
void netProfit()
{
    header();
    for (int idx = 0; idx < citiesIdx; idx++)
    {
        incomeFromtickets = (eachCitySoldticket[idx] * rent[idx]) + incomeFromtickets;
    }
    cout << "Income from ticket sold" << incomeFromtickets << endl;
    cout << "Expances is " << totalExpance << endl;
    cout << "net profit is " << incomeFromtickets - totalExpance << endl
         << endl;
    cout << "press any key to continue....." << endl;

    getch();
}
void signUp()
{
    header();
    string code;
    cout << "Enter access password ";
    getline(cin, code);
    getline(cin, code);
    if (code == accesspassword)
    {
        header();
        cout << "Enter new user name ";
        getline(cin, username[signidx]);
        cout << "set user password ";
        cin >> password[signidx];
        cout << "Enter destination";
        cin >> post[signidx];
        signidx++;
    }
    else
    {
        cout << "wrong password " << endl;
    }
    cout << "press any key to continue ";
    getch();
}
void signIn()
{
    header();
    string name;
    string userpassword;
    cout << "Enter user name ";
    getline(cin, name);
    getline(cin, name);
    cout << "Enter password ";
    getline(cin, userpassword);
    bool check = false;
    for (int idx = 0; idx < signidx; idx++)
    {
        if (name == username[idx] && userpassword == password[idx])
        {
            if (post[idx] == "admin")
            {
                admin();
            }
            if (post[idx] == "employ")
            {
                employ();
            }
            check = true;
            break;
        }
    }
    if (check == false)
    {
        cout << "worng entry " << endl;
    }
    cout << "press any key to continue ";
    getch();
}
void seeEmployeDetail()
{
    header();
    cout << "name   "
         << "              Post   "
         << "       passwords" << endl;
    for (int idx = 0; idx < signidx; idx++)
    {
        if (username[idx] == "``")
        {
            continue;
        }
        cout << username[idx] << "            " << post[idx] << "           " << password[idx] << endl;
    }
    cout << "Press any key to continue ";
    getch();
}
void AddorRemove()
{
    header();
    int op;
    string name;
    string pos;
    int loction;
    cout << "press 1 for add " << endl;
    cout << "press 2 for remove " << endl;
    cin >> op;
    if (op == 1)
    {
        signUp();
    }
    if (op == 2)
    {
        header();
        bool check = false;
        int loction;
        cout << "Enter employ/admin name you want to remove from ";
        getline(cin, name);
        getline(cin, name);
        cout << "Enter post ";
        cin >> pos;
        for (int idx = 0; idx < signidx; idx++)
        {
            if (name == username[idx] && pos == post[idx])
            {
                loction = idx;
                check = true;
                break;
            }
        }
        for (int idx = loction; idx < signidx - 1; idx++)
        {
            username[idx] = username[idx + 1];
            post[idx] = post[idx + 1];
            password[idx] = password[idx + 1];
        }
        signidx--;
        if (check == false)
        {
            cout << "such employ does not exsist " << endl;
        }
        else
        {
            cout << "Remove successfully" << endl;
        }
        cout << "press any key to continue ";
        getch();
    }
}
void newDestination()
{
    header();
    cout << "Enter new location";
    cin >> cities[citiesIdx];
    cout << "Enter price ";
    cin >> rent[citiesIdx];
    citiesIdx++;
    cout << endl
         << "press any key to continue....." << endl;
    getch();
}
void changeaccesspassword()
{
    header();
    string name, name2;
    bool run = true;
    cout << "Enter access password ";
    getline(cin, name);
    if (name == accesspassword)
    {
        header();
        while (run)
        {
            cout << "Enter new password ";
            getline(cin, name);
            cout << "confirm new password";
            getline(cin, name2);
            if (name == name2)
            {
                accesspassword = name;
                cout << "Access Password change successfully" << endl;
                run = false;
            }
            else
            {
                cout << "reconfirm the password";
                cout << "press any key to continue .....";
                getch();
            }
        }
    }
    else
    {
        header();
        cout << "wrong password ";
        cout << "press any key to continue .....";
        getch();
    }
}