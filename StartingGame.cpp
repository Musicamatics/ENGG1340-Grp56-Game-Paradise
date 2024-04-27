#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <window.h>
#include <cinio.h>

using namespace std;
char window[25][75];

void setwindow()
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 75; j++)
        {
            if (i == 0 || i == 24 || j == 0 || j == 74)
            {
                window[i][j] = '#';
            }
            else
            {
                window[i][j] = ' ';
            }
        }
    }
}


void print(const string& str)
{
    cout << str << endl;
}

int main()
{
    bool input_check = true;
    string user;
    print("Welcome to GameParadise!");
    print("Please enter your name:");
    while (input_check)
    {
        getline(cin, user);
        if (!user.empty())
        {
            input_check = false;
        }
    }
    cout << "Welcome, " << user << " !" << endl;

    bool choose = true;
    string chosen;
    while (choose)
    {
        print("Please choose a game to play:");
        print("1) Snake Game    (Enter 1)");
        print("2) Wordle        (Enter 2)");
        getline(cin, chosen);
        if (chosen != "1" && chosen != "2")
        {
            print("Invalid Input!!");
            print("Please try again!");
        }
        else
        {
            choose = false;
        }
    }

    if (chosen == "1")
    {
        print("Loading Snake Game...");
        system("g++ -Wall -Wextra -pedantic -std=c++11 -o snake main.cpp snake.cpp userinput.cpp -lncurses");
        system("./snake");
    }
    else if (chosen == "2")
    {
        print("Loading Wordle...");
        system("g++ -Wall -Wextra -pedantic -std=c++11 -o wordle wordle_main.cpp wordle.cpp");
        system("./wordle");
    }

    return 0;
}
